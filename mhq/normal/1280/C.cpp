#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int k;
const int maxN = 2 * (int)1e5 + 100;
vector < pair < int, int > > g[maxN];
int n;
ll h[maxN];
ll A = 0;
ll B = 0;
int sz[maxN];
ll add[maxN];
void dfs(int u, int p) {
    sz[u] = 1;
    for (auto it : g[u]) {
        if (it.first == p) continue;
        h[it.first] = h[u] + it.second;
        dfs(it.first, u);
        sz[u] += sz[it.first];
        add[it.first] = it.second;
    }
}
void solve() {
    A = B = 0;
    cin >> k;
    n = 2 * k;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    h[1] = 0;
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        if (sz[i] & 1) A += add[i];
    }
    int c = -1;
    for (int i = 1; i <= n; i++) {
        if (sz[i] < n / 2) continue;
        bool ok = true;
        for (auto it : g[i]) {
            if (sz[i] > sz[it.first] && sz[it.first] > n / 2) ok = false;
        }
        if (ok) {
            c = i;
            break;
        }
    }
    assert(c != -1);
    h[c] = 0;
    dfs(c, -1);
    for (int i = 1; i <= n; i++) {
        B += h[i];
    }
    cout << A << " " << B << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}