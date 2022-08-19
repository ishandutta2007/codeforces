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
LL Abs(LL i){
  if(i < 0) return -i;
  return i;
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, d;
  cin >> n >> d;
  LL time[n];
  for(int i = 1; i < n-1; i++){
    cin >> time[i];
  }
  time[n-1] = 0;
  LL x[n];
  LL y[n];
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  LL dist[n];
  int vis[n];
  for(int i = 0; i < n; i++){
    vis[i] = 0;
    dist[i] = 1000000007;
  }
  dist[0] = 0;
  int nvis = 1;
  vis[0] = 1;
  int cur = 0;
  while(nvis < n){

    for(int i = 0; i < n; i++){
      if(!vis[i]){
	dist[i] = min(dist[i], dist[cur] + d*(Abs(x[i]-x[cur])+Abs(y[i]-y[cur])) - time[i]);
      }
    }
    int minnode = -1;
    LL mindist = 10000000007;
    for(int i = 0; i < n; i++){
      if(!vis[i]){
	if(mindist > dist[i]){
	  mindist = dist[i];
	  minnode = i;
	}
      }
    }
    cur = minnode;
    nvis++;
    vis[cur] = 1;
  }
  cout << dist[n-1] << endl;
}