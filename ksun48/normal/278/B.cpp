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
  int n;
  cin >> n;
  set<int> set1;
  char strings[n][25];
  for(int i = 0; i < n; i++){
    cin >> strings[i];
  }
  for(int i = 0; i < 26; i++){
    int yes = 1;
    for(int j = 0; j < n; j++){
      for(int k = 0; k < strlen(strings[j]); k++){
	if(strings[j][k] == (i+'a')){
	  yes = 0;
	}
      }
    }
    char hmm = 'a'+i;
    if(yes){
      cout << hmm << endl;
      exit(0);
    }
  }
  for(int i = 0; i < 26; i++){
    for(int m = 0; m < 26; m++){
      int yes = 1;
      for(int j = 0; j < n; j++){
	for(int k = 0; k < strlen(strings[j])-1; k++){
	  if(strings[j][k] == (i+'a') && strings[j][k+1] == (m+'a')){
	    yes = 0;
	  }
	}
      }
      char hmm = 'a'+i;
      char hmmm = 'a'+m;
      if(yes){
	cout << hmm << hmmm << endl;
	exit(0);
      }
     }
  }
  //cout << *lower_bound(set1.begin(), set1.end(), 0) << endl;
  exit(0);
}