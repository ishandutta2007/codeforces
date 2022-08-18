#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <numeric>

using namespace std;

#define MAXN 110

int N;
int X[MAXN];
int Y[MAXN];
bool vis[MAXN];

void dfs(int x) {
  if(vis[x]) return;
  vis[x] = true;
  for(int i = 0; i < N; i++) {
    if(X[i] == X[x] || Y[i] == Y[x]) {
      dfs(i);
    }
  }
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    vis[i] = false;
    cin >> X[i] >> Y[i];
  }
  int cnt = -1;
  for(int i = 0; i < N; i++) {
    if(vis[i]) continue;
    dfs(i);
    ++cnt;
  }
  cout << cnt << endl;
  return 0;
}