#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  VI p(n);
  rep(i, n) cin >> p[i], p[i]--;
  vector<vector<P>> to(n);
  vector<P> edges(m);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    to[u].emplace_back(v, i);
    to[v].emplace_back(u, i);
    edges[i] = {u, v};
  }
  vector<char> visited(n);
  VI depth(n);
  vector<P> par(n, P(-1, -1));
  auto dfs = [&](auto&& self, int u) -> void {
    visited[u] = true;
    for(auto [v, id]: to[u]) if (!visited[v]) {
      par[v] = {u, id};
      depth[v] = depth[u] + 1;
      self(self, v);
    }
  };
  rep(i, n) if (!visited[i]) {
    dfs(dfs, i);
  }
  VI pos(n);
  rep(i, n) pos[p[i]] = i;
  // move value from pos[v] -> v
  VVI vpath(n);
  vector<P> swapped_values(m);
  VI es1, es2;
  rep(v, n) {
    es1.clear();
    es2.clear();
    int p = pos[v];
    int q = v;
    while(depth[p] > depth[q]) {
      es1.emplace_back(par[p].second);
      swapped_values[par[p].second].first = v;
      p = par[p].first;
    }
    while(depth[q] > depth[p]) {
      es2.emplace_back(par[q].second);
      swapped_values[par[q].second].second = v;
      q = par[q].first;
    }
    while(p != q) {
      es1.emplace_back(par[p].second);
      swapped_values[par[p].second].first = v;
      p = par[p].first;
      es2.emplace_back(par[q].second);
      swapped_values[par[q].second].second = v;
      q = par[q].first;
    }
    // reversed order
    es2.insert(es2.end(), rall(es1));
    swap(vpath[v], es2);
  }
  VI ready(m);
  VI todo;
  rep(v, n) if (vpath[v].size()) {
    if (++ready[vpath[v].back()] == 2) {
      todo.emplace_back(vpath[v].back());
    }
  }
  VI ans;
  while(todo.size()) {
    int i = todo.back(); todo.pop_back();
    ans.emplace_back(i);
    for(int v: {swapped_values[i].first, swapped_values[i].second}) {
      vpath[v].pop_back();
      if (vpath[v].size()) {
        if (++ready[vpath[v].back()] == 2) {
          todo.emplace_back(vpath[v].back());
        }
      }
    }
  }
  assert((int)ans.size() == m);
  rep(i, m) cout << ans[i] + 1 << " \n"[i + 1 == m];
}