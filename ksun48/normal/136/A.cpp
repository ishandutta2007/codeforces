#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void print_vec(int *vec, int n, const char *str=NULL) {
  if(str != NULL) printf("%s ", str);
  for(int i=0; i<n; i++) {
    if(i>0) printf(" ");
    printf("%d", vec[i]+1);
  }
  printf("\n");
  fflush(stdout);
}
main(int argc, char **argv) {
  int a;
  scanf("%d", &a);
  int presents[a];
  int b;
  for(int i = 0; i < a; i++){
    scanf("%d", &b);
    presents[b-1] = i;
  }
  print_vec(presents, a);
}