/*
ID: ksun482
LANG: C++
TASK: start
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int DEBUG = 0;
int il(char a){
  if(('a' <= a && a <= 'z')||('A' <= a && a <= 'Z')){
    return 1;
  }
  return 0;
}
main(int argc, char **argv) {
  if(argc>=2) {
    DEBUG = atoi(argv[1]);
  }
  char maine;
  int isps = 0;
  while(scanf("%c", &maine) == 1){
    if(isps == 1 && il(maine)){
      printf(" %c", maine);
      isps = 0;
    } else if (isps == 0 && il(maine)){
      printf("%c", maine);
      isps = 0;
    } else if (maine == ' '){
      isps = 1;
    } else {
      printf("%c", maine);
      isps = 1;
    }
  }
  //printf("\n");
  exit(0);
}