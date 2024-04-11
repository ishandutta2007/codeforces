#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;
int Max(int a, int b) {
  return (a > b ? a : b);
}

main(int argc, char **argv) {
  int a, b;
  cin >> a >> b;
  
  cout << int(a*b/2) << endl;
  exit(0);
}