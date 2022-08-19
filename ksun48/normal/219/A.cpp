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
int Max(int a, int b) {
  return (a > b ? a : b);
}

int compare_dec (const void * a, const void * b) {
  if ( *(int*)a < *(int*)b ) return 1;
  if ( *(int*)a > *(int*)b ) return -1;
  return 0;
}
main(int argc, char **argv) {
  int k;
  cin >> k;
  char str[1100];
  cin >> str;
  int len = strlen(str);
  int az[26];
  for(int i = 0; i < 26; i++) az[i] = 0;
  for(int i = 0; i < len; i++) az[str[i]-'a']++;
  for(int i = 0; i < 26; i++){
    if(az[i] % k != 0){
      cout << -1 << endl;
      exit(0);
    }
  }
  for(int i = 0; i < k; i++){
    for(int j = 0; j < 26; j++){
      for(int m = 0; m < az[j]/k; m++){
	char n = j+'a';
	cout << n;
      }
    }   
  }
  cout << endl;
  exit(0);
}