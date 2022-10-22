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

std::vector<int> topological_sort(const std::vector<std::vector<int>>& graph) {
    // if the graph contains cycles or self-loops, returns empty vector
    const int n = graph.size();
    std::vector<int> indeg(n);
    for(int u = 0; u < n; u++) for(auto v: graph[u]) {
        indeg[v]++;
    }
    std::vector<int> todo; todo.reserve(n);
    for(int u = 0; u < n; u++) if (indeg[u] == 0) todo.push_back(u);
    std::vector<int> ret; ret.reserve(n);
    while(!todo.empty()) {
        int u = todo.back(); todo.pop_back();
        ret.push_back(u);
        for(auto v: graph[u]) {
            indeg[v]--;
            if (indeg[v] == 0) todo.push_back(v);
        }
    }
    if (int(ret.size()) != n) return {};
    return ret;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<P> edges(m);
  VI indeg(n), outdeg(n);
  for(auto& [u, v]: edges) cin >> u >> v, u--, v--, outdeg[u]++, indeg[v]++;
  VVI to(n);
  for(auto [u, v]: edges) if (outdeg[u] != 1 && indeg[v] != 1) {
    to[u].emplace_back(v);
  }
  auto ts = topological_sort(to);
  VI dp(n);
  for(int u: ts) {
    dp[u]++;
    for(int v: to[u]) chmax(dp[v], dp[u]);
  }
  int ans = *max_element(all(dp));
  cout << ans << '\n';
}