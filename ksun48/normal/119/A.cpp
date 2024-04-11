#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;
int gcd(int a, int b){
  if(a == 0){
    return b;
  }
  if(b == 0){
    return a;
  }
  if(a == b){
    return a;
  }
  if(a > b){
    return gcd(a % b, b);
  }
  return gcd (b % a, a);
}

main(int argc, char **argv) {
  int a, b, n;
  cin >> a >> b >> n;
  while(1){
    if(gcd(n,a) <= n){
      n -= gcd(n,a);
    } else {
      cout << 1 << endl;
      exit(0);
    }
    if(gcd(n,b) <= n){
      n -= gcd(n,b);
    } else {
      cout << 0 << endl;
      exit(0);
    }   
  }
  exit(0);
}