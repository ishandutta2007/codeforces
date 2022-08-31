#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 10;
int inv[maxN];
int cur_sum[maxN];
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int lp[maxN];
vector<pair<int,pair<int,int>>> g[maxN];
int mx[maxN];
int coef[maxN];
void add(int x, int d, bool calc=false) {
    while (x > 1) {
        int p = lp[x];
        while (x % p == 0) {
            x /= p;
            cur_sum[p] += d;
        }
//        assert(1 <= p && p <= n);
        if (calc) {
            mx[p] = max(mx[p], cur_sum[p]);
        }
    }
}
void dfs(int v, int p) {
    for (auto& it : g[v]) {
        int u = it.first;
        int x = it.second.first;
        int y = it.second.second;
        if (u == p) continue;
        coef[u] = coef[v];
        coef[u] = mult(coef[u], y);
        coef[u] = mult(coef[u], inv[x]);
        add(y, -1);
        add(x, +1, true);
        dfs(u, v);
        add(y, +1);
        add(x, -1);
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
    }
    for (int i = 1; i <= n; i++) lp[i] = 0;
    for (int i = 2; i <= n; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            for (int j = 2 * i; j <= n; j += i) lp[j] = i;
        }
    }
    for (int it = 1; it < n; it++) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        g[i].emplace_back(j, make_pair(x, y));
        g[j].emplace_back(i, make_pair(y, x));
    }
    coef[1] = 1;
    for (int i = 1; i <= n; i++) {
        cur_sum[i] = 0;
        mx[i] = 0;
    }
    dfs(1, -1);
    int he = 1;
    for (int i = 1; i <= n; i++) {
        if (mx[i] > 0) {
            for (int z = 1; z <= mx[i]; z++) {
                he = mult(he, i);
            }
        }
    }
//    cout << he << endl;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = sum(ans, mult(he, coef[i]));
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }

    return 0;
}