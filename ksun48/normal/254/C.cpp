#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#include <complex>
#include <deque>
#include <map>
#include <utility>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int Min(int a, int b) {
  return (a < b ? a : b);
}
int DEBUG = 0;
main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("input.txt", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("output.txt", "w", stdout);
  char str1[100001];
  char str2[100001];
  cin >> str1 >> str2;
  int len = strlen(str1);
  int freq1[26];
  int freq2[26];
  int minx[26];
  for(int i = 0; i < 26; i++){
    freq1[i] = 0;
    freq2[i] = 0;
  }
  for(int i = 0; i < len; i++){
    freq1[str1[i]-'A']++;
    freq2[str2[i]-'A']++;
  }
  int s = 0;  
  for(int i = 0; i < 26; i++){
    minx[i] = Min(freq1[i], freq2[i]);
    s += freq1[i]-minx[i];
  }
  cout << s << endl;
  for(int i = 0; i < len; i++){
    int k = 0;
    for(int j = 0; j < 26; j++){
      if(j == str1[i]-'A'){
	if(minx[j] > 0 && freq2[j] > 0 && freq1[j] > 0){
	  freq2[j]--;
	  freq1[j]--;
	  minx[j]--;
	  k = j;
	  break;
	}
      } else {
	if(freq2[j] > minx[j] && freq1[str1[i]-'A'] > minx[str1[i]-'A']){
	  k = j;
	  freq2[j]--;
	  freq1[str1[i]-'A']--;
	  break;
	}
      }
    }
    char c = k+'A';
    cout << c;
  }
  cout << endl;
}