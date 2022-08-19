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
int compare_inc (const void * a, const void * b) {
  if ( *(int*)a > *(int*)b ) return 1;
  if ( *(int*)a < *(int*)b ) return -1;
  return 0;
}
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, a, b;
  cin >> n >> a >> b;
  int chores[n];
  for(int i = 0; i < n; i++){
    cin >> chores[i];
  }
  qsort(chores, n, sizeof(int), compare_inc);
  cout << chores[b]-chores[b-1] << endl;
}