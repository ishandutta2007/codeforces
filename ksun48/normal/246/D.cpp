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

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, k;
  cin >> n >> k;
  int colors[n];
  set<int> colorset;
  for(int i = 0; i < n; i++){
    cin >> colors[i];
    colorset.insert(colors[i]);
  }
  int z = colorset.size();
  int c[z];
  map<int, int> m;
  for(int i = 0; i < z; i++){
    c[i] = *colorset.begin();
    m[c[i]] = i;
    colorset.erase(colorset.begin());
  }
  set<int> edge[z];
  for(int i = 0; i < k; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    if(colors[a] != colors[b]){
      edge[m[colors[a]]].insert(m[colors[b]]);
      edge[m[colors[b]]].insert(m[colors[a]]);
    }
  }
  int maxv = -1;
  int maxn = -1;
  for(int i = 0; i < z; i++){
    //cout << "i=" << i << " " << edge[i].size() << endl;
  }
  //cout << endl;
  for(int i = 0; i < z; i++){
    //cout << "i= " << i << " size()= " << edge[i].size() << " " << maxv << endl;
    if( int(edge[i].size()) > int(maxv)) {
      maxv = edge[i].size();
      maxn = i;
      //cout << "i= " << i << endl;
    }
  }
  //cout << maxn << endl;
  cout << c[maxn] << endl;
}