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
  int a;
  scanf("%d", &a);
  LL d[a+1], k[a+1];
  d[0] = 1;
  k[0] = 0;
  for(int i = 1; i <= a; i++){
    d[i] = k[i-1] % 1000000007;
    k[i] = (3*d[i-1] + 2*k[i-1]) % 1000000007;
  }
  cout << d[a] << endl;
}