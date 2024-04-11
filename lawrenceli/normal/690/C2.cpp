#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int n, m;
vector<int> adj[maxn];
int dist[maxn];

void dfs(int v, int d = 0) {
    if (dist[v] != -1) return;
    dist[v] = d;
    for (int i : adj[v])
        dfs(i, d + 1);
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(dist, -1, sizeof(dist));
    dfs(1);

    int x = max_element(dist + 1, dist + n + 1) - dist;
    memset(dist, -1, sizeof(dist));
    dfs(x);

    cout << *max_element(dist + 1, dist + n + 1) << '\n';
}