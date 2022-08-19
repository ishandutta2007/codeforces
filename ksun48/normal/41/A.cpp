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
  char t[120];
  char s[120];
  cin >> t >> s;
  if(strlen(t) != strlen(s)){
    cout << "NO" << endl; exit(0);
  }
  int len = strlen(t);
  for(int i = 0; i < len; i++){
    if(t[i] != s[len-1-i]){
      cout << "NO" << endl; exit(0);
    }
  }
  cout << "YES" << endl; exit(0);
  exit(0);
}