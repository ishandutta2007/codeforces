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
  int k, n;
  scanf("%d%d", &n, &k);
  int scores[n];
  for(int i = 0; i < n; i++){
    cin >> scores[i];
  }
  int num = 0;
  for(int i = 0; i < n; i++){
    if(scores[i] >= scores[k-1] && scores[i] > 0){
      num++;
    }
  }
  cout << num << endl;
}