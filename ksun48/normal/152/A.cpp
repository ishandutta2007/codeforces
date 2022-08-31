#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
char Max(char a, char b) {
  return (a > b ? a : b);
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m;
  cin >> n >> m;
  char str[n+1][m+1];
  int isbest[n];
  for(int i = 0; i < n; i++){
    cin >> str[i];
    isbest[i] = 0;
  }
  for(int i = 0; i < m; i++){
    int max = 0;
    for(int j = 0; j < n; j++){
      max = Max(max, str[j][i]);
    }
    for(int j = 0; j < n; j++){
      if(str[j][i] == max){
	isbest[j] = 1;
      }
    }
  }
  int numbest = 0;
  for(int i = 0; i < n; i++){
    numbest += isbest[i];
  }
  cout << numbest << endl;
  exit(0);
}