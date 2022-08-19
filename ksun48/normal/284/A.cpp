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
#define reorder(a, b) if(a>b) swap(a,b);
int gcd(int a, int b) { 
  reorder(a, b);
  while(a != 0) { 
    b = b % a;
    reorder(a, b);
  }
  return b;
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int p;
  cin >> p;
  int k = 0;
  for(int i = 1; i <= p-1; i++){
    if(gcd(i,p-1) == 1){
      k++;
    }
  }
  cout << k << endl;
}