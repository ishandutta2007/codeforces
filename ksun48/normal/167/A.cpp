#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <set>
#include <queue>
#include <complex>
#include <deque>
#include <map>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
struct NODE{
  double init;
  double v;
  double time;
};
int compare_NODE_inc (const void * a_, const void * b_) {
  NODE *a = (NODE*)a_;
  NODE *b = (NODE*)b_;
  if(      a->init > b->init ) return  1;
  else if( a->init < b->init ) return -1;
  else return 0;
}

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  double a, d;
  cin >> n >> a >> d;
  NODE troll[n];
  for(int i = 0; i < n; i++){
    cin >> troll[i].init >> troll[i].v;
    troll[i].time = troll[i].init;
  }
  qsort(troll, n, sizeof(NODE), compare_NODE_inc);
  for(int i = 0; i < n; i++){
    if(troll[i].v*troll[i].v/(2*a) >= d){
      troll[i].time += sqrt(2*d/a);
    } else {
      troll[i].time += (d/troll[i].v + troll[i].v/(2*a));
    }
  }
  printf("%.10g\n", troll[0].time);
  for(int i = 1; i < n; i++){
    if(troll[i].time < troll[i-1].time){
      troll[i].time = troll[i-1].time;
    }
    printf("%.10g\n", troll[i].time);
  }
}