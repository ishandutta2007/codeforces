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
  int a, b, c;
  cin >> a >> b >> c;
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int f[c+1];
  f[0]=a;
  f[1]=b;
  for(int i = 2; i <= c; i++){
      f[i]=f[i-1]+f[i-2];
  }    
  cout << f[c] << endl;
}