#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, u, v, k;
bool vis[N];
vector<int> adj[N];

int DFS(int u) {
    int ret = 1;
    vis[u] = true;
    for (int &v : adj[u]) {
        if (!vis[v]) {
            ret += DFS(v);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            k -= DFS(i) - 1;
        }
    }
    cout << k;
}