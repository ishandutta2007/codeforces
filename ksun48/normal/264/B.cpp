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
int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
int DEBUG = 0;
int prime[10000];
map<int,int> pmap;
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);
  int np = 0;
  for(int i = 2; i < 100000; i++){
    int isprime = 1;
    for(int j = 0; j < np; j++){
      if(prime[j]*prime[j] > i) break;
      if(i % prime[j] == 0){
	isprime = 0;
	break;
      }
    }
    if(isprime) prime[np] = i;
    if(isprime) pmap[i] = np;
    if(isprime) np++;
  }
  //for(int i = 0; i < np; i++) cout << prime[i] << endl;
  //cout << np << endl;
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  int num[n];
  for(int i = 0; i < n; i++){
    cin >> num[i];
  }
  int maxs[10000];
  //cout << n << endl;
  for(int i = 0; i < 10000; i++) maxs[i] = 0;
  for(int i = 0; i < n; i++){
    int primes[20];
    int k = 0;
    if(num[i] == 1) continue;
    for(int j = 0; j < np; j++){
      if(num[i] == 1) break;
      if(prime[j]*prime[j] > num[i]){
	primes[k++] = pmap[num[i]];
	//cout << num[i] << endl;
	break;
      }
      if(num[i] % prime[j] == 0){
	//cout << prime[j] << endl;
	while(num[i] % prime[j] == 0) num[i] = num[i]/prime[j];
	primes[k++] = j;
      }
    }
   
    int maxn = 1;
    for(int j = 0; j < k; j++){
      maxn = Max(maxn, maxs[primes[j]]+1);
    }
    for(int j = 0; j < k; j++){
      maxs[primes[j]] = maxn;
    }
    for(int j = 0; j < 4; j++){
      //cout << maxs[j] << endl;
    }
    //cout << endl;
  }
  int ans = 1;
  for(int i = 0; i < np; i++){
    ans = Max(ans, maxs[i]);
  }
  cout << ans << endl;
}