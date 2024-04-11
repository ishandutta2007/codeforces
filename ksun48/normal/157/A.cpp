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
#include <vector>
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, x = 0;
  cin >> n;
  int array[n+1][n+1];
  int rowsums[n];
  int colsums[n];
  for(int i = 0; i < n; i++){
    rowsums[i] = 0;
    colsums[i] = 0;
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> array[i][j];
      rowsums[i] += array[i][j];
      colsums[j] += array[i][j];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(rowsums[i] < colsums[j]){
	x++;
      }
    }
  }
  cout << x << endl;
  exit(0);
}