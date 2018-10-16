/*
   This program will ask to the user n number of integer values
   and return how many of that numbers are duplicate.
   
   Author: Victor Manuel Gastelum Huitzil
   e-mail: A01411985@itesm.mx
   Date: 15/10/18 
*/

#include <stdio.h>
#include <stdlib.h>

// Compare numbers
int compare (const void*a, const void*b) {
    return ( *(int*)a-*(int*)b);
}

int main() {
    int k;
    int n;
    int x;
    int dup=0;
    int rep;

    // Here I ask how many numbers is the user going to enter
    printf("How many numbers are you going to enter?\n");
    scanf("%d", &n);

    int arr[n];

    // Here the loop continues depending on the times that user indicates with the numbers
    // that ask him before
    for (int i=0; i<n ; i++) {
        printf("Give me number %d:\n", i + 1);
        scanf("%d", &k);
        arr[i] =k;
    }

    // We use the function that creates before to compare the numbers
    qsort(arr,n, sizeof(int), compare);

    // This loop will continues depending on how many duplicate numbers were found
    for (int i=0; i<n; i+=x+1) {
        x=0;

        // Loop to found the duplicates
        do {
            if (arr[i] == arr[i+x+1]) {
                x++; 
                rep=1;
            } else {
                rep=0;
            }
        } while (rep==1);

        if (x>0) {
            dup++;
        }
    }

    printf("The amount of duplicated numbers is %d.", dup);

    return 0;
}
