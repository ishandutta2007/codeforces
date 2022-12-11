#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, long long> > get_edges(long long u, long long v) {
  vector<pair<long long, long long> > result;

  while (u != v) {
    if (u > v) {
      swap(u, v);
    }

    result.push_back({v / 2, v});
    v /= 2;
  }

  return result;
}

map<pair<long long, long long>, long long> costs;

void solve() {
  int q; cin >> q;

  for (int i = 0; i < q; i++) {
    int tp; cin >> tp;

    if (tp == 1) {
      long long u, v;
      int w;

      cin >> u >> v >> w;

      auto edges = get_edges(u, v);

      for (auto& edge : edges) {
        costs[edge] += w;
      }
    } else {
      long long u, v;

      cin >> u >> v;

      auto edges = get_edges(u, v);
      long long answer = 0;

      for (auto& edge : edges) {
        answer += costs[edge];
      }

      cout << answer << "\n";
    }
  }

}

int main() {
  solve();

  return 0;
}