#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
main(int argc, char **argv) {
  int a;
  scanf("%d", &a);
  a--;
  
  int i = 0;
  int pow2 = 1;
  while(1){
    if(a < 5*(pow2-1)){
      break;
    } 
    pow2 *= 2;
    i++;
  }
  int c = a - 5*(pow2/2 - 1);
  int d = int(c*2/pow2);

  if(d == 0){
    printf("Sheldon\n");
  }
  if(d == 1){
    printf("Leonard\n");
  }  
  if(d == 2){
    printf("Penny\n");
  } 
  if(d == 3){
    printf("Rajesh\n");
  } 
  if(d == 4){
    printf("Howard\n");
  }
  exit(0);
}