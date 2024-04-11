#include<bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>


#include <algorithm>
#include <utility>
#include <vector>


#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {
namespace internal {

struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    explicit scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder

using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
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

std::vector<std::vector<int>> scc_dag(std::vector<std::vector<int>>& scc, std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    int m = scc.size();
    std::vector<int> d(n);
    for(int i = 0; i < m; ++i) for(int v: scc[i]) d[v] = i;
    std::vector<std::vector<int>> to(m);
    std::vector<int> added(m, -1);
    for(int i = 0; i < m; ++i) {
        added[i] = i;
        for(int u: scc[i]) for(int x: graph[u]) {
            int v = d[x];
            if (added[v] != i) {
                added[v] = i;
                to[i].push_back(v);
            }
        }
    }
    return to;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        VVI to(n);
        scc_graph g(n);
        vector<bool> has_self_loop(n);
        rep(i, m) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            if (a == b) has_self_loop[a] = true;
            else {
                to[a].push_back(b);
                g.add_edge(a, b);
            }
        }
        auto scc = g.scc();
        int sz = scc.size();
        VVI to2 = scc_dag(scc, to);
        VI dp(sz, 0);
        rep(i, sz) {
            if (dp[i] == 0) {
                bool found = false;
                for(int u: scc[i]) if (u == 0) {
                    found = true;
                    break;
                }
                if (found) dp[i] = scc[i].size() == 1 ? 1 : -1;
            }
            if (dp[i] == 0) continue;
            for(int u: scc[i]) if (has_self_loop[u]) {
                dp[i] = -1;
                break;
            }
            if (scc[i].size() > 1) dp[i] = -1;
            if (dp[i] == -1) {
                for(int v: to2[i]) dp[v] = -1;
            } else if (dp[i] == 1) {
                for(int v: to2[i]) {
                    if (dp[v] < 0) continue;
                    dp[v] = min(2, dp[v] + 1);
                }
            } else {
                for(int v: to2[i]) {
                    if (dp[v] < 0) continue;
                    dp[v] = 2;
                }
            }
        }
        VI ans(n);
        rep(i, sz) {
            const int x = dp[i];
            for(int u: scc[i]) ans[u] = x;
        }
        rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
    }
}