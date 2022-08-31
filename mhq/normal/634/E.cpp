#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = 3 * (int)1e5 + 100;
int par[maxN];
vector < int > g[maxN];
int a[maxN];
void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) continue;
        par[to] = v;
        dfs(to, v);
    }
}
int b[maxN];
int dp[maxN];
bool is_good[maxN];
void go(int v, int p) {
    is_good[v] = true;
    dp[v] = 0;
    int mx = 0;
    for (int to : g[v]) {
        if (to == p) continue;
        go(to, v);
        is_good[v] &= is_good[to];
        if (is_good[to]) dp[v] += dp[to];
        else {
            mx = max(mx, dp[to]);
        }
    }
    if (b[v] == 0) {
        dp[v] = 0;
        is_good[v] = false;
        return;
    }
    dp[v] += (1 + mx);
}
int f[maxN];
bool all_f[maxN];
pair < pair < int, int > , bool > unite(pair < pair < int, int >, bool > a, pair < pair < int, int >, bool > b) {
    pair < pair < int, int >, bool > t;
    t.second = b.second & a.second;
    t.first = make_pair(a.first.first + b.first.first, max(a.first.second, b.first.second));
    return t;
}
void calc_up(int v, int p) {
    vector < int > sons;
    for (int to : g[v]) {
        if (to == p) continue;
        sons.push_back(to);
    }
    if (b[v] == 0) {
        for (int to : sons) {
            f[to] = 0;
            all_f[to] = false;
        }
    }
    else {
        vector < pair < pair < int, int >, bool > > pref(sons.size() + 1), suf(sons.size() + 1);
        pref[0] = make_pair(make_pair(0, 0), true);
        for (int i = 1; i <= sons.size(); i++) {
            pair < pair < int, int >, bool > t;
            if (is_good[sons[i - 1]]) t.first.first = dp[sons[i - 1]];
            else t.first.second = dp[sons[i - 1]];
            t.second = is_good[sons[i - 1]];
            pref[i] = unite(pref[i - 1], t);
        }
        suf[sons.size()] = make_pair(make_pair(0, 0), true);
        for (int i = (int)sons.size() - 1; i >= 0; i--) {
            pair < pair < int, int >, bool > t;
            if (is_good[sons[i]]) t.first.first = dp[sons[i]];
            else t.first.second = dp[sons[i]];
            t.second = is_good[sons[i]];
            suf[i] = unite(suf[i + 1], t);
        }
        for (int i = 0; i < sons.size(); i++) {
            pair < pair < int, int >, bool > t;
            t.second = all_f[v];
            if (t.second) t.first.first = f[v];
            else t.first.second = f[v];
            auto nt = unite(t, unite(pref[i], suf[i + 1]));
            nt.first.first += 1;
            f[sons[i]] = nt.first.first + nt.first.second;
            all_f[sons[i]] = nt.second;
        }
    }
    for (int to : sons) {
        calc_up(to, v);
    }

}
bool ok(int x) {
    for (int i = 1; i <= n; i++) {
        b[i] = (a[i] >= x);
        f[i] = all_f[i] = dp[i] = is_good[i] = 0;
    }
    f[1] = 0;
    all_f[1] = true;
    go(1, -1);
    calc_up(1, -1);
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) continue;
        int s;
        if (all_f[i] || is_good[i]) s = f[i] + dp[i];
        else s = max(f[i], dp[i]);
        if (s >= k) return true;
    }
    return false;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    int l = 0;
    int r = 1000 * 10000 + 10;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ok(mid)) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}