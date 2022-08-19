#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <complex>
#include <deque>
#include <map>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  int ans[n];
  for(int i = 0; i < n; i++){
    ans[i] = 0;
    for(int j = 0; j < n; j++){
      int a;
      cin >> a;
      if(a >= 0){
	ans[i] = ans[i] | a;
      }
    }
  }
  for(int i = 0; i < n; i++){
    cout << ans[i] << " ";
  } 
  cout << endl;
}