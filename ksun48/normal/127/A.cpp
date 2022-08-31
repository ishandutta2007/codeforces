#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>
#include <set>
#include <math.h>
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
  double k;
  cin >> n >> k;
  double x[n];
  double y[n];
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  double dist = 0;
  for(int i = 0; i < n-1; i++){
    dist += sqrt((x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]));
  }
  printf("%.10lf\n", dist*k/50);
  exit(0);
}