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
int minNodes = 1000000;
LL a[10];
int num[10];
void allFlip(int *flip, int n, int k) {
  if (n+1==k) {
    vector<int> children[n+1];
    for(int i = 1; i <= n; i++){
      children[flip[i]].push_back(i);
    }
    int ans = 0;
    if(children[0].size() > 1) ans ++ ;
    for(int i = 1; i <= n; i++){
      ans++;
      LL prod = 1;
      int nfactors = num[i];
      for(int j = 0; j < children[i].size(); j++){
	nfactors -= num[children[i][j]];
	if(a[i]/a[children[i][j]] < prod){
	  return;
	}
	prod *= a[children[i][j]];
      }
      if(a[i] % prod != 0){
	return;
      }
      if(nfactors == 0){
	continue;
      }
      if(nfactors == 1 && children[i].size() == 0){
	continue;
      }
      ans += nfactors;
    }
    minNodes = min(minNodes, ans);
    return;
  }
  for (int i=0; i<k; i++) {
    flip[k]=i;
    allFlip(flip, n, k+1);
  }
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    a[i] = -a[i];
    num[i] = 0;
  }
  sort(a+1, a+n+1);
  for(int i = 1; i <= n; i++) a[i] = -a[i];
  for(int i = 1; i <= n; i++){
    LL b = a[i];
    for(LL p = 2; p*p <= a[i]; p++){
      while(b % p == 0){
	num[i]++;
	b /= p;
	if(DEBUG) cout << p << " ";
      }
    }
    if(b > 1){
      num[i]++;
      if(DEBUG) cout << b << " ";
    }
    if(DEBUG) cout << endl;
    if(DEBUG) cout << num[i] << endl;
  }
  int flip[n+1];
  allFlip(flip, n, 1);
  cout << minNodes << endl;
}