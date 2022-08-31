#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
vector < int > g[maxN];
int h[maxN];
void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) continue;
        h[to] = h[v] + 1;
        dfs(to, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, a, b;
        int da, db;
        cin >> n >> a >> b >> da >> db;
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        h[a] = 0;
        dfs(a, -1);
        int c = 1;
        for (int i = 1; i <= n; i++) {
            if (h[i] > h[c]) c = i;
        }
        if (h[b] <= da) {
            cout << "Alice\n";
            continue;
        }
        h[c] = 0;
        dfs(c, -1);
        c = 1;
        for (int i = 1; i <= n; i++) {
            if (h[i] > h[c]) c = i;
        }
        db = min(db, h[c]);
        da = min(da, h[c]);
        if (db <= 2 * da) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}