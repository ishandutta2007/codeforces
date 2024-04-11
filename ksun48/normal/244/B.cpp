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
int m[15];
int len;
int ans = 0;
void allflip(int *flip, int n, int k, int a, int b) {
  if (n==k) {
    if(flip[0] == 0){
      return;
    }
    if(n == len){
      for(int i = 0; i < n; i++){
	if(flip[i] < m[i]){
	  ans++;
	  return;
	} else if(flip[i] > m[i]){
	  return;
	}
      }
    }
    ans++;
    return;
  } else {
    flip[k] = a;
    allflip(flip, n, k+1, a, b);
    flip[k] = b;  
    allflip(flip, n, k+1, a, b);
  }
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  char c[15];
  cin >> c;
  len = strlen(c);
  for(int i = 0; i < len; i++){
    m[i] = c[i]-'0';
  }
  for(int d = 1; d <= len; d++){
    for(int i = 0; i < 10; i++){
      for(int j = i+1; j < 10; j++){
	int vec[d];
	allflip(vec, d, 0, i, j);
	//cout << d << " " << i << " " << j << " " << ans << endl;
	//ans = 0;
      }
    }
  }
  for(int d = 1; d < len; d++){
    ans -= 72;
  }
  for(int i = 1; i <= 9; i++){
    int b = 0;
    for(int j = 0; j < len; j++){
      if(i > m[j]){
	b = 1;
	break;
      } else if(i < m[j]){
	b = 0;
	break;
      }
    }
    if(b == 0){
      ans -= 8;
      //cout << i << endl;
    }
  }
  cout << ans << endl;
  
}