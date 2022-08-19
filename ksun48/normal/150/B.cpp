#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LL int64_t
#define MOD 1000000007
int DEBUG = 0;
int powmod(int m, int n){
  LL a = 1;
  for(int i = 0; i < n; i++){
    a = m*a;
    a = a % MOD;
  }
  return ((int)a);
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m, k;
  cin >> n >> m >> k;
  if(k > n){
    cout << powmod(m, n) << endl;
    exit(0);
  }
  if(k == 1){
    cout << powmod(m, n) << endl; 
    exit(0);
  }
  if(k == n){
    cout << powmod(m, int((n+1)/2)) << endl;
    exit(0);
  }
  if(k % 2 == 0){
    cout << m << endl;
    exit(0);
  }
  cout << m*m << endl;

}