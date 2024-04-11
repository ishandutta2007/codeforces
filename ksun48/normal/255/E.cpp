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
int DEBUG = 0;

main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n;
  cin >> n;
  
  LL nimsum = 0;
  for(LL i = 0; i < n; i++){
    LL k;
    cin >> k;
    if(k <= 3 || (k >= 82 && k <= 6723)){
      nimsum = nimsum ^ 0;
    } else if((k >= 4 && k <= 15) || (k >= 50626 && k <= 2562991875)){
      nimsum = nimsum ^ 1;
    } else if(k >= 6724 && k <= 50625){
      nimsum = nimsum ^ 3;
    } else {
      nimsum = nimsum ^ 2;
    }
  }
  //cout << nimsum << endl;
  if(nimsum == 0){
    cout << "Rublo" << endl;
  } else {
    cout << "Furlo" << endl;
  }
}