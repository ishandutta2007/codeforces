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
  int a, amazing = 0;
  scanf("%d", &a);
  int b;
  cin >> b;
  int max = b; int min = b;
  for(int i = 1; i < a; i++){
    cin >> b;
    if(b > max){
      amazing ++;
      max = b;
    } else if(b < min){
      amazing ++;
      min = b;
    }
  }
  cout << amazing << endl;
}