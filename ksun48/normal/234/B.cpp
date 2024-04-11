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
struct NODE{
  int id;
  int time;
};

int compare_NODE_dec (const void * a_, const void * b_) {
  NODE *a = (NODE*)a_;
  NODE *b = (NODE*)b_;
  if(      a->time < b->time ) return  1;
  else if( a->time > b->time ) return -1;
  else if( a->id < b->id ) return  1;
  else if( a->id > b->id ) return -1;
  else return 0;
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("input.txt", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("output.txt", "w", stdout);
  int n, k;
  cin >> n >> k;
  NODE stuff[n];
  for(int i = 0; i < n; i++){
    stuff[i].id = i;
    cin >> stuff[i].time;
  }
  qsort(stuff, n, sizeof(NODE), compare_NODE_dec);
  cout << stuff[k-1].time << endl;
  for(int i = 0; i < k; i++){
    cout << stuff[i].id+1 << " ";
  }
  cout << endl;
}