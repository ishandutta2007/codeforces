#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#include <complex>
#include <deque>
#include <map>
#include <utility>
#include <limits>
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
char str[1000001];
int compare_inc (const void * a, const void * b) {
  if ( *(int*)a > *(int*)b ){
    if(str[*(int*)b-1] == 'r'){
      return 1;
    } else {
      return -1;
    }
  }
  if ( *(int*)a < *(int*)b ){
    if(str[*(int*)a-1] == 'r'){
      return -1;
    } else {
      return 1;
    }
  }
  return 0;
}
int DEBUG = 0;
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  
  cin >> str;
  int len = strlen(str);
  int array[len];
  for(int i = 0; i < len; i++){
    array[i] = i+1;
  }
  qsort(array, len, sizeof(int), compare_inc);
  for(int i = 0; i < len; i++){
    cout << array[i] << endl;
  }
}