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
  int n;
  cin >> n;
  if( n <= 10){
    cout << 0 << endl;
  } else if( n < 20){
    cout << 4 << endl;
  } else if( n == 20){
    cout << 15 << endl;
  } else if(n == 21){
    cout << 4 << endl;
  } else {
    cout << 0 << endl;
  }
  exit(0);
}