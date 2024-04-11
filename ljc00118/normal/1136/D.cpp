#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

vector <int> adj[N];
int p[N], vis[N];
int n, m, big, ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vis[p[n]] = 1; big = 1;
    for (int i = n - 1; i >= 1; i--) {
        int u = p[i], cnt = 0;
        for (unsigned j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if(vis[v]) ++cnt;
        }
        if(cnt == big) ++ans;
        else vis[u] = 1, ++big;
    }
    cout << ans << endl;
    return 0;
}