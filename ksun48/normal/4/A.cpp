#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
main(int argc, char **argv) {
  int a;
  scanf("%d", &a);
  if(a % 2 == 1 || a == 2){
    printf("NO\n");
    exit(0);
  } else {
    printf("YES\n");
    exit(0);
  }
}