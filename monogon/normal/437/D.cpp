
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// fix p and q. If we imagine all nodes appearing in decreasing order of a[i],
// the first i that connects p and q, means f(p, q) = a[i]
// so when we insert a node, process all its edges to already appeared nodes
// when we add an edge, if we join disconnected components,
// answer increases by a[i] * sz(A) * sz(B)
// at end, divide by n(n-1) / 2

const int N = 1e5 + 5;
int n, m, u, v, a[N], dsu[N];
vector<int> adj[N];
bool vis[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fill(dsu, dsu + N, -1);
    vector<pair<int, int>> ve;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ve.emplace_back(a[i], i);
    }
    sort(ve.rbegin(), ve.rend());
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    double ans = 0;
    for(auto p : ve) {
        int x = p.second;
        vis[x] = true;
        for(int y : adj[x]) {
            if(vis[y] && trace(x) != trace(y)) {
                ans += 1LL * a[x] * dsu[trace(x)] * dsu[trace(y)];
                join(x, y);
            }
        }
    }
    ans /= (1LL * n * (n - 1) / 2);
    cout << fixed << setprecision(8);
    cout << ans << '\n';
}