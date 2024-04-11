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
#include <vector>
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
struct EDGE{
  int v2;
  int len;
  int used;
  int num;
};
deque<int> search1;
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m;
  cin >> n >> m;
  int in[n];
  int tot[n];
  vector<EDGE> edges[n];
  for(int i = 0; i < n; i++) in[i] = tot[i] = 0;
  int e1[m];
  int e2[m];
  int len[m];
  int dir[m];
  map<pair<int,int>,int> edgemap;
  for(int i = 0; i < m; i++){
    cin >> e1[i] >> e2[i] >> len[i];
    e1[i]--; e2[i]--;
    tot[e1[i]] += len[i];
    tot[e2[i]] += len[i];
    edgemap[make_pair(e1[i],e2[i])] = edges[e1[i]].size();
    edgemap[make_pair(e2[i],e1[i])] = edges[e2[i]].size();
    EDGE tmp;
    tmp.v2 = e2[i];
    tmp.len = len[i];
    tmp.used = 0;
    tmp.num = i;
    edges[e1[i]].push_back(tmp);
    tmp.v2 = e1[i];
    edges[e2[i]].push_back(tmp);
  }
  search1.push_back(0);
  while(!search1.empty()){
    int a = search1.front();
    for(int i = 0; i < edges[a].size(); i++){
      if(edges[a][i].used == 0){
	edges[a][i].used = 1;
	int n1 = edges[a][i].num;
	int c;
	if(e1[n1] == a){
	  dir[n1] = 0;
	  c = e2[n1];
	} else {
	  dir[n1] = 1;
	  c = e1[n1];
	}
	edges[c][edgemap[make_pair(c,a)]].used = 1;
	in[c] += edges[a][i].len;
	if(in[c] == tot[c]/2 && c != n-1){
	  search1.push_back(c);
	}
      }
    }
    search1.pop_front();
  }
  for(int i = 0; i < m; i++){
    cout << dir[i] << endl;
  }
}

/*

g++ 270E.cpp -o a.out; cat 270E.in | ./a.out 1

*/