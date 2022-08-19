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
  int n;
  cin >> n;
  set<int> here;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    while(here.count(a)){
      here.erase(a);
      a = a+1;
    }
    here.insert(a);
  }
  //cout << here.size() << endl;
  cout << (*here.rbegin()) + 1 - here.size() << endl;
}