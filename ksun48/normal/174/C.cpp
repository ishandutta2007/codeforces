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
  scanf("%d", &n);
  int a[n+2];
  a[0] = 0;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  a[n+1] = 0;
  int b[n+1];
  for(int i = 0; i <= n; i++){
    b[i] = a[i+1]-a[i];
  }
  int k = 0;
  for(int i = 0; i <= n; i++){
    if( b[i] > 0){
      k += b[i];
    }
  }
  cout << k << endl;
  int p[k];
  int pc = 0;
  int m[k];
  int mc = 0;
  for(int i = 0; i <= n; i++){
    if(b[i] > 0){
      for(int j = 0; j < b[i]; j++){
	p[pc++] = i;
      }
    } else {
      for(int j = 0; j < -b[i]; j++){
	m[mc++] = i;
      }
    }
  }
  for(int i = 0; i < k; i++){
    cout << p[i] + 1 << " " << m[i] << endl;
  }
}