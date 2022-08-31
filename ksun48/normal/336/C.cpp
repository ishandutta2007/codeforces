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
  int n;
  cin >> n;
  int a[n];
  int e[n];
  int q[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
    e[i] = a[i];
    q[i] = a[i];
  }
  for(int m = 0; m < 30; m++){
    int all1 = 1;
    for(int i = 0; i < n; i++){
      if(e[i] % 2 == 0){
	all1 = 0;
      }
    }
    if(all1){
      cout << n << endl;
      for(int k = 0; k < n; k++){
	cout << a[k] << " ";
      }
      cout << endl;
      exit(0);
    }
    for(int i = 0; i < n; i++){
      e[i] /= 2;
    }
  }
  for(int ans = 29; ans >= 0; ans--){
    int stuff[n];
    for(int i = 0; i < n; i++){
      stuff[i] = a[i] >> ans;
    }
    int num = 0;
    int tand = 1073741823;
    for(int i = 0; i < n; i++){
      if(stuff[i] % 2 == 1){
	num++;
	tand &= a[i];
      }
    }
    if(num > 0){
      if(tand % (1 << ans) == 0){
	cout << num << endl;
	for(int i = 0; i < n; i++){
	  if(stuff[i] % 2 == 1){
	    cout << a[i] << " ";
	  }
	}
	cout << endl;
	exit(0);
      }
    }
  }
}