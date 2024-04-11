#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <set>
#include <math.h>
#include <deque>
#define LL int64_t
using namespace std;
int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
int compare_dec (const void * a, const void * b) {
  if ( Abs(*(int*)a) < Abs(*(int*)b) ) return 1;
  if ( Abs(*(int*)a) > Abs(*(int*)b) ) return -1;
  return 0;
}
int is_prime(int k){
  if(k == 1){
    return 0;
  }
  int prime = 1;
  for(int i = 2; i*i <= k; i++){
    if(k % i == 0){
      prime = 0;
      break;
    }
  }
  return prime;
}
main(int argc, char **argv) {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    LL a;
    cin >> a;
    LL k = sqrt(1.0*a);
    if(k*k == a){
      if(is_prime(k)){
	cout << "YES" << endl;
      } else {
	cout << "NO" << endl;
      }
      //cout << "HMM" << endl;
    } else {
      cout << "NO" << endl;
    }
    
  }
  exit(0);
}