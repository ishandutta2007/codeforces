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
  char str[300];
  cin >> str;
  int num1[n];
  int num2[n];
  for(int i = 0; i < n; i++){
    num1[i] = str[i] - '0';
    num2[i] = str[i+n]-'0';
  }
  qsort(num1, n, sizeof(int), compare_dec);
  qsort(num2, n, sizeof(int), compare_dec);
  int k = 1;
  for(int i = 0; i < n; i++){
    if(num1[i] <= num2[i]) k = 0;
  }
  if(k == 1){
    cout << "YES" << endl;
    exit(0);
  }
  k = 1;
  for(int i = 0; i < n; i++){
    if(num1[i] >= num2[i]) k = 0;
  }
  if(k == 1){
    cout << "YES" << endl;
    exit(0);
  }
  cout << "NO" << endl;
  exit(0);
}