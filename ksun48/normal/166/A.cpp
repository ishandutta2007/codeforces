#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
//#include <multiset>
#include <queue>
#include <complex>
#include <deque>
#include <map>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
struct NODE{
  int p;
  int t;
};
int compare_NODE_comb (const void * a, const void * b) {
  NODE *x = (NODE*)a;
  NODE *y = (NODE*)b;
  if(      x->p < y->p ) return  1;
  else if( x->p > y->p ) return -1;
  else if( x->t > y->t ) return  1;
  else if( x->t < y->t ) return -1;
  else return 0;
}

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, k;
  cin >> n >> k;
  k--;
  NODE teams[n];
  for(int i = 0; i < n; i++){
    cin >> teams[i].p >> teams[i].t;
  }
  qsort(teams, n, sizeof(NODE), compare_NODE_comb);
  for(int i = 0; i < n; i++){
    //cout << teams[i].p << " " << teams[i].t << endl;
  }
  int dest = teams[k].t;
  int desp = teams[k].p;
  int num = 0;
  for(int i = 0; i < n; i++){
    if(dest == teams[i].t && desp == teams[i].p){
      num++;
      //cout << i << endl;
    }
  }
  cout << num << endl;
}