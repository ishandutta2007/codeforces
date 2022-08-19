#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <set>
#include <math.h>
#define LL int64_t
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
  LL num[21];
  for(int i = 0; i < 21; i++){
    num[i] = 0;
  }
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    num[a+10]++;
  }
  for(int i = 0; i < 21; i++){
    //cout << num[i] << " " << endl;
  }
  LL k = 0;
  for(int i = 0; i <= 9; i++){
    k += num[i]*num[20-i];
  }
  k += (num[10]*(num[10]-1))/2;
  cout << k << endl;
  exit(0);
}