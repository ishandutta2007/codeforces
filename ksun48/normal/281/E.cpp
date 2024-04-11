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
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  
  int n;
  cin >> n;
  vector<int> edges[n];
  for(int i = 1; i < n; i++){
    int a, b;
    cin >> a >> b;
    edges[a-1].push_back(b-1);
    edges[b-1].push_back(a-1);
  }
  int dist[n];
  for(int i = 0; i < n; i++) dist[i] = -1;
  dist[0] = 1;
  deque<int> search;
  search.push_back(0);
  while(!search.empty()){
    int k = *search.begin();
    search.pop_front();
    for(int i = 0; i < edges[k].size(); i++){
      if(dist[edges[k][i]] == -1){
	dist[edges[k][i]] = dist[k]+1;
	search.push_back(edges[k][i]);
      }
    }
  }
  double dist1[n];
  double sum = 0;  
  for(int i = 0; i < n; i++){
    dist1[i] = (double)dist[i];
    sum += 1.0/dist1[i];
  }
  printf("%.10f\n", sum);
  //cout << dist[0] << " " << dist[1] << endl;
}