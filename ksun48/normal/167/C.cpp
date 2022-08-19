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
int iswin(LL a, LL b){
  if(a == 0 || b == 0){
    return 0;
  }
  if(a > b){
    LL tmp = a;
    a = b;
    b = tmp;
  }
  if(b % a == 0){
    return 1;
  }
  if(iswin(a, b%a) == 0){
    return 1;
  } else {
    if(a % 2 == 1){
      if(((b-b%a)/a) % 2 == 1){
	return 0;
      } else {
	return 1;
      }
    } else {
      if((((b-b%a)/a) % (a+1)) % 2 == 1){
	return 0;
      } else {
	return 1;
      }
    }
  }
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    LL a, b;
    cin >> a >> b;
    if (iswin(a, b) == 1){
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
  }
  
}