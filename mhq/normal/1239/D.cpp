#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e6 + 100;
vector < int > g[maxN], gr[maxN];
int n, m;
bool used[maxN];
int comp[maxN];
vector < int > order;
void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

vector < int > comps;
void dfs2 (int v) {
    used[v] = true;
    comps.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        gr[i].clear();
        used[i] = false;
        comp[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    order.clear();
    for (int i = 1; i <= n; i++) {
        if (!used[i]) dfs1(i);
    }
    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }
    reverse(order.begin(), order.end());
    for (int v : order) {
        if (!used[v]) {
            comps.clear();
            dfs2(v);
        }
    }
    if (comps.size() == n) {
        cout << "No" << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }
    for (int v : comps) used[v] = true;
    cout << "Yes" << '\n';
    cout << comps.size() << " " << n - comps.size() << '\n';
    for (int v : comps) cout << v << " ";
    cout << '\n';
    for (int v = 1; v <= n; v++) if (!used[v]) cout << v << " ";
    cout << '\n';

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