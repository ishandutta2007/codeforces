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
  int n;
  int k = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    if(a+b+c>= 2){
      k++;
    }
  }
  cout << k << endl;
  exit(0);
}