//
//  main.c
//  CS 261 - Data Structures
//  Worksheet_0
//
//  Created by John Rudolph on 10/7/19.
//  Copyright © 2019 John Rudolph. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

# define MAX_SIZE 100


# define TYPE int
# define EQ(a, b) (a == b)

struct arrayBagStack {
    TYPE data [MAX_SIZE];
    int count;
};

/* Interface for Bag */
void initBag (struct arrayBagStack * b);
void addBag (struct arrayBagStack * b, TYPE v);
int containsBag (struct arrayBagStack * b, TYPE v);
void removeBag (struct arrayBagStack * b, TYPE v);
int sizeBag (struct arrayBagStack * b);

/* Interface for Stack */
void pushStack (struct arrayBagStack * b, TYPE v);
TYPE topStack (struct arrayBagStack * b);
void popStack (struct arrayBagStack * b);
int isEmptyStack (struct arrayBagStack * b);


/*Dynamic array stuct*/
struct DynArr {
    TYPE * data;
    int size;
    int capacity;
};
/* initialize a dynamic array structure with given capacity */
void dynArrayInit (struct DynArr * da, int initialCapacity);

/* internal method to double the capacity of a dynamic array */
void _dynArraySetCapacity (struct DynArr * da);

/* release dynamically allocated memory for the dynamic array */
void dynArrayFree (struct DynArr * da);

/* return number of elements stored in dynamic array */
int dynArraysize (struct DynArr * da);

/* add a value to the end of a dynamically array */
void dynArrayAdd (struct DynArr * da, TYPE e);

/* remove the value stored at position in the dynamic array */
void dynArrayRemoveAt (struct DynArr * da, int position);

/* retrieve element at a given position */
TYPE dynArrayGet (struct DynArr * da, int position);

/* store element at a given position */
void dynArrayPut (struct DynArr * da, int position, TYPE value);


int main(int argc, const char * argv[]) {


    printf("Hello, World!\n");
    return 0;
}


//Implement bag, initialize count to 0
void initBag(struct arrayBagStack *b)
{
    b->count = 0;
}

//adds a value to end of array (bag)
void addBag (struct arrayBagStack *b, TYPE v)
{
    b->data[b->count+1] = v;
}

//returns value at location v
int containsBag (struct arrayBagStack *b, TYPE v)
{
    return b->data[v];
}

//sets value at location v to 0
void removeBag (struct arrayBagStack * b, TYPE v)
{
    b->data[v] = 0;
}

//returns the size of the data array
int sizeBag (struct arrayBagStack * b)
{
    return sizeof(b->data);
}

//adds value of v to top of stack
void pushStack (struct arrayBagStack * b, TYPE v)
{
    if(b->count < MAX_SIZE) {
        b->data[b->count] = v;
        b->count++;
    }
    else
        return;
}

//returns value at top of stack
TYPE topStack (struct arrayBagStack * b)
{
    return b->data[b->count];
}

//sets value of top of stack to 0
void popStack (struct arrayBagStack * b)
{
    if(b->count > 0) {
        b->data[b->count] = 0;
        b->count--;
    }
    else
        printf("The stack is already empty.\n");
}


int isEmptyStack (struct arrayBagStack * b)
{
    if(b->count < 0) {
        return 1;   // return true if empty
    }
    else
        return 0;   // return false if not empty
}


/* initialize a dynamic array structure with given capacity */
void dynArrayInit (struct DynArr * da, int initialCapacity)
{
    da->data = malloc(initialCapacity * sizeof(TYPE));
    assert(da->data!=0);
    da->size = 0;
    da->capacity = initialCapacity;
}

/* internal method to double the capacity of a dynamic array */
void _dynArraySetCapacity (struct DynArr * da)
{
    //create new array
    struct DynArr * temp = 0;
    dynArrayInit(temp, da->capacity * 2);
    
    //copy values from old array into new one
    for(int i = 0; i < da->size; i++ ){
        da->data[i] = temp->data[i];
    }
    
    //free memory from old array
    dynArrayFree(da);
    
    //change pointer to refernce new array
    da = temp;
    
    //free memory from temp
    dynArrayFree(temp);
}


/* release dynamically allocated memory for the dynamic array */
void dynArrayFree (struct DynArr * da)
{
    if( da->data !=0 ){
        free( da->data );
        da->data = 0;
    }
    da->size = 0;
    da->capacity = 0;
}


/* return number of elements stored in dynamic array */
int dynArraysize (struct DynArr * da)
{
    return da->size;
}


/* add a value to the end of a dynamically array */
void dynArrayAdd (struct DynArr * da, TYPE e)
{
    if(da->size == da->capacity) {
        _dynArraySetCapacity(da);
        da->data[da->size+1] = e;
    }
    else {
        da->data[da->size+1] = e;
    }
}

/* remove the value stored at position in the dynamic array */
void dynArrayRemoveAt (struct DynArr * da, int position)
{
    assert(da->data[position] != 0);
    da->data[position] = 0;
    
    //loop to move each element in array back by one position
    for (int i = position; i < da->size; i++){
        da->data[i] = da->data[i+1];
    }
}


/* retrieve element at a given position */
TYPE dynArrayGet (struct DynArr * da, int position)
{
    //assert(da->data[position] != 0);
    return da->data[position];
}


/* store element at a given position */
void dynArrayPut (struct DynArr * da, int position, TYPE value)
{
    if(da->size + 1 == da->capacity){
        _dynArraySetCapacity(da);
    }
    //loop to move each element in array forward by one position
    for (int i = da->size; i > position; i--){
        da->data[i+1] = da->data[i];
    }
    
    da->data[position] = value;
}
