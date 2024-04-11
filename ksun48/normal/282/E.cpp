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
// SAUSAGE SAUSAGE SAUSAGE SAUSAGE SAUSAGE SAUSAGE SAUSAGE SAUSAGE
int tr[10000000][2];
int ntr = 1;
void addnode(LL x){
  int k = 0;
  for(int i = 39; i >= 0; i--){
    LL cur = ((1LL << i) & x);
    cur = cur / (1LL << i);
    if(tr[k][cur] >= 0){
      k = tr[k][cur];
    } else {
      tr[k][cur] = ntr;
      tr[ntr][0] = tr[ntr][1] = -1;
      k = ntr;
      ntr++;
    }
  }
}
LL maxsg = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  LL a[n];
  LL sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum ^= a[i];
  }
  tr[0][0] = -1;
  tr[0][1] = -1;
  LL x = 0;
  for(int j = 0; j < n; j++){
    //cout << "x= " << x << " sum = " << sum<< endl;
    addnode(x);
    int k = 0;
    LL cursum = sum;
    for(int i = 39; i >= 0; i--){
      LL cur = ((1LL << i) & sum);
      cur = cur / (1LL << i);
      if(tr[k][1-cur] >= 0){
	cursum ^= ((LL)(1-cur) << i);
	k = tr[k][1-cur];
      } else {
	cursum ^= ((LL)(cur) << i);
	k = tr[k][cur];
      }
    }
    //cout << cursum << endl;
    maxsg = max(maxsg, cursum);
    //cout << cursum << endl;
    sum ^= a[j];
    x ^= a[j];
  }
  addnode(x);
  int k = 0;
  LL cursum = sum;
  for(int i = 39; i >= 0; i--){
    LL cur = ((1LL << i) & x) / (1LL << i);
    if(tr[k][1-cur] >= 0){
      cursum ^= ((1-cur) << i);
      k = tr[k][1-cur];
    } else {
      cursum ^= ((cur) << i);
      k = tr[k][cur];
    }
  }
  maxsg = max(maxsg, cursum);
  cout << maxsg << endl;
}