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
int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
int compare_dec (const void * a, const void * b) {
  if ( Abs(*(int*)a) < Abs(*(int*)b) ) return 1;
  if ( Abs(*(int*)a) > Abs(*(int*)b) ) return -1;
  return 0;
}
main(int argc, char **argv) {
  int n, k;
  cin >> n >> k;
  int num[n];
  for(int i = 0; i < n; i++) cin >> num[i];
  qsort(num, n, sizeof(int), compare_dec);
  for(int i = 0; i < n; i++){
    if(k > 0){
      if(num[i] < 0){
	num[i] = -num[i];
	k--;
      }
    }    
  }
  if(k % 2 == 1) num[n-1] = -num[n-1];
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += num[i];
  }
  cout << sum << endl;
  exit(0);
}