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
  int n, m;
  cin >> n >> m;
  m = m % ((n)*(n+1)/2);
  for(int i = 1; i <= n; i++){
    m -= i;
    if(m < 0){
      m += i;
      cout << m << endl;
      exit(0);
    }
  }
  exit(0);
}