#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
main(int argc, char **argv) {
  int a;
  scanf("%d", &a);
  int min = 999; int minpos;
  int max = -1; int maxpos;
  int b;
  for(int i = 0; i < a; i++){
    scanf("%d", &b);
    if(b <= min){
      min = b;
      minpos = i;
    }
    if(b > max){
      max = b;
      maxpos = i;
    }
  }
  int pwn = 0;
  if(minpos < maxpos){
    pwn = -1;
  }
  pwn += maxpos;
  pwn += (a-minpos-1);
  printf("%d\n", pwn);
  exit(0);
}