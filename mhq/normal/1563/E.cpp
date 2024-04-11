#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1005;
ll a[maxN], b[maxN];
vector<int> g[maxN];
bool reach[maxN];
int prv[maxN];
vector<int> cycle;
void dfs(int v, int p, ll x) {
    if (!cycle.empty()) {
        return;
    }
    for (int to : g[v]) {
        if (to != p && !reach[v] && reach[to]) {
            int nto = v;
            while (!reach[nto]) {
                cycle.emplace_back(nto);
                nto = prv[nto];
            }
            return;
        }
        if (!reach[to] && to != p && a[to] < x) {
            if (prv[to] != -1) {
                int nto = to;
                while (!reach[nto]) {
                    cycle.emplace_back(nto);
                    nto = prv[nto];
                }
                nto = v;
                while (!reach[nto]) {
                    cycle.emplace_back(nto);
                    nto = prv[nto];
                }
                return;
            }
            prv[to] = v;
            dfs(to, v, x + b[to]);
        }
    }
}
bool check(ll x) {
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        reach[i] = false;
    }
    reach[1] = true;
    while (cnt < n) {
        cycle.clear();
        for (int i = 1; i <= n; i++) {
            prv[i] = -1;
        }
        for (int i = 1; i <= n; i++) {
            if (reach[i]) {
                dfs(i, -1, x);
            }
        }
        if (cycle.empty()) return false;
        vector<bool> z(n + 1);
        for (int c : cycle) {
            z[c] = true;
        }
        for (int i = 1; i <= n; i++) {
            if (z[i]) {
                assert(!reach[i]);
                reach[i] = true;
                cnt++;
                x += b[i];
            }
        }
    }
    return true;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int l = -1;
    int r = (int)1e9 + 15;
    while  (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << '\n';
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