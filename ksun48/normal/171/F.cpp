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
int reverse(int k){
  int digits[11];
  int a = k;
  int i = 0;
  while(a != 0){
    digits[i] = a % 10;
    a = (a-a%10)/10;
    i++;
  }
  int b = 0;
  for(int j = 0; j < i; j++){
    b *= 10;
    b += digits[j];
  }
  return b;
}
int is_prime(int n) {
  if(n<2) return 0;
  for(int i=2; i<=int(sqrt(1.0*n)); i++) {
    if( (n%i) == 0 ) return 0;
  }
  return 1;
}
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  int a;
  cin >> a;
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int k = 0;
  for(int n = 10; n < 1111111111; n++){
    if(n != reverse(n)){
      if(is_prime(n) && is_prime(reverse(n))){
	k++;
	if( k == a){
	  cout << n << endl;
	  exit(0);
	}
      }
    }
  }
}