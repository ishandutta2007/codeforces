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
  for(int i = 0; i <= n; i++){
    for(int j = 0; j < n-i; j++){
      cout << " " << " ";
    }
    for(int j = 0; j <= i; j++){
      cout << j;
      if(i != 0 || j != 0){
	cout << " ";
      }
    }
    for(int j = i-1; j >= 0; j--){
      cout << j;
      if( j > 0){
	cout << " ";
      }
    }
    cout << endl;
  }
  for(int i = n-1; i >= 0; i--){
    for(int j = 0; j < n-i; j++){
      cout << " " << " ";
    }
    for(int j = 0; j <= i; j++){
      cout << j;
      if(i != 0 || j != 0){
	cout << " ";
      }
    }
    for(int j = i-1; j >= 0; j--){
      cout << j;
      if( j > 0){
	cout << " ";
      }
    }
    cout << endl;
  }
  exit(0);
}