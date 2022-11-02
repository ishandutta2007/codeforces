#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int n, m, vis[MAXN], cyc[MAXN], par[MAXN], sze[MAXN];
vector<int> adj[MAXN];

int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }
void merge(int a, int b) { par[getpar(a)] = getpar(b); }

void dfs(int cur) {
    vis[cur] = 1;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (vis[nxt] == 1) cyc[getpar(cur)] = 1;
        if (!vis[nxt]) dfs(nxt);
    }
    vis[cur] = 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=1; i<=n; i++) par[i] = i;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        merge(a, b);
    }

    for (int i=1; i<=n; i++) {
        sze[getpar(i)]++;
        if (!vis[i])
            dfs(i);
    }

    int ans = 0;
    for (int i=1; i<=n; i++)
        if (getpar(i) == i)
            ans += sze[i]+cyc[i]-1;

    cout << ans << '\n';
}