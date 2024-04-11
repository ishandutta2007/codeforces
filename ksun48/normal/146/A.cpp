#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
main(int argc, char **argv) {
  int a;
  scanf("%d", &a);
  char num[a];
  scanf("%s", num);
  for(int i = 0; i < a; i++){
    if(num[i] == '4' || num[i] == '7'){
    } else{
      printf("NO\n");
      exit(0);
    }
  }
  int num41 = 0, num71 = 0, num42 = 0, num72 = 0;
  for(int i = 0; i < a/2; i++){
    if(num[i] == '4'){
      num41++;
    } else {
      num71++;
    }
  }
  for(int i = a/2; i < a; i++){
    if(num[i] == '4'){
      num42++;
    } else {
      num72++;
    }
  }
  if((num41 == num42) && (num71 == num72)){
    printf("YES\n");
    exit(0);
  } else {
    printf("NO\n");
    exit(0);
  }
}