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
LL lucky[13];
LL MOD = 1000000007;
LL **alloc2d(int M, int N) {
  LL **a = new LL * [M];
  for(int i=0; i<M; i++) a[i] = new LL [N];
  return a;
}
LL **pascal = alloc2d(20, 20); LL pow2[20]; LL pow8[20];
int dec2base(int n, int base, int *base_rep) {
  int ndigit=0;
  while(n>=base) {
    base_rep[ndigit++] = (n % base);
    n = (n - (n % base))/base;
  }
  base_rep[ndigit++] = n;
  return ndigit;
}
void addlucky(int a, int j){
  for(int i = 0; i <= j; i++){
    lucky[a+i] += (pow2[i])*(pow8[j-i]*(pascal[j][i]));
    //cout << a << " " << i << " " << j << " " <<  (pow2[i])*(pow8[j-i]*(pascal[j][i])) << endl;
  }
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  for(int i = 0; i < 13; i++) lucky[i] = 0;
  pow2[0] = pow8[0] = 1;
  for(int i = 1; i < 11; i++){
    pow2[i] = 2*pow2[i-1]; pow8[i] = 8*pow8[i-1];
  }
  pascal[0][0] = 1;
  for(int n=1; n<=11; n++) {
    pascal[n][0] = pascal[n][n] = 1;
    for(int p=1; p<=n-1; p++) pascal[n][p] = (pascal[n-1][p-1] + pascal[n-1][p]);
  }
  int m;
  cin >> m;
  int base_rep[11];
  for(int i = 0; i < 11; i++) base_rep[i] = 0;
  int ndig = dec2base(m, 10, base_rep);
  int newrep[11];
  for(int i = 0; i < 11; i++) newrep[i] = base_rep[10-i];
  //for(int i = 0; i < 11; i++) cout << newrep[i];
  //cout << endl;
  int curlucky = 0;
  for(int i = 0; i < 11; i++){
    int a = 0;
    int b = newrep[i];
    if(i == 10) b++;
    for(int j = a; j < b; j++){
      if(j == 4 || j == 7) curlucky++;
      addlucky(curlucky, 10 - i);
      if(j == 4 || j == 7) curlucky--;
    }
    if(newrep[i] == 4 || newrep[i] == 7) curlucky++;
  }
  lucky[0]--;
  //for(int i = 0; i < 13; i++) cout << lucky[i] << endl;
  LL ways = 0;
  for(int i = 0; i <= 11; i++){
    for(int j1 = 0; j1 < i; j1++){
      for(int j2 = 0; j2 < i-j1; j2++){
	for(int j3 = 0; j3 < i-j1-j2; j3++){
	  for(int j4 = 0; j4 < i-j1-j2-j3; j4++){
	    for(int j5 = 0; j5 < i-j1-j2-j3-j4; j5++){
	      for(int j6 = 0; j6 < i-j1-j2-j3-j4-j5; j6++){
		LL numways = 1;
		numways = (numways * lucky[i]) % MOD;
		lucky[i]--;
		numways = (numways * lucky[j1]) % MOD;
		lucky[j1]--;
		numways = (numways * lucky[j2]) % MOD;
		lucky[j2]--;
		numways = (numways * lucky[j3]) % MOD;
		lucky[j3]--;
		numways = (numways * lucky[j4]) % MOD;
		lucky[j4]--;
		numways = (numways * lucky[j5]) % MOD;
		lucky[j5]--;
		numways = (numways * lucky[j6]) % MOD;
		lucky[j5]++; lucky[j4]++; lucky[j3]++; lucky[j2]++; lucky[j1]++; lucky[i]++;
		
		ways = (ways + numways) % MOD;
	      }     
	    }
	  }
	}
      }
    }    
  }
  cout << ways << endl;
}