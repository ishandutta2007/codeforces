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
  int mem;
  int id;
};
int compare_NODE_inc (const void * a_, const void * b_) {
  NODE *a = (NODE*)a_;
  NODE *b = (NODE*)b_;
  if(      a->mem > b->mem ) return  1;
  else if( a->mem < b->mem ) return -1;
  else return 0;
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, d, a, b;
  cin >> n >> d >> a >> b;
  NODE cli[n];
  for(int i = 0; i < n; i++){
    int e, f;
    cin >> e >> f;
    cli[i].id = i;
    cli[i].mem = a*e+b*f;
  }
  qsort(cli, n, sizeof(NODE), compare_NODE_inc);
  int served = 0;
  for(int i = 0; i < n; i++){
    if(d >= cli[i].mem){
      d -= cli[i].mem;
      served++;
    }
  }
  cout << served << endl;
  for(int i = 0; i < served; i++){
    cout << cli[i].id +1 << " ";
  }
  cout << endl;
  exit(0);
}