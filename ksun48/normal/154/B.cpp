#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int is_prime(int n) {
  if(n<2) return 0;
  for(int i=2; i*i<=n; i++) {
    if( (n%i) == 0 ) return i;
  }
  return n;
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m;
  cin >> n >> m;
  int hc[n+1], primes[n+1], idx[n+1];
  for(int i = 0; i < n+1; i++){
    hc[i] = 0;
    primes[i] = 0;
    idx[i] = 0;
  }
  for(int j = 0; j < m; j++){
    char a[2];
    int b;
    cin >> a >> b;
    if(a[0] == '+'){
      if(hc[b] == 1){
	cout << "Already on" << endl;
      } else {
	int k = b;
	while (k != 1){
	  int j = is_prime(k);
	  if(primes[j] > 0){
	    cout << "Conflict with " << idx[j] << endl;
	    break;
	  }
	  else {
	    k = k/j;
	  }
	}
	if(k == 1){
	  k = b;
	  while (k != 1){
	    int j = is_prime(k);
	    k = k/j;
	    primes[j] = 1;
	    idx[j] = b;
	  }
	  cout << "Success" << endl;
	  hc[b] = 1;
	}	
      }
    } else {
      if(hc[b] == 1){
	int k = b;
	while (k != 1){
	  int j = is_prime(k);
	  k = k/j;
	  primes[j] = 0;
	  idx[j] = 0;
	}
	hc[b] = 0;
	cout << "Success" << endl;
      } else {
	cout << "Already off" << endl;
      }
    }
  }
}