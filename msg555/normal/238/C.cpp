#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

vector<pair<int, int> > E[3010];
map<int, int> memo[3010][2];

int solve(int u, int p, bool up) {
  int& ref = memo[u][up][p];
  if(ref) return ref - 1;

  int base = 0;
  for(int i = 0; i < E[u].size(); i++) {
    int v = E[u][i].first;
    if(v == p) continue;
    base += solve(v, u, true) + !E[u][i].second;
  }

  ref = base;
  if(!up) {
    for(int i = 0; i < E[u].size(); i++) {
      int v = E[u][i].first;
      if(v == p) continue;
      ref = min(ref, base - (solve(v, u, true) + !E[u][i].second) +
                            (solve(v, u, false) + E[u][i].second));
    }
  }

  return ref++;
}

int main() {
  int N; cin >> N;
  for(int i = 1; i < N; i++) {
    int u, v; cin >> u >> v; u--; v--;
    E[u].push_back(make_pair(v, true));
    E[v].push_back(make_pair(u, false));
  }
  int res = N == 1 ? 0 : 0x7FFFFFFF;
  for(int u = 0; u < N; u++) {
    for(int j = 0; j < E[u].size(); j++) {
      int v = E[u][j].first;
      res = min(res, solve(u, v, false) + solve(v, u, false));
    }
  }
  cout << res << endl;
}