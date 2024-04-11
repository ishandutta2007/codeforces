#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a;
  scanf("%d", &a);
  int b[5000];
  for(int i = 0; i < 5000; i++){
    b[i] = 0;
  }
  int c;
  for(int i = 0; i < a; i++){
    scanf("%d", &c);
    b[c-1] = 1;
  }
  int num = 0;
  for(int i = 0; i < a; i++){
    num += b[i]; 
  }
  printf("%d\n", a-num);
}