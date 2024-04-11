#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, u, a[N], b[N];
long long ans = 0, dp[N];
bool vis[N];
vector<int> tpo, adj[N], tot[N];

void topo_sort(int u) {
    vis[u] = true;
    for (int v : tot[u]) {
        if (!vis[v]) {
            topo_sort(v);
        }
    }
    tpo.push_back(u);
}

long long DFS(int u) {
    dp[u] = a[u];
    for (int v : adj[u]) {
        if (DFS(v) < 0) {
            tot[u].push_back(v);
        } else {
            tot[v].push_back(u);
        }
        dp[u] += max(0LL, dp[v]);
    }
    ans += dp[u];
    return dp[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] != -1) {
            adj[b[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == -1) {
            DFS(i);
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            topo_sort(i);
        }
    }
    reverse(tpo.begin(), tpo.end());
    for (int v : tpo) {
        cout << v << " ";
    }
}