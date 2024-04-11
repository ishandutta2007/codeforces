#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <set>
#include <math.h>
#include <deque>
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
int is_prime(int k){
  if(k == 1){
    return 0;
  }
  int prime = 1;
  for(int i = 2; i*i <= k; i++){
    if(k % i == 0){
      prime = 0;
      break;
    }
  }
  return prime;
}
main(int argc, char **argv) {
  int n, m;
  cin >> n >> m;
  char grid[n+1][m+1];
  for(int i = 0; i < n; i++){
    cin >> grid[i];
  }
  int k = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == 'W'){
	int ispig = 0;
	if(i > 0 && grid[i-1][j] == 'P') ispig = 1;
	if(j > 0 && grid[i][j-1] == 'P') ispig = 1;
	if(i < n-1 && grid[i+1][j] == 'P') ispig = 1;
	if(j < m-1 && grid[i][j+1] == 'P') ispig = 1;
	k += ispig;
      }
    }
  }
  cout << k << endl;
  exit(0);
}