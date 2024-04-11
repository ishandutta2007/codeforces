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
  int a, b, c;
  cin >> a >> b >> c;
  cout << (int(sqrt((a*1.0*b)/c)) + int(sqrt((b*1.0*c)/a)) + int(sqrt((c*1.0*a)/b)))*4 << endl;
  
exit(0);
}