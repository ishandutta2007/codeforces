#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
struct NODE{
  int s;
  int e;
};
int compare_NODE_inc (const void * a, const void * b) {
  return ( (*(NODE*)a).s - (*(NODE*)b).s );
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a;
  scanf("%d", &a);
  NODE dates[a];
  for(int i = 0; i < a; i++){
    scanf("%d%d", &dates[i].s, &dates[i].e);
  }
  int number = 0;
  qsort(dates, a, sizeof(NODE), compare_NODE_inc);
  int max = 0;
  for(int i = 0; i < a; i++){
    if(dates[i].e < max){
      number++;
    } else {
      max = dates[i].e;
    }
  }
  cout << number << endl;
}