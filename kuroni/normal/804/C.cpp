#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, m, u, v, k, ans[N];
bool chk[N];
vector<int> adj[N], col[N];

void DFS(int u, int p = 0) {
    for (int v : col[u]) {
        chk[ans[v]] = true;
    }
    int cnt = 1;
    for (int v : col[u]) {
        if (ans[v] == 0) {
            while (chk[cnt]) {
                cnt++;
            }
            ans[v] = cnt++;
        }
    }
    for (int v : col[u]) {
        chk[ans[v]] = false;
    }
    for (int v : adj[u]) {
        if (v != p) {
            DFS(v, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        while (k--) {
            cin >> u;
            col[i].push_back(u);
        }
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    for (int i = 1; i <= m; i++) {
        if (ans[i] == 0) {
            ans[i] = 1;
        }
    }
    cout << *max_element(ans + 1, ans + m + 1) << '\n';
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
}