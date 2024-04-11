#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100100;
const int BLOCK = 500;

int n, m, q, u[MAXN], v[MAXN], ans[MAXN], deg[MAXN], p[MAXN], vis[MAXN], ind[MAXN];
int num[1000][1000];
vector<pii> adj[MAXN], edges[MAXN];
vector<int> qadj[MAXN];

bool cmp(pii p1, pii p2) { return p1.second < p2.second; }

int par[MAXN], rnk[MAXN];
vector<int> change;

int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }
void merge(int a, int b) {
    a = getpar(a), b = getpar(b);
    change.push_back(a), change.push_back(b);
    if (a == b) return;
    if (rnk[a] > rnk[b]) swap(a, b);
    par[a] = b;
    if (rnk[a] == rnk[b]) rnk[b]++;
}

void dfs(int root, int cur, int c) {
    if (vis[cur] == c) return;
    vis[cur] = c;
    if (deg[cur] > BLOCK) num[ind[cur]][ind[root]]++;
    for (; p[cur]<adj[cur].size() && adj[cur][p[cur]].second <= c; p[cur]++) {
        int nxt = adj[cur][p[cur]].first, col = adj[cur][p[cur]].second;
        if (col == c) dfs(root, nxt, c);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(pii(b, c));
        adj[b].push_back(pii(a, c));
        deg[a]++, deg[b]++;
        edges[c].push_back(pii(a, b));
    }

    int cnt = 0;
    for (int i=1; i<=n; i++) {
        sort(adj[i].begin(), adj[i].end(), cmp);
        if (deg[i] > BLOCK) ind[i] = cnt++;
    }

    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> u[i] >> v[i];
        if (deg[u[i]] > BLOCK) swap(u[i], v[i]);
        if (deg[u[i]] <= BLOCK) qadj[u[i]].push_back(i);
    }

    for (int i=1; i<=n; i++) par[i] = i;

    for (int c=1; c<=m; c++) {
        for (int i=0; i<edges[c].size(); i++) {
            int a = edges[c][i].first, b = edges[c][i].second;
            merge(a, b);
        }
        sort(change.begin(), change.end());
        change.resize(unique(change.begin(), change.end())-change.begin());
        for (int i=0; i<change.size(); i++) {
            int x = change[i];
            for (int j=0; j<qadj[x].size(); j++)
                if (getpar(x) == getpar(v[qadj[x][j]]))
                    ans[qadj[x][j]]++;
        }
        for (int i=0; i<change.size(); i++) par[change[i]] = change[i], rnk[change[i]] = 0;
        change.clear();
    }

    for (int i=1; i<=n; i++)
        if (deg[i] > BLOCK) {
            memset(p, 0, sizeof(p));
            memset(vis, 0, sizeof(vis));
            for (int j=1; j<=m; j++)
                dfs(i, i, j);
        }

    for (int i=0; i<q; i++) {
        if (deg[u[i]] <= BLOCK) cout << ans[i] << '\n';
        else {
            assert(deg[u[i]] > BLOCK && deg[v[i]] > BLOCK);
            cout << num[ind[u[i]]][ind[v[i]]] << '\n';
        }
    }
    return 0;
}