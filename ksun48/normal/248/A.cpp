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
  int n;
  cin >> n;
  int l[n];
  int numl = 0;
  int r[n];
  int numr = 0;
  for(int i = 0; i < n; i++){
    cin >> l[i] >> r[i];
    numl += l[i];
    numr += r[i];
  }
  int k = 0;
  if(numl*2 > n){
    k += n-numl;
  } else {
    k += numl;
  }
  if(numr*2 > n){
    k += n-numr;
  } else {
    k += numr;
  }
  cout << k << endl;
}