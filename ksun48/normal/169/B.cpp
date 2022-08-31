#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <complex>
#include <deque>
#include <map>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int compare_dec (const void * a, const void * b) {
  if ( *(char*)a < *(char*)b ) return 1;
  if ( *(char*)a > *(char*)b ) return -1;
  return 0;
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  char a[100010], b[100010];
  cin >> a >> b;
  int len = strlen(b);
  qsort(b, len, sizeof(char), compare_dec);
  int len2 = strlen(a);
  int counter = 0;
  //cout << b << endl;
  for(int i = 0; i < len2; i++){
    if(counter == len || a[i] >= b[counter]){
      cout << a[i];
    } else {
      cout << b[counter];
      counter++;
    }
  }
  cout << endl;
}