#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
main(int argc, char **argv) {
  char str[2222];
  scanf("%s", str);
  int len = strlen(str);
  for(int i = 0; i < len; i++){
    if(str[i] == 'H' || str[i] == 'Q' || str[i] == '9'){
      printf("YES\n");
      exit(0);
    }
  }
  printf("NO\n");
  exit(0);
}