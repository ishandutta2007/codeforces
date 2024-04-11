#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Main();
#ifdef LOCAL
  cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

struct min_cost_max_flow {
  struct edge {
    int v, u, num, w, cost;
    edge(int v = -1, int u = -1, int num = -1, int w = 0, int cost = 0) :
      v(v), u(u), num(num), w(w), cost(cost)
    {}
  };

  const int INF = 1e9;
  int n, s, t, E = 0;
  vector<edge> edges;
  vector<int> flow, dist, parent;

  min_cost_max_flow() : n(0), s(0), t(0) {}

  void unite(int n_, int s_, int t_) {
    n = n_;
    s = s_;
    t = t_;
  }

  void add_edge(int v, int u, int w, int cost) {
    edges.push_back(edge(v, u, 2 * E, w, cost));
    edges.push_back(edge(u, v, 2 * E + 1, 0, -cost));
    flow.push_back(0);
    flow.push_back(0);
    E++;
  }

  void calc_dist() {
    dist.assign(n, INF);
    parent.assign(n, -1);
    dist[s] = 0;
    while (true) {
      bool any = false;
      for (auto [v, u, num, w, cost] : edges) {
        if (flow[num] < w && dist[v] != INF && dist[u] > dist[v] + cost) {
          dist[u] = dist[v] + cost;
          parent[u] = num;
          any = true;
        }
      }
      if (!any) {
        break;
      }
    }
  }

  int solve() {
    calc_dist();
    assert(dist[t] != INF);
    vector<int> path;
    int v = t;
    while (v != s) {
      path.push_back(parent[v]);
      v = edges[parent[v]].v;
    }
    for (auto num : path) {
      flow[num]++;
      flow[num ^ 1]--;
    }
    return dist[t];
  }

  int get_min_cost(int max_flow) {
    int ans = 0;
    for (int i = 0; i < max_flow; i++) {
      ans += solve();
    }
    return ans;
  }
};

int n, q;
vector<int> L, R;
min_cost_max_flow G;

void Main() {
  cin >> n >> q;
  L.assign(n, 0);
  R.assign(n, n - 1);
  for (int t = 0; t < q; t++) {
    int type, l, r, x;
    cin >> type >> l >> r >> x;
    l--, x--;
    for (int i = l; i < r; i++) {
      if (type == 1) {
        L[i] = max(L[i], x);
      } else {
        R[i] = min(R[i], x);
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (R[i] < L[i]) {
      ok = false;
    }
  }
  if (!ok) {
    cout << "-1\n";
    return;
  }
  G.unite(2 * n + 2, 0, 2 * n + 1);
  for (int i = 1; i <= n; i++) {
    G.add_edge(0, i, 1, 0);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = L[i - 1]; j <= R[i - 1]; j++) {
      G.add_edge(i, n + 1 + j, 1, 0);
    }
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    for (int j = 0; j < n; j++) {
      int cost = j * 2 + 1;
      G.add_edge(i, 2 * n + 1, 1, cost);
    }
  }
  cout << G.get_min_cost(n) << '\n';
}