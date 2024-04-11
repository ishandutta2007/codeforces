#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m;
  cin >> n >> m;
  char str[n][m+1];
  for(int i = 0; i < n; i++){
    cin >> str[i];
  }
  int letters[26][m];
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < m; j++){
      letters[i][j] = 0;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      letters[str[i][j]-'A'][j] = 1;
    }
  }
  int numletters[m];
  for(int i = 0; i < m; i++){
    numletters[i] = 0;
  }
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < m; j++){
      numletters[j] += letters[i][j];
    }
  }
  LL numways = 1;
  for(int i = 0; i < m; i++){
    numways *= (LL)numletters[i];
    numways = numways % 1000000007;
  }
  cout << numways << endl;
}