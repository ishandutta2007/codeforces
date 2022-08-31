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

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, k;
  cin >> n >> k;
  int o[k];
  int array[n*k+1];
  for(int i = 1; i <= n*k; i++){
    array[i] = 0;
  }
  for(int i = 0; i < k; i++){
    cin >> o[i];
    array[o[i]] = 1;
  }
  int c = 1;
  for(int m = 0; m < k; m++){
    cout << o[m];
    for(int j = 0; j < n-1; j++){
      while(array[c] == 1){
	  c++;
      }
      cout << " " << c;
      c++;
    }
    cout << endl;
  }
  
}