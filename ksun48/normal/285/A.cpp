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
  int n, k;
  cin >> n >> k;
  if(k == 0){
    for(int i = 1; i <= n; i++){
      cout << i << " ";
    }
    cout << endl;
  } else {
    
    for(int i = 1; i <= k; i++){
      cout << n-i+1 << " ";
    }
    for(int i = 1; i < n-k+1; i++){
      cout << i << " ";
    }
    cout << endl;
  }
  
  
}