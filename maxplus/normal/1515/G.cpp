#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <memory.h>

using namespace std;

constexpr int N = 2e5;

vector<pair<int, int>> nei[N], rnei[N];
vector<int> ts;
int tag[N];

void build_ts(int u) {
  tag[u] = 1;
  for (auto [v, c]: nei[u]) if (!tag[v]) {
    build_ts(v);
  }
  ts.push_back(u);
}

int64_t d[N], g[N];

void calc_gcd(int comp, int u, int64_t dist) {
  tag[u] = comp;
  d[u] = dist;
  for (auto [v, c]: rnei[u]) {
    if (tag[v] == -1) {
      calc_gcd(comp, v, dist + c);
    } else if (tag[v] == comp) {
      g[comp] = gcd(g[comp], dist + c - d[v]);
    }
  }
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v, c;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    nei[--u].emplace_back(--v, c);
    rnei[v].emplace_back(u, c);
  }
  for (int i = 0; i < n; ++i) if (!tag[i]) {
    build_ts(i);
  }
  reverse(ts.begin(), ts.end());
  memset(tag, -1, sizeof tag);
  for (auto i: ts) if (tag[i] == -1) {
    calc_gcd(i, i, 0);
  }
  cin >> c;
  while (c--) {
    cin >> u >> v >> m;
    if (v % gcd(g[tag[u - 1]], m)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}