#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <ios>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pii;

const int MAXN = 105;

int n, m;
vector<int> adj[MAXN];
bool vis[MAXN], in[MAXN];
pii dist[2][MAXN];
queue<int> que;

void bfs(int st, int b) {
    memset(vis, 0, sizeof(vis));
    memset(in, 0, sizeof(in));
    que.push(st);
    in[st] = 1;
    dist[b][st].fi = 0;
    dist[b][st].se = 1;
    vis[st] = 1;
    while (!que.empty()) {
        int sze = que.size();
        vector<int> vi;
        for (int ii=0; ii<sze; ii++) {
            int v = que.front(); que.pop();
            for (int i=0; i<adj[v].size(); i++) {
                int u = adj[v][i];
                if (!vis[u]) {
                    dist[b][u].fi = dist[b][v].fi + 1;
                    dist[b][u].se += dist[b][v].se;
                    if (!in[u])
                        que.push(u), in[u] = 1, vi.push_back(u);
                }
            }
        }
        for (int i=0; i<vi.size(); i++) vis[vi[i]] = 1;
    }
}

int main() {
    ios :: sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(0, 0);
    bfs(n-1, 1);

    pii p = dist[0][n-1];
    ll ans = 0;

    for (int i=0; i<n; i++) {
        if (dist[0][i].fi + dist[1][i].fi != p.fi) continue;
        ll num = dist[0][i].se * dist[1][i].se;
        if (i == 0 || i == n-1) ans = max(ans, num);
        else ans = max(ans, 2*num);
    }

    cout << fixed << setprecision(10) << double(ans) / (p.se) << '\n';
    return 0;
}