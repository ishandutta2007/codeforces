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
struct NODE{
  int s;
  double pos;
};
int Max(int a, int b) {
  return (a > b ? a : b);
}
int compare_NODE_inc (const void * a_, const void * b_) {
  NODE *a = (NODE*)a_;
  NODE *b = (NODE*)b_;
  if(      a->pos > b->pos ) return  1;
  else if( a->pos < b->pos ) return -1;
  else return 0;
}
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m;
  cin >> n >> m;
  NODE stuff[n];
  for(int i = 0; i < n; i++) cin >> stuff[i].s >> stuff[i].pos;
  int t = 0;
  int dp[n];
  for(int i = 0; i < n; i++){
    int m = 0;
    for(int j = 0; j < i; j++){
      if(stuff[i].s >= stuff[j].s){
	m = Max(m, dp[j]);
      }
    }
    dp[i] = m+1;
    t = Max(t, dp[i]);
  }
  cout << n-t << endl;
}