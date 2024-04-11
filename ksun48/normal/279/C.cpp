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
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m;
  cin >> n >> m;
  int ans[n];
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  multiset<int> umd;
  int j = 0;
  for(int i = 0; i < n; i++){
    while(j < n){
      if(a[j+1] < a[j]){
	j++;
	umd.insert(-1);
      } else if(a[j+1] == a[j]){
	j++;
	umd.insert(0);
      } else if(a[j+1] > a[j]){
	if(umd.count(-1) > 0){
	  break;
	} else {
	  umd.insert(1);
	  j++;
	}
      }
    }
    ans[i] = j;
    //cout << i << " " << ans[i] << endl;
    if(i < n-1){
      if(a[i] < a[i+1]){
	umd.erase(umd.find(1));
      } else if(a[i] == a[i+1]){
	umd.erase(umd.find(0));
      } else if(a[i] > a[i+1]){
	umd.erase(umd.find(-1));
      }
    }
  }
  for(int i = 0; i < m; i++){
    int l, r;
    cin >> l >> r;
    if(ans[l-1] >= r-1){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}