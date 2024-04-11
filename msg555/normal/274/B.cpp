#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int A[100010];

vector<int> E[100010];

pair<long long, long long> solve(int u, int p) {
  pair<long long, long long> res;

  for(int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if(v == p) continue;

    pair<long long, long long> r2 = solve(v, u);
    res.first = max(res.first, r2.first);
    res.second = max(res.second, r2.second);
  }

  long long v = A[u] + res.first - res.second;
  if(v < 0) {
    res.first += -v;
  } else {
    res.second += v;
  }
  
  return res;
}

int main() {
  int N; cin >> N;
  for(int i = 0; i + 1 < N; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  pair<long long, long long> res = solve(0, -1);
  cout << res.first + res.second << endl;
  
  return 0;
}