#include <bits/stdc++.h>

using namespace std;

const int N = 300 * 1000 + 10;

struct BIT {
  vector<int> f;

  BIT(int n = 0) {
    f.assign(n, 0);
  }

  void upd(int at, int val) {
    for (; at < f.size(); at = (at | (at + 1)))
      f[at] = max(f[at], val);
  }

  int get(int at) {
    int res = 0;
    for (; at >= 0; at = (at & (at + 1)) - 1)
      res = max(res, f[at]);
    return res;
  }
};

BIT in[N];
vector<pair<int, int>> weightFrom[N];

struct edge {
  int from;
  int to;
  int w;

  edge(int f, int t, int ww): from(f), to(t), w(ww) {}

  bool operator < (const edge& e) const {
    return w < e.w || w == e.w && from < e.from;
  }
};

int main() {
  ios_base::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<edge> e;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    --a;
    --b;
    e.push_back(edge(a, b, w));
  }
  sort(e.begin(), e.end());
  for (edge ed : e) {
    int from = ed.from;
    int to = ed.to;
    int w = ed.w;
    weightFrom[to].push_back(pair<int, int>(w, from));
  }
  for (int i = 0; i < n; i++)
    in[i] = BIT(weightFrom[i].size());
  int res = 0;
  for (edge ed : e) {
    int from = ed.from;
    int to = ed.to;
    int w = ed.w;
    int posTo = lower_bound(weightFrom[to].begin(), weightFrom[to].end(), pair<int, int>(w, from)) - weightFrom[to].begin();
    int posFrom = upper_bound(weightFrom[from].begin(), weightFrom[from].end(), pair<int, int>(w, -1)) - weightFrom[from].begin();
    int old = in[from].get(posFrom - 1);
    res = max(res, old + 1);
    in[to].upd(posTo, old + 1);
  }
  cout << res;

  return 0;
}