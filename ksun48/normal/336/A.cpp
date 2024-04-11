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
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int x, y;
  cin >> x >> y;
  if(x > 0 && y > 0){
    cout << 0 << " " << x+y << " " << x+y << " " << 0 << endl;
  } else if(x < 0 && y > 0){
    cout << x-y << " " << 0 << " " << 0 << " " << y-x << endl;
  } else if(x < 0 && y < 0){
    cout << x+y << " " << 0 << " " << 0 << " " << x+y << endl;
  } else {
    cout << 0 << " " << y-x << " " << x-y << " " << 0 << endl;
  }
}