#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int n;
const int maxN = (int)1e5 + 100;
struct edge{
    int to, we, color;
    edge(int _to, int _we, int _color) : to(_to), we(_we), color(_color) {}
};
vector < edge > g[maxN];
bool used[maxN];
int sb[maxN];
int sz[maxN];
void start_dfs(int root, int p, vector < int >& all) {
    all.emplace_back(root);
    sz[root] = 1;
    sb[root] = 0;
    for (auto& ed : g[root]) {
        if (ed.to == p) continue;
        if (used[ed.to]) continue;
        start_dfs(ed.to, root, all);
        sz[root] += sz[ed.to];
        sb[root] = max(sb[root], sz[ed.to]);
    }
}
struct path{
    int bal1, bal2, prod;
    path(int _bal1, int _bal2, int _prod) : bal1(_bal1), bal2(_bal2), prod(_prod) {}
};
int ans = 1;
struct FenwickSize{
    vector < int > f;
    int n;
    FenwickSize (int _n) {
        n = _n;
        f.resize(n + 1);
    }
    void upd(int v, int d) {
        while (v <= n) {
            f[v] += d;
            v = (v | (v - 1)) + 1;
        }
    }
    int get(int r) {
        int tot = 0;
        while (r > 0) {
            tot += f[r];
            r &= (r - 1);
        }
        return tot;
    }
    int get(int l, int r) {
        if (r > n) r = n;
        return sub(get(r), get(l - 1));
    }
};
struct FenwickProd{
    vector < int > f;
    int n;
    FenwickProd (int _n) {
        n = _n;
        f.resize(n + 1, 1);
    }
    void upd(int v, int d) {
        while (v <= n) {
            f[v] = mult(f[v], d);
            v = (v | (v - 1)) + 1;
        }
    }
    int get(int r) {
        int tot = 1;
        while (r > 0) {
            tot = mult(tot, f[r]);
            r &= (r - 1);
        }
        return tot;
    }
    int get(int l, int r) {
        if (r > n) r = n;
        return mult(get(r), pw(get(l - 1), mod - 2));
    }
};
void calc_dfs(int v, int p, path hs, vector < path >& all) {
    all.push_back(hs);
    for (auto& ed : g[v]) {
        if (ed.to == p) continue;
        if (used[ed.to]) continue;
        auto new_hs = hs;
        new_hs.prod = mult(new_hs.prod, ed.we);
        if (ed.color == 0) {
            new_hs.bal1 += 2;
            new_hs.bal2 -= 1;
        }
        else {
            new_hs.bal1 -= 1;
            new_hs.bal2 += 2;
        }
        calc_dfs(ed.to, v, new_hs, all);
    }
}
void solve(int root) {
    vector < int > all_v;
    start_dfs(root, -1, all_v);
    int cen = -1;
    int n = all_v.size();
    for (int v : all_v) {
        if (2 * sb[v] <= n && 2 * (n - sz[v]) <= n) {
            cen = v;
            break;
        }
    }
    assert(cen != -1);
    FenwickSize fenwA(3 * n + 3), fenwB(3 * n + 3);
    FenwickProd fenwProdA(3 * n + 3), fenwProdB(3 * n + 3);
    for (auto& ed : g[cen]) {
        if (used[ed.to]) continue;
        vector < path > new_vec;
        path g = path(0, 0, ed.we);
        if (ed.color == 0) {
            g.bal1 = 2;
            g.bal2 = -1;
        }
        else {
            g.bal1 = -1;
            g.bal2 = 2;
        }
        calc_dfs(ed.to, cen, g, new_vec);
        int BAD = 1;
        for (auto& it : new_vec) {
            if (it.bal1 >= 0 && it.bal2 >= 0) ans = mult(ans, it.prod);
            int P1 = fenwProdA.get(it.bal1 + 2 * n);
            int P2 = fenwA.get(it.bal1 + 2 * n);
            int X = mult(P1, pw(it.prod, P2));
            ans = mult(ans, X);
            int C1 = fenwProdB.get(-it.bal2 + 2 * n - 1);
            int C2 = fenwB.get(-it.bal2 + 2 * n - 1);
            BAD = mult(BAD, mult(C1, pw(it.prod, C2)));
        }
        ans = mult(ans, pw(BAD, mod - 2));
        for (auto& it : new_vec) {
            fenwProdA.upd(-it.bal1 + 2 * n, it.prod);
            fenwA.upd(-it.bal1 + 2 * n, 1);
            fenwProdB.upd(it.bal2 + 2 * n, it.prod);
            fenwB.upd(it.bal2 + 2 * n, 1);
        }
    }
    used[cen] = true;
    for (auto& ed : g[cen]) {
        if (used[ed.to]) continue;
        solve(ed.to);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, we, color;
        cin >> u >> v >> we >> color;
        g[u].emplace_back(v, we, color);
        g[v].emplace_back(u, we, color);
    }
    solve(1);
    cout << ans;
    return 0;
}