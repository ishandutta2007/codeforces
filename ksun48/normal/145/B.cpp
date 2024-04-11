#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
main(int argc, char **argv) {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if(c - d != -1 && c - d != 0 && c - d != 1){
    printf("-1\n");
    exit(0);
  }
  if(c - d == 1){
    if(a < c || b < c){
      printf("-1\n");
      exit(0);
    }
    for(int i = 0; i < a-d; i++){
      printf("4");
    }
    for(int i = 0; i < d; i++){
      printf("74");
    }
    for(int i = 0; i < b-d; i++){
      printf("7");
    }
    printf("\n");
    exit(0);
  }
  if(c - d == -1){
    if(a < d || b < d){
      printf("-1\n");
      exit(0);
    }
    printf("74");
    for(int i = 0; i < a-d; i++){
      printf("4");
    }
    for(int i = 0; i < c-1; i++){
      printf("74");
    }
    for(int i = 0; i < b-d; i++){
      printf("7");
    }
    printf("74");
    printf("\n");
    exit(0);
  }
  if(c == d){
    if((a >= c && b > c) || (b >= c && a > c)){
      if(a == c){
	printf("7");
	for(int i = 0; i < a-d+1; i++){
	  printf("4");
	}
	for(int i = 0; i < d-1; i++){
	  printf("74");
	}
	for(int i = 0; i < b-d; i++){
	  printf("7");
	}
	printf("\n");
	exit(0);
      }
      
      for(int i = 0; i < a-d; i++){
	printf("4");
      }
      for(int i = 0; i < d-1; i++){
	printf("74");
      }
      for(int i = 0; i < b-d+1; i++){
	printf("7");
      }
      printf("4\n");
	exit(0);
    }
  }
  printf("-1\n"); exit(0);
}