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
  int x, y;
  cin >> x >> y;
  if(x == 0 && y == 0){
    cout << 0 << endl;
    exit(0);
  }
  for(int i = 0; i <= 100; i++){
    if(y == -i && x >= -i && x <= i+1){
      cout << 4*i << endl;
      exit(0);
    }
    if(x == i+1 && y >= -i && y <= i+1){
      cout << 4*i+1 << endl;
      exit(0);
    }
    if(y == i+1 && x >= -i-1 && x <= i+1){
      cout << 4*i+2 << endl;
      exit(0);
    }
    if(x == -i-1 && y >= -i-1 && y <= i+1){
      cout << 4*i+3 << endl;
      exit(0);
    }
  }
  
  
}