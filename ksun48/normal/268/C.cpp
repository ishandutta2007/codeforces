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
  int n, m;
  cin >> n >> m;
  if(n >= m){
    cout << m+1 << endl;
    for(int i = 0; i <= m; i++){
      cout << n-i << " " << i << endl;
    }
  } else {
    cout << n+1 << endl;
    for(int i = 0; i <= n; i++){
      cout << i << " " << m-i << endl;
    }
  }
  
}