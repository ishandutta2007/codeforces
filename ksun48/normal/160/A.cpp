#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>
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
  int c[n];
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> c[i];
    sum += c[i];
  }
  qsort(c, n, sizeof(int), compare_dec);
  int s = 0;
  for(int i = 0; i < n; i++){
    s += c[i];
    if(2*s > sum){
      cout << i + 1 << endl;
      exit(0);
    }
  }
  exit(0);
}