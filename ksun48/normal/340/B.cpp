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
  int n;
  cin >> n;
  int x[n], y[n];
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      int maxd = 0;
      int d = -1;
      int mind = 0;
      int e = -1;
      for(int k = 0; k < n; k++){
	if(k != i && k != j){
	  int a = (x[j]-x[i])*y[k]+(y[i]-y[j])*x[k]+x[i]*y[j]-x[j]*y[i];
	  if(a > maxd){
	    d = k;
	    maxd = a;
	  } 
	  if(a < mind){
	    e = k;
	    mind = a;
	  }
	}
      }
      if(d == -1 || e == -1) continue;
      maxd-mind;
      ans = max(ans, maxd-mind);
    }
    
  }
  double ans1 = (double)ans;
  printf("%.10lf\n", ans1/2);

}