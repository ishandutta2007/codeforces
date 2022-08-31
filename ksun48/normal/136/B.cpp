#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int DEBUG = 0;
int dec2base(int n, int base, int *base_rep) {
  // return ndigit in the base rep
  // by successive mod ops
  // base_rep[0] is the least significant digit
  int ndigit=0;
  while(n>=base) {
    base_rep[ndigit++] = (n % base);
    n = (n - (n % base))/base;
  }
  base_rep[ndigit++] = n;
  if(0) {
    for(int i=ndigit-1; i>=0; i--) {
      printf(" %d", base_rep[i]);
    }
    printf("\n");
  }
  return ndigit;
}
void print1d(int *vec, int M, const char *str=NULL) {
  if(str != NULL) printf("%s ", str);
  for(int i=0; i<M; i++) {
    if(i>0) printf(" ");
    printf("%d", vec[i]);
  }
  printf("\n");
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a, b;
  scanf("%d%d", &a, &b);
  int a1[32], b1[32];
  for(int i = 0; i < 32; i++){
    a1[i] = 0;
    b1[i] = 0;
  }
  int a2 = dec2base(a, 3, a1);
  int b2 = dec2base(b, 3, b1);
  int c1[32];
  for(int i = 0; i < 32; i++){
    c1[i] = (3 + b1[i] - a1[i]) % 3;
  }
  //print1d(a1, 32);
  //print1d(b1, 32);
  //print1d(c1, 32);
  int c = 0;
  for(int i = 31; i >= 0; i--){
    c *= 3;
    c += c1[i];
  }
  printf("%d\n", c);
}