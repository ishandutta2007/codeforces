#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
int Min(int a, int b) {
  return (a < b ? a : b);
}
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int compare_dec (const void * a, const void * b) {
  return ( *(int*)b - *(int*)a );
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int nummoves = 1;
  int n;
  int score = 0;
  scanf("%d", &n);
  int a, b;
  int unused[n];
  int count = 0;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    if(b != 0){
      nummoves += (b - 1);
      score += a;
    } else {
      unused[count++] = a;
    }
  }
  qsort(unused, count, sizeof(int), compare_dec);
  for(int k = 0; k < Min(count, nummoves); k++){
    score += unused[k];
  }
  cout << score << endl;
}