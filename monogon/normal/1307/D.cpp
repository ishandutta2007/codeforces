
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// sort decreasing by dn[x].
// for a fixed x, choose y with dn[y] <= dn[x] maximizing d1[y].

const int N = 2e5 + 5;
int n, m, k, u, v, a[N], d1[N], dn[N];
vector<int> adj[N];

void bfs(int x, int *d) {
    fill(d, d + N, -1);
    queue<int> q;
    d[x] = 0;
    q.push(x);
    while(!q.empty()) {
        u = q.front(); q.pop();
        for(int y : adj[u]) {
            if(d[y] == -1) {
                d[y] = d[u] + 1;
                q.push(y);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1, d1);
    bfs(n, dn);
    sort(a, a + k, [](int u, int v) { return dn[u] > dn[v]; });
    int ans = 0;
    int M = d1[a[0]];
    for(int i = 1; i < k; i++) {
        ans = max(ans, M + 1 + dn[a[i]]);
        M = max(M, d1[a[i]]);
    }
    cout << min(ans, d1[n]) << endl;
}