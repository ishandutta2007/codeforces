#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;
int Max(int a, int b) {
  return (a > b ? a : b);
}

main(int argc, char **argv) {
  int n;
  cin >> n;
  int numpas = 0;
  int maxpas = 0;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    numpas -= a;
    numpas += b;
    maxpas = Max(maxpas, numpas);
  }
  cout << maxpas << endl;
  exit(0);
}