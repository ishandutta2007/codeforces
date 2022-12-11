#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100100;

int a[MAX_N];
map<int, pair<long long, long long> > f[MAX_N];

vector<int> uncalculated_neighbors[MAX_N];
multiset<pair<long long, int>, greater<pair<long long, int> > > maximal_fs[MAX_N];
multiset<pair<long long, int>, greater<pair<long long, int> > > maximal_gs[MAX_N];

pair<int, int> edges[MAX_N];

pair<long long, long long> dfs(int v, int p) {
  auto it = f[v].find(p);
  if (it != f[v].end()) {
    return it->second;
  }

  int mem = -1;
  while (uncalculated_neighbors[v].size()) {
    int u = uncalculated_neighbors[v].back();
    uncalculated_neighbors[v].pop_back();
    if (u == p) {
      mem = u;
      continue;
    }

    auto q = dfs(u, v);
    maximal_fs[v].insert(make_pair(q.first, u));
    maximal_gs[v].insert(make_pair(q.second, u));
  }

  if (mem != -1) {
    uncalculated_neighbors[v].push_back(mem);
  }

  long long mx_f1 = 0ll;
  long long mx_f2 = 0ll;
  int counter = 0;
  for (auto q : maximal_fs[v]) {
    if (q.second == p) {
      continue;
    }
    if (counter == 0) {
      mx_f1 = q.first;
      counter = 1;
    } else {
      mx_f2 = q.first;
      break;
    }
  }

  long long mx_g = 0ll;
  for (auto q : maximal_gs[v]) {
    if (q.second == p) {
      continue;
    }

    mx_g = q.first;
    break;
  }

  long long f_value = mx_f1 + a[v];
  long long g_value = max(mx_f1 + mx_f2 + a[v], mx_g);

  return f[v][p] = make_pair(f_value, g_value);
} 

void solve() {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v; scanf("%d%d", &u, &v);
    uncalculated_neighbors[u].push_back(v);
    uncalculated_neighbors[v].push_back(u);

    edges[i] = make_pair(u, v);
  }

  long long answer = 0ll;
  for (int i = 1; i < n; i++) {
    auto p = dfs(edges[i].first, edges[i].second);
    auto q = dfs(edges[i].second, edges[i].first);

    answer = max(answer, p.second + q.second);
  }
  cout << answer << "\n";
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}