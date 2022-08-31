#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <set>
#include <math.h>
#define LL int64_t
using namespace std;
int Max(int a, int b) {
  return (a > b ? a : b);
}

int compare_dec (const void * a, const void * b) {
  if ( *(int*)a < *(int*)b ) return 1;
  if ( *(int*)a > *(int*)b ) return -1;
  return 0;
}
main(int argc, char **argv) {
  LL k, l;
  cin >> k >> l;
  LL a = 1;
  int c = 0;
  while(a < l && a < 1000000000000000){
    a *= k;
    c++;
  }
  if(a == l){
    cout << "YES" << endl << c-1 << endl;
  } else {
    cout << "NO" << endl;
  }
  exit(0);
}