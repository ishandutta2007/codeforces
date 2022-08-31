#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
#define LL int64_t
int DEBUG = 0;
LL is_prime(LL n) {
  if(n<2) return 0;
  for(LL i=2; i*i<=n; i++) {
    if((n%i) == 0 ) return i;
  }
  return 1;
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL a;
  cin >> a;
  if(a == 1){
    cout << 1 << endl << 0 << endl;
    exit(0);
  }
  LL k = is_prime(a);
  if(k == 1){
    cout << 1 << endl << 0 << endl;
    exit(0);
  }
  LL j = is_prime(a/k);
  if(j == 1){
    cout << 2 << endl;
    exit(0);
  }
  cout << 1 << endl << j*k << endl;
}