#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int is2block(int ycoord, int blocksize){
  if(int(ycoord/blocksize) % 2 == 1){
    return 0;
  }
  return 1;
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}

main(int argc, char **argv) {
  int a, x, y;
  scanf("%d%d%d", &a, &x, &y);
  if(y <= 0 || (y % a == 0)){
    printf("-1\n");
    exit(0);
  }
  if(y < a){
    if(2*Abs(x)<a){
      printf("1\n");
      exit(0);
    } else {
      printf("-1\n");
      exit(0);
    }
  }
  if(is2block(y, a)){
    if(x == 0 || Abs(x) >= a){
      printf("-1\n");
      exit(0);
    }
    int height = int(y/a);
    int leftblock = int(height*3/2);
    if(x > 0){
      printf("%d\n", leftblock+1);
      exit(0);
    } else {
      printf("%d\n", leftblock);
      exit(0);
    }
  } else {
    int height = int(y/a);
    if(2*Abs(x) < a){
      int block = (3*height+1)/2;
      printf("%d\n", block);
      exit(0);
    } else {
      printf("-1\n");
      exit(0);
    }
  }
  
  exit(0);
}