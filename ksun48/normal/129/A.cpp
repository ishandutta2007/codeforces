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
  cin >> n;
  int c[n];
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> c[i];
    sum += c[i];
  }
  int a = 0;
  for(int i = 0; i < n; i++){
    if(c[i] % 2 == sum % 2){
      a++;
    }
  }
  cout << a << endl;
  exit(0);
}