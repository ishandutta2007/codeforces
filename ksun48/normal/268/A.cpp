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
int DEBUG = 0;
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  int a[n];
  int b[n];
  int c = 0;
  for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(a[i] == b[j]) c++;
    }
  }
  cout << c << endl;
}