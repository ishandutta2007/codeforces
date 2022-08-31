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
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
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
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a, b;
  cin >> a >> b;
  cout << a +reverse(b) << endl;
}