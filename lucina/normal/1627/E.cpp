#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
const ll INF = 1e17;
const int nax = 1e6 + 10;
int n, m, k;
ll x[nax];
array <int, 5> a[nax];

void solve() {
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> x[i];

    vector < vector <int>> g(n + 10);
    vector < vector <ll>> c(n + 10);
    for (int i = 1 ; i <= k ; ++ i) {
        for (int j = 0 ; j < 5 ; ++ j)
            cin >> a[i][j];
        auto &[sx, sy, ex, ey, cst] = a[i];
        g[sx].push_back(sy);
        g[ex].push_back(ey);
    }
    g[1].push_back(1);
    g[n].push_back(m);
    for (int i = 1 ; i <= n ; ++ i) {
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
        c[i].resize(g[i].size(), INF);
    }
    c[1][0] = 0;
    sort(a + 1, a + 1 + k);

    auto refresh_cost = [&](int fl) -> void {
        vector <ll> &a = c[fl];
        vector <ll> b = a;
        int64_t cst = x[fl];
        ll cur_cost = INF;
        for (int i = 0 ; i < a.size() ; ++ i) {
            cur_cost = min(cur_cost, a[i]);
            b[i] = min(b[i], cur_cost);
            if (i + 1 < a.size()) {
                cur_cost += cst * (g[fl][i + 1] - g[fl][i]);
            }
        }
        cur_cost = INF;
        for (int i = int(a.size()) - 1 ; i >= 0 ; -- i) {
            cur_cost = min(cur_cost, a[i]);
            b[i] = min(b[i], cur_cost);
            if (i > 0) {
                cur_cost += cst * (g[fl][i] - g[fl][i - 1]);
            }
        }
        a.swap(b);
    };

    auto where = [&](int i, int j) -> int{
        return lower_bound(g[i].begin(), g[i].end(), j) - g[i].begin();
    };

    for (int s = 1 ; s <= k ;) {
        int ts = s;
        while (ts <= k && a[s][0] == a[ts][0]) ts += 1;
        int i = a[s][0];
        refresh_cost(i);
        for (int i = s ; i < ts ; ++ i) {
            auto &[sx, sy, ex, ey, cst] = a[i];
            int now = where(sx, sy);
            int64_t from_cost = c[sx][now];
            if (from_cost == INF) continue;
            int to = where(ex, ey);
            c[ex][to] = min(c[ex][to], from_cost - cst);
        }
        s = ts;
    }
    refresh_cost(n);
    if (c[n].back() == INF) {
        cout << "NO ESCAPE" << '\n';
        return;
    }
    cout << c[n].back() << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T --  ;) {
        solve();
    }
}