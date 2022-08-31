#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <complex>
#include <deque>
#include <map>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a;
  scanf("%d", &a);
  char charz[a][30];
  for(int i = 0; i < a; i++){
    cin >> charz[i];
  }
  int num = 0;
  int k = strlen(charz[0]);
  for(int i = 0; i < k; i++){
    for(int j = 1; j < a; j++){
      if(charz[j][i] != charz[0][i]){
	cout << num << endl;
	exit(0);
      }
    }
    num++;
  }
  cout << num << endl;
  exit(0);
}