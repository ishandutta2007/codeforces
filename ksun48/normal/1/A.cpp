#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;
main(int argc, char **argv) {
  long long a, b, c, d, e;
  cin >> a >> b >> c;

  if(a % c == 0){
    d = a/c;
  } else {
    d = (long long)(a/c) + 1;
  }
  if(b % c == 0){
    e = b/c;
  } else {
    e = (long long)(b/c) + 1;
  }
  long long f = (long long) (d*e);
  cout << f << endl;
  exit(0);
}