#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int Max(int a, int b) {
  return (a > b ? a : b);
}
main(int argc, char **argv) {
  char a[1000000], b[1000000];
  scanf("%s %s", a, b);
  int len = strlen(a);
  int s2 = 0, s1 = 0;
  //printf("%s %s\n", a, b);
  //printf("%d\n", len);
  for(int i = 0; i < len; i++){
    if(a[i] == b[i]){
     
    } else if (a[i] < b[i]){
      s1++;
    } else {
      s2++;
    }
  }
  //printf("%d %d\n", s2, s1);
  printf("%d\n", Max(s2, s1));
   exit(0);
}