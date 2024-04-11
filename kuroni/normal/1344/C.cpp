#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, u, v, ans = 0, dp[N][2], vis[N];
vector<int> st, adj[N][2];

void DFS(int u) {
    vis[u] = 1;
    for (int &v : adj[u][0]) {
        if (vis[v] == 1) {
            cout << -1;
            exit(0);
        } else if (vis[v] == 0) {
            DFS(v);
        }
    }
    st.push_back(u);
    vis[u] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        adj[u][0].push_back(v);
        adj[v][1].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = i;
        if (vis[i] == 0) {
            DFS(i);
        }
    }
    for (int j = 0; j < 2; j++) {
        reverse(st.begin(), st.end());
        for (int &u : st) {
            for (int &v : adj[u][j]) {
                dp[v][j] = min(dp[v][j], dp[u][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i][0] == i && dp[i][1] == i) {
            ans++;
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        cout << "EA"[dp[i][0] == i && dp[i][1] == i];
    }
}