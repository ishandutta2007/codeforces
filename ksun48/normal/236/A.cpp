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
  char hello[100];
  cin >> hello;
  int len = strlen(hello);
  int letters[26];
  for(int i = 0; i < 26; i++){
    letters[i] = 0;
  }
  for(int i = 0; i < len; i++){
    letters[hello[i]-'a'] = 1;
  }
  int k = 0;
  for(int i = 0; i < 26; i++){
    if(letters[i] == 1){
      k++;
    }
  }
  if(k % 2 == 0){
    cout << "CHAT WITH HER!" << endl;
  } else {
    cout << "IGNORE HIM!" << endl;
  }
  exit(0);
}