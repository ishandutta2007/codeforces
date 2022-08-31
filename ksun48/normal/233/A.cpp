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
  if(n % 2 == 1){
    cout << -1 << endl;
    exit(0);
  } else {
    for(int i = 1; i <= n; i++){
      if(i % 2 == 1){
	cout << i + 1 << " ";
      } else {
	cout << i-1 << " ";
      }
    }
    cout << endl;
  }
  exit(0);
}