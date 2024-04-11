#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;
int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}

main(int argc, char **argv) {
  char a[3];
  char b[3];
  scanf("%s %s", a, b);
  int c, d;
  c = a[0]-b[0];
  d = a[1]-b[1];
  printf("%d\n", Max(Abs(c), Abs(d)));
  for(int i = 0; i < Max(Abs(c), Abs(d)); i++){
    if(c > 0){
      if(i < Abs(c)){
	printf("L");
      }
    } else if (c < 0){
      if(i < Abs(c)){
	printf("R");
      }
    }
    if(d > 0){
      if(i < Abs(d)){
	printf("D");
      }
    } else if (d < 0){
      if(i < Abs(d)){
	printf("U");
      }
    }
    printf("\n");
  }
}