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
  int k[1001];
  for(int i = 0; i <= 1000; i++){
    k[i] = 0;
  }
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    k[a]++;
  }
  int b = 0;
  int max = 0;
  int maxn = -1;
  for(int i = 0; i <= 1000; i++){
    if(k[i] > 0){
      b++;
      max = Max(max, k[i]);
    }
  }
  cout << max << " " << b << endl;
  exit(0);
}