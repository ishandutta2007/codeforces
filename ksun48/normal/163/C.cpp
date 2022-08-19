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
double MOD(double n, double k){
  return n-k*(int(1.0*n/k));
}
struct NODE{
  double dist;
  int dc;
  int nc;
};
int compare_NODE_inc (const void * a_, const void * b_) {
  NODE *a = (NODE*)a_;
  NODE *b = (NODE*)b_;
  if(      a->dist > b->dist ) return  1;
  else if( a->dist < b->dist ) return -1;
  else return 0;
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  double l, v1, v2;
  cin >> n >> l >> v1 >> v2;
  double choc[n];
  double prob[n+1];
  for(int i = 0; i < n; i++){
    cin >> choc[i];
  }
  double t = (v2*l)/(v1+v2);
  NODE cc[2*n];
  for(int i = 0; i < n; i++){
    cc[i].dist = choc[i];
    cc[i].dc = -1;
  }
  for(int i = 0; i < n; i++){
    cc[i+n].dist = MOD(choc[i]+2*l-t, 2*l);
    if(cc[i+n].dist <=0) cc[i+n].dist += 2*l;
    cc[i+n].dc = 1;
  }
  qsort(cc, 2*n, sizeof(NODE), compare_NODE_inc);
  //int num = n;
  //for(int i = 0; i < n; i++){
  //  if(choc[i] > t){
  //    num = i;
  //    break;
  //  }
  //}
  //if(choc[0] == 0){
  //  num--;
  //}
  // num is num of choc from 0 to choc[0].dist inclusive
  int num = 0;
  for(int i=0; i<n; i++) {
    if(choc[i] <= t) num ++;
    else break;
  }
  if(DEBUG) {
    cout << "num= " << num << endl;
  }
  cc[0].nc = num;
  for(int i = 1; i < 2*n; i++){
    cc[i].nc = cc[i-1].nc + cc[i-1].dc;
  }
  if(DEBUG) {
    for(int i = 0; i < 2*n; i++){
      cout << "i= " << i << " cc dist= " << cc[i].dist << " nc= " << cc[i].nc << " dc= " << cc[i].dc << endl;
    }
  }
  //cout << "hmm\n";
  for(int i = 0; i <= n; i++){
    prob[i] = 0;
  }
  for(int i = 0; i < 2*n; i++){
    double a = MOD(cc[(i+1)%(2*n)].dist-cc[i].dist+2*l, 2*l);
    prob[cc[(i+1)%(2*n)].nc] += a/(2*l);
  }
  for(int i = 0; i <= n; i++){
    printf("%.20lf\n", prob[i]);
  }
}