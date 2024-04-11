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
void traverse2(vector<int> *edges, int *isconn, int start, int *f){
  isconn[start] = 1;
  for(int i = 0; i < edges[start].size(); i++){
    if(isconn[edges[start][i]] == 0){
      if(f[edges[start][i]] != 1){
	traverse2(edges, isconn, edges[start][i], f);
      } else {
	isconn[edges[start][i]] = 1;
      }
    }
  }
}
void traverse1(vector<int> *edges, int *isconn, int start, int *f){
  isconn[start] = 1;
  for(int i = 0; i < edges[start].size(); i++){
    if(isconn[edges[start][i]] == 0){
      //if(f[edges[start][i]] != 2){
	traverse1(edges, isconn, edges[start][i], f);
	//} else {
	//	isconn[edges[start][i]] = 1;
	//}
    }
  }
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m;
  cin >> n >> m;
  int f[n];
  for(int i = 0; i < n; i++){
    cin >> f[i];
  }
  int a[m];
  int b[m];
  for(int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vector<int> toedges[n];
  vector<int> fromedges[n];
  int from1[n];
  int to2[n];
  for(int i = 0; i < n; i++){
    from1[i] = 0;
    to2[i] = 0;
  }
  for(int i = 0; i < m; i++){
    fromedges[b[i]].push_back(a[i]);
    toedges[a[i]].push_back(b[i]);
  }
  for(int i = 0; i < n; i++){
    if(f[i] == 2){
      traverse2(fromedges, to2, i, f); 
    } else if (f[i] == 1){
      traverse1(toedges, from1, i, f);
    }
  }
  for(int i = 0; i < n; i++){
    //cout << to2[i] << from1[i] << endl;
    if(to2[i] && from1[i]){
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
}