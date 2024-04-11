#include<bits/stdc++.h>
namespace {
using namespace std;

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace atcoder;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
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
  struct S { int type, i, j; };
  vector<S> q(m);
  for(auto& [t, i, j]: q) cin >> t >> i >> j, i--, j--;
  dsu d(2 * n);
  for(auto [t, i, j]: q) {
    d.merge(i, j + n);
    d.merge(i + n, j);
  }
  bool ok = true;
  rep(i, n) if (d.same(i, i + n)) ok = false;
  if (!ok) {
    cout << "NO\n";
    return 0;
  }
  string ori(n, '.');
  for(const auto& g: d.groups()) {
    if (ori[g[0] % n] != '.') continue;
    for(int i: g) {
      if (i < n) ori[i] = 'L';
      else ori[i - n] = 'R';
    }
  }
  VVI to(n);
  for(auto [t, i, j]: q) {
    if (ori[i] == 'R') swap(i, j);
    if (t == 1) to[i].emplace_back(j);
    else to[j].emplace_back(i);
  }
  auto res = topological_sort(to);
  if (res.empty()) {
    cout << "NO\n";
    return 0;
  } else {
    VI pos(n);
    rep(i, n) pos[res[i]] = i;
    cout << "YES\n";
    rep(i, n) cout << ori[i] << ' ' << pos[i] << '\n';
  }
}