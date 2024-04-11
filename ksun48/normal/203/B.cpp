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
  int n, m;
  cin >> n >> m;
  int num[n][n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      num[i][j] = 0;
    }    
  }
  for(int i = 1; i < m+1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    for(int c = a; c >= a-2 && c >= 0; c--){
      for(int d = b; d >= b-2 && d >= 0; d--){
	num[c][d]++;
	if(num[c][d] == 9){
	  cout << i << endl;
	  //cout << a << b << c << d << endl;
	  exit(0);
	}
      }
    }
    for(int e = 0; e < n-2; e++){
      for(int f = 0; f < n-2; f++){
	//cout << num[e][f];
      }
      //cout << endl;
    }
    //cout << endl;
  }
  cout << -1 << endl;
}