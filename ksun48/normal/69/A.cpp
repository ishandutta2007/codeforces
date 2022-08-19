#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>
#include <set>
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
  int n;
  cin >> n;
  int a = 0, b=0,c=0;
  for(int i = 0; i < n; i++){
    int d,e,f;
    cin >> d >> e >> f;
    a += d;
    b += e;
    c += f;
  }
  if(a == 0 && b == 0 && c == 0){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  exit(0);
}