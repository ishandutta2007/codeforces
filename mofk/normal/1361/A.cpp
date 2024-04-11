#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[500005];
vector <int> adj[500005];
int ord[500005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) cin >> a[i], ord[i] = i;

    sort(ord + 1, ord + n + 1, [](int x, int y) {return a[x] < a[y];});
    for (int i = 1; i <= n; ++i) {
        int u = ord[i];
        vector <bool> s(a[u], false);
        for (auto v: adj[u]) {
            if (a[v] == a[u]) return cout << -1 << endl, 0;
            if (a[v] > a[u]) continue;
            s[a[v]] = true;
        }
        for (int j = 1; j < a[u]; ++j) if (!s[j]) return cout << -1 << endl, 0;
    }
    for (int i = 1; i <= n; ++i) cout << ord[i] << ' '; cout << endl;
    return 0;
}