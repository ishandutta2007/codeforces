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
  int n;
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  cin >> n;
  int diff = 0;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    if(diff - a >= -500){
      cout << 'A';
      diff -= a;
    } else {
      cout << 'G';
      diff += b;
    }
  }
  cout << endl;
}