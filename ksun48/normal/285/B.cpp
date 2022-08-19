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
  int n, s, t;
  cin >> n >> s >> t;
  s--; t--;
  int p[n];
  for(int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  int k = s;
  int i = 0;
  while(1){
    if(k == t){
      cout << i << endl;
      exit(0);
    }
    if(i > 0 && k == s){
      cout << -1 << endl;
      exit(0);
    }
    k = p[k];
    i++;
  }
}