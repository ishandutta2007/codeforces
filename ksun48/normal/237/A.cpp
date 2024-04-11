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
  int time[24*60];
  for(int i = 0; i < 24*60; i++){
    time[i] = 0;
  }
  for(int i = 0; i < n; i++){
    int h, m;
    cin >> h >> m;
    time[60*h+m]++;    
  }
  int a = 0;
  for(int i = 0; i < 24*60; i++){
    a = Max(a, time[i]);
  }
  cout << a << endl;
  exit(0);
}