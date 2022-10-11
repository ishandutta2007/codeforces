#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "/home/lesha/codes/Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

const int MOD = int(1e9) + 7;

struct DSU {
    vector<int> par;
    vector<int> sz;

    DSU() {}
    explicit DSU(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }

    inline int getPar(int v) {
        return par[v] == v ? v : par[v] = getPar(par[v]);
    }

    inline bool unite(int v, int u) {
        v = getPar(v);
        u = getPar(u);
        if (v == u) return false;
        if (sz[v] < sz[u]) swap(v, u);
        par[u] = v;
        sz[v] += sz[u];
        return true;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    swap(n, m);
    int ans = 1;
    vector<int> ord;
    DSU dsu(n);
    vector<int> used(n, 0);

    for (int id = 0; id < m; id++) {
        int k;
        cin >> k;
        if (k == 1) {
            int v;
            cin >> v;
            v--;
            v = dsu.getPar(v);
            if (used[v]) continue;
            ord.push_back(id);
            used[v] = 1;
            ans *= 2;
            if (ans >= MOD) ans -= MOD;
        } else if (k == 2) {
            int v, u;
            cin >> v >> u;
            v--, u--;
            v = dsu.getPar(v);
            u = dsu.getPar(u);
            dbg();

            if (v != u && used[u] + used[v] <= 1) {
                int final = used[u] || used[v];
                used[u] = used[v] = final;
                dsu.unite(v, u);
                ans *= 2;
                if (ans >= MOD) ans -= MOD;
                ord.push_back(id);
            }
        } else assert(false);
    }

    cout << ans << ' ' << len(ord) << '\n';
    for (auto x : ord) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}