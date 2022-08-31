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
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("input.txt", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("output.txt", "w", stdout);
  multiset<int> mea;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int k;
    cin >> k;
    mea.insert(k);
  }
  int minr = n;
  int curr = n;
  for(int i = 0; i <= 5000; i++){
    curr = curr + mea.count(i) - mea.count(2*i+1)-mea.count(2*i+2);
    if(curr < minr){
      minr = curr;
    }
  }
  cout << minr << endl;
}