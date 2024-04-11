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
#include <time.h>
#include <limits>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
LL maxScore = numeric_limits<LL>::min();
//LL scores[35][35];
int n; int u; LL r;
LL a[35], b[35], q[35], p[35];
void scores(LL *curra){
  LL sum = 0;
  for(int i = 0; i < n; i++){
    sum += (q[i] * curra[i]);
  }
  if(sum > maxScore){
    maxScore = sum;
  }
}
double sum_clock = 0;
double sum_clock2 = 0;

void allFlip(int *flip, int u, int k, LL *curra) {
  if (u % 2 == k % 2) {
    scores(curra);
  }
  if (u == k) return;
  
  for (int i=0; i<2; i++) {
    flip[k]=i;
    if(k == 0 || flip[k] == 1 || flip[k-1] == 1) {
      LL saved_a[35];
      memcpy(saved_a, curra, sizeof(saved_a));
      if(flip[k] == 0){
	for(int j = 0; j < n; j++){
	  curra[j] = curra[j] ^ b[j];
	}
      } else {
	for(int j = 0; j < n; j++){
	  curra[j] = saved_a[p[j]]+r;
	}
      }
      allFlip(flip, u, k+1, curra);
      memcpy(curra, saved_a, sizeof(saved_a));
    }
  }
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  cin >> n >> u >> r;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }  for(int i = 0; i < n; i++){
    cin >> b[i];
  }  for(int i = 0; i < n; i++){
    cin >> q[i];
  }  for(int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  int ops[u];
  for(int i = 0; i < u; i++){
    ops[i] = 0;
  }
  // cout << "CLOCKS_PER_SEC= " << CLOCKS_PER_SEC << endl;

  double t1 = clock();

  allFlip(ops, u, 0, a);

  double t2 = clock();
  sum_clock2 += (t2-t1);  
  //cout << "sum_clock= " << sum_clock << endl;
  //cout << "sum_clock2= " << sum_clock2 << endl;

  cout << maxScore << endl;
}