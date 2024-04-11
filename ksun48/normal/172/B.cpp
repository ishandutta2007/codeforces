#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <complex>
#include <deque>
#include <map>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a, b, m, r0;
  cin >> a >> b >> m >> r0;
  int r[m];
  for(int i = 0; i < m; i++){
    r[i] = -1;
  }
  int cur = r0;
  cur = (a*cur+b)%m;
  r[cur] = 0;
  for(int i = 0; i <= m; i++){
    if(r[(a*cur+b)%m] == -1){
      r[(a*cur+b)%m] = r[cur] + 1;
      cur = (a*cur+b)%m;
    } else {
      cout << r[cur]+1-r[(a*cur+b)%m] << endl;
      exit(0);
    }
  }
}