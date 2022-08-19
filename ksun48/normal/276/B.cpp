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
#include <limits>
#include <vector>
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  char str[10000];
  cin >> str;
  int len = strlen(str);
  int freq[26];
  for(int i = 0; i < 26; i++) freq[i] = 0;
  for(int i = 0; i < len; i++){
    freq[str[i]-'a']++;
  }
  if(len % 2 == 1){
    cout << "First" << endl;
    exit(0);
  } else {
    int k = 0;
    for(int i = 0; i < 26; i++){
      if(freq[i] % 2 == 1){
	k++;
	//cout << i << endl;
      }
    }
    if(k <= 1){
      cout << "First" << endl;
      exit(0);
    } else {
      cout << "Second" << endl;
      exit(0);
    }
  }
}