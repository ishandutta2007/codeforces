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
struct LEM {
  double wgt;
  double sp;
  int id;
};
int compare_NODE_inc (const void * a_, const void * b_) {
  LEM *a = (LEM*)a_;
  LEM *b = (LEM*)b_;
  if(      a->wgt > b->wgt ) return  1;
  else if( a->wgt < b->wgt ) return -1;
  else if( a->sp > b->sp ) return  1;
  else if( a->sp < b->sp ) return -1;
  else return 0;
}

double min(double a, double b) {
  return (a < b ? a : b);
}
double max(double a, double b) {
  return (a > b ? a : b);
}
int DEBUG = 0;
int n, h, k;
LEM lem[100001];
double maxspeed = 0;
double minspeed = 8000000000000;
int check(double t, int c){
  int curledge = 1;
  for(int i = 0; i < n; i++){
    if(curledge <= k && curledge/lem[i].sp <= t){
      curledge++;
      if(c) cout << lem[i].id << " ";
    }
  }
  if(c) cout << endl;
  if(c) exit(0);
  if(curledge > k) return 1;
  return 0;
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  cin >> n >> k >> h;
  for(int i = 0; i < n; i++){
    cin >> lem[i].wgt;
    lem[i].id = i+1;
  }
  for(int i = 0; i < n; i++){
    cin >> lem[i].sp;
    maxspeed = max(maxspeed, lem[i].sp);
    minspeed = min(minspeed, lem[i].sp);
  }
  double mint = (double)(1.0/maxspeed);
  double maxt = (double)(k*1.0/minspeed);
  qsort(lem, n, sizeof(LEM), compare_NODE_inc);
  if(check(mint, 0)){
    check(mint, 1);
  }
  for(int iter = 0; iter <= 200; iter++){
    if(iter == 200){
      check(maxt, 1);
    } else {
      double midt = (mint+maxt)/2;
      if(check(midt, 0)){
	maxt = midt;
      } else {
	mint = midt;
      }
    }
  }
}