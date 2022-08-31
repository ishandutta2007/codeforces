#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5 + 10;
vector<int> g[maxN];
const int LOG = 20;
struct Path {
    int l = -1, e1 = -1, e2 = -1;
};
int up[maxN][LOG];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        vector<int> tin(n), tout(n);
        vector<int> sz(n);
        vector<int> h(n);
        int tiempo = 0;
        function<void(int, int)> dfs = [&](int v, int p) {
            tin[v] = tiempo++;
            up[v][0] = p;
            sz[v] = 1;
            for (int i = 1; i < LOG; ++i) {
                up[v][i] = up[up[v][i-1]][i-1];
            }
            for (int to : g[v]) {
                if (to == p) continue;
                h[to] = h[v] + 1;
                dfs(to, v);
                sz[v] += sz[to];
            }
            tout[v] = tiempo++;
        };
        dfs(0, 0);
        auto upper = [&](int a, int b) {
            return tin[a] <= tin[b] && tout[b] <= tout[a];
        };

    // --- //
        auto lca = [&](int a, int b) {
            if (upper(a, b)) return a;
            if (upper(b, a)) return b;
            for (int l = LOG-1; l >= 0; --l) {
            if (!upper(up[a][l], b)) {
                    a = up[a][l];
                }
            }
            return up[a][0];
        };
        auto upd = [&](Path &p, int v) -> bool {
        if (p.l < 0) {
            p.l = p.e1 = v;
            return true;
        }
        if (p.e2 < 0) {
            if (upper(v, p.l)) {
                p.l = v;
                return true;
            }
            if (upper(p.e1, v)) {
                p.e1 = v;
                return true;
            }
            if (upper(v, p.e1)) return true;
            int l = lca(v, p.e1);
            if (!upper(l, p.l)) return false;
            p.l = l;
            p.e2 = v;
            return true;
        }
        if (p.l != v && upper(v, p.l)) {
            return false;
        }
        if (upper(p.e1, v)) {
            p.e1 = v;
            return true;
        }
        if (upper(p.e2, v)) {
            p.e2 = v;
            return true;
        }
        return upper(v, p.e1) || upper(v, p.e2);
    };
        vector<Path> paths;
        vector<ll> ans(n + 1);
        ans[0] = (1LL * n * (n - 1)) / 2;
        paths.emplace_back();
        for (int i = 0; i < n; i++) {
            Path pp = paths.back();
            if (!upd(pp, i)) {
                break;
            }
            if (i == 0) {
                ll tot = (1LL * n * (n - 1)) / 2;
                for (auto& it : g[0]) {
                    tot -= (1LL * sz[it] * (sz[it] - 1)) / 2;
                }
                ans[1] = tot;

            paths.push_back(pp);
                continue;
            }

            paths.push_back(pp);

            int c1 = pp.e1;
            int c2 = pp.e2;
            if (c1 == -1) c1 = pp.l;
            if (c2 == -1) c2 = pp.l;
            if (upper(c2, c1)) swap(c1, c2);
            if (upper(c1, c2)) {
                int D = h[c2] - h[c1] - 1;
                int p = c2;
                for (int k = 0; k < LOG; k++) {
                    if (D & (1 << k)) p = up[p][k];
                }
            //    cout << c2 << " " << p << " hihi " << c1 << endl;
                ans[i + 1] = (1LL * sz[c2] * (sz[c1] - sz[p]));
            }
            else {
                ans[i + 1] = 1LL * sz[c1] * sz[c2];
            }
        }
   //     for (ll& v : ans) cout << v << " ";
    //    cout << endl;
        for (int i = 0; i < n; i++) {
            ans[i] -= ans[i + 1];
        }
        for (int i = 0; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}