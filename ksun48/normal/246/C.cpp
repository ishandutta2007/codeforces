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
int compare_inc (const void * a, const void * b) {
  if ( *(int*)a > *(int*)b ) return 1;
  if ( *(int*)a < *(int*)b ) return -1;
  return 0;
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, k;
  cin >> n >> k;
  int beauty[n];
  for(int i = 0; i < n; i++){
    cin >> beauty[i];
  }
  int a = 0;
  qsort(beauty, n, sizeof(int), compare_inc);
  for(int i = 0; i < n; i++){
    for(int j = i; j >= 0; j--){
      if(a >= k) exit(0);
      cout << n-i << " ";
      for(int k = n-1; k > i; k--){
	cout << beauty[k] << " ";
      }
      cout << beauty[j] << endl;
      a++;
    }
  }
  
}