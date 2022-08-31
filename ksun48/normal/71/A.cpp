#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a;
  scanf("%d", &a);
  for(int i = 0; i < a; i++){
    char pwn[101];
    scanf("%s", pwn);
    int len = strlen(pwn);
    if(len > 10){
      printf("%c", pwn[0]);
      printf("%d", len-2);
      printf("%c\n", pwn[len-1]);
    } else {
      printf("%s\n", pwn);
    }
  }
}