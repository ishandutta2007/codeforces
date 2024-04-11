#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int exp(int x){
  int k = 1;
  for(int i = 0; i < x; i++){
    k *= 2;
  }
  return k;
}
main(int argc, char **argv) {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  if(b == 0){
    if(a+1 == n){
      if(n == 1){
	printf("1\n");
	exit(0);
      }
      printf("-1\n");
      exit(0);
    } else {
      printf("1 1");
      for(int i = 2; i <= a+1; i++){
	printf(" %d", i);
      }
      for(int i = 0; i < n-a-2; i++){
	printf(" 1");
      }
      printf("\n");
      exit(0);
    }
  } else {
    printf("1");
    for(int i = 1; i <= b; i++){
      printf(" %d", exp(i));
    }
    for(int i = 1; i <= a; i++){
      printf(" %d", exp(b) + i);
    }
    for(int i = 0; i < n-a-b-1; i++){
      printf(" 1");
    }
    printf("\n");
    exit(0);
  }
}