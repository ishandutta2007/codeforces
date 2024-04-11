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

struct Tree {
  unordered_map<int, int> cnt;
  int max_cnt, where_max;

  Tree() : max_cnt(0), where_max(-1) {}

  inline void update(int pos, int delta) {
    cnt[pos] += delta;
    int cur_cnt = cnt[pos];
    if (cur_cnt > max_cnt || (cur_cnt == max_cnt && where_max > pos)) {
      where_max = pos;
      max_cnt = cur_cnt;
    }
  }
};

int n;
vector<vector<int>> G;
vector<int> dep, ans;
vector<Tree> ver;

void dfs(int v, int pr) {
  ver[v].update(dep[v], 1);
  for (auto u : G[v]) {
    if (u != pr) {
      dep[u] = dep[v] + 1;
      dfs(u, v);
      if (ver[v].cnt.size() < ver[u].cnt.size()) {
        swap(ver[v], ver[u]);
      }
      for (auto [pos, cnt] : ver[u].cnt) {
        ver[v].update(pos, cnt);
      }
    }
  }
  ans[v] = ver[v].where_max - dep[v];
}

void Main() {
  cin >> n;
  G.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    G[v].push_back(u);
    G[u].push_back(v);
  }
  dep.assign(n, 0);
  ans.assign(n, -1);
  ver.resize(n);
  dfs(0, 0);
  for (auto el : ans) {
    cout << el << '\n';
  }
}