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
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL p, q;
  cin >> p >> q;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    LL a;
    cin >> a;
    double qd = (double)q;
    double ad = (double)a;
    LL k = 2000000000000000000;
    double c = (double)(k);
    if(qd*ad >= c){
      cout << "NO" << endl;
      exit(0);
    }
    if(p-q*a < 0){
      cout << "NO" << endl;
      exit(0);
    }
    if(p-q*a > q){
      cout << "NO" << endl;
      exit(0);
    }
    p -= q*a;
    swap(p,q);
  }
  if(q == 0){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}