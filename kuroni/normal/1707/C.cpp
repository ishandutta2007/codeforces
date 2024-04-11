#include <bits/stdc++.h>

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

using namespace std;
using namespace atcoder;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<bool> ans(n);
    dsu dsu(n);

    // graph stuff
    vector<vector<int>> adj(n), par(n);
    vector<int> in(n), out(n), h(n), coef(n);
    vector<pair<int, int>> bad;
    int pos = 0, cur = 0;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if (dsu.same(u, v)) {
            bad.push_back({u, v});
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
            dsu.merge(u, v);
        }
    }
    function<void(int, int)> DFS = [&](int u, int p) {
        if (par[u].empty()) {
            h[u] = (p == -1 ? 1 : h[p] + 1);
            par[u].resize(__lg(h[u]) + 1); par[u][0] = p;
            for (int i = 1; (1 << i) <= h[u]; i++) {
                par[u][i] = par[par[u][i - 1]][i - 1];
            }
        }
        in[u] = pos++;
        cur += coef[u];
        ans[u] = cur == 0;
        for (int v : adj[u]) {
            if (v != p) {
                DFS(v, u);
            }
        }
        cur -= coef[u];
        out[u] = pos;
    };
    DFS(0, -1);
    for (int i = 0; i < bad.size(); i++) {
        auto [u, v] = bad[i];
        if (h[u] > h[v]) {
            swap(u, v);
        }
        if (in[u] <= in[v] && out[u] >= out[v]) {
            int up = h[v] - h[u] - 1; u = v;
            for (int i = 0; up; i++) {
                if (up >> i & 1) {
                    up -= (1 << i);
                    u = par[u][i];
                }
            }
            coef[u]++; coef[v]--;
        } else {
            coef[0]++;
            coef[u]--; coef[v]--;
        }
    };
    DFS(0, -1);
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
}