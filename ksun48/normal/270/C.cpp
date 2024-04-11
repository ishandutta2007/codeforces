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
  int size;
  int num;
};
int compare_NODE_inc (const void * a_, const void * b_) {
  NODE *a = (NODE*)a_;
  NODE *b = (NODE*)b_;
  if(      a->size > b->size ) return  1;
  else if( a->size < b->size ) return -1;
  else return 0;
}
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  NODE nodes[n];
  for(int i = 0; i < n; i++){
    cin >> nodes[i].size >> nodes[i].num;
  }
  qsort(nodes, n, sizeof(NODE), compare_NODE_inc);
  int c = 0;
  int numcur = 0;
  for(int i = 0; i < 1100000000; i++){
    int d = (numcur+3)/4;
    int a = 0;
    if(c < n && nodes[c].size == i){
      if(d <= nodes[c].num){
	numcur = nodes[c].num;
      } else {
	numcur = d;
      }
      c++;
      a = 1;
    } else {
      numcur = d;
    }
    //cout << i << " " << numcur << endl;
    if(numcur == 1 && c == n){
      if(a == 1 && nodes[c-1].num == 1){
	cout << i + 1 << endl;
      } else {
	cout << i << endl;
      }
      break;
    }
  }
}