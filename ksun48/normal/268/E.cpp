#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#include <complex>
#include <deque>
#include <map>
#include <utility>
#include <limits>
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
struct NODE{
  double l;
  double p;  
};
int compare_NODE_dec (const void * a_, const void * b_) {
  NODE *a = (NODE*)a_;
  NODE *b = (NODE*)b_;
  if(a->p == 1 && b->p == 1) return 0;
  if(a->p == 1) return -1;
  if(b->p == 1) return 1;
  if( (a->l)*(a->p)/(1-(a->p)) > (b->l)*(b->p)/(1-(b->p))) return -1;
  if( (a->l)*(a->p)/(1-(a->p)) < (b->l)*(b->p)/(1-(b->p))) return 1;
  else return 0;
}
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  NODE nodes[n];
  double k = 0;
  for(int i = 0; i < n; i++){
    cin >> nodes[i].l >> nodes[i].p;
    nodes[i].p /= 100;
    k += nodes[i].l;
  }
  qsort(nodes, n, sizeof(NODE), compare_NODE_dec);
  double csum = 0;
  for(int i = n-1; i >= 0; i--){
    k += (nodes[i].l*nodes[i].p)*csum;
    csum += (1-nodes[i].p);
  }
  printf("%.10lf\n", k);
}