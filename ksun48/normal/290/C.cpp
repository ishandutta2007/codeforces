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
  int tux;
  cin >> tux;
  int foo = 0;
  int bar = 0;
  int baz = 0;
  int quz = 0;
  while(tux > 0){
    tux--;
    int pur;
    cin >> pur;
    foo += pur;
    bar++;
    if(max(foo*quz,bar*baz) == foo*quz){
      baz = foo;
      quz = bar;
    }
  }
  double k = (double)baz / (double)quz;
  cout << k << endl;
}