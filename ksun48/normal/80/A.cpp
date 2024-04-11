#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <set>
#include <math.h>
#define LL int64_t
using namespace std;
int Max(int a, int b) {
  return (a > b ? a : b);
}

int compare_dec (const void * a, const void * b) {
  if ( *(int*)a < *(int*)b ) return 1;
  if ( *(int*)a > *(int*)b ) return -1;
  return 0;
}
main(int argc, char **argv) {
  int n, m;
  cin >> n >> m;
  int primes[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  for(int i = 0; i < 15; i++){
    if(n == primes[i]){
      if(i == 14){
	cout << "NO" << endl;
	exit(0);
      }
      if(m == primes[i+1]){
	cout << "YES" << endl;	
	exit(0);
      }
      cout << "NO" << endl;
      exit(0);
    }    
  }
  
  exit(0);
}