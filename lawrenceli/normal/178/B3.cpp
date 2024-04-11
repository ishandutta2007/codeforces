#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <cstring>

using namespace std;

const int MAXN = 100100;
const int MAXLG = 17;

int n, m, k;
vector<int> edge[MAXN], adj[MAXN];
int par[MAXN], ind[MAXN], lowlink[MAXN], cnt, dep[MAXN], pre[MAXN];
int jump[MAXN][MAXLG];

void setmin(int& a, int b) { if (a > b) a = b; }

void dfs(int cur) {
    ind[cur] = lowlink[cur] = cnt++;
    for (int i=0; i<edge[cur].size(); i++) {
        int nxt = edge[cur][i];
        if (ind[nxt] == -1) {
            par[nxt] = cur;
            adj[cur].push_back(nxt);
            dfs(nxt);
            setmin(lowlink[cur], lowlink[nxt]);
        } else if (nxt != par[cur])
            setmin(lowlink[cur], lowlink[nxt]);
    }
}

void dfs2(int cur) {
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        dep[nxt] = dep[cur] + 1;
        if (lowlink[nxt] == ind[nxt]) pre[nxt] = pre[cur] + 1;
        else pre[nxt] = pre[cur];
        dfs2(nxt);
    }
}

void initlca() {
    for (int i=0; i<n; i++) jump[i][0] = par[i];
    for (int k=1; k<MAXLG; k++)
        for (int i=0; i<n; i++)
            jump[i][k] = jump[jump[i][k-1]][k-1];
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int i=MAXLG-1; i>=0; i--)
        if (dep[jump[b][i]] >= dep[a])
            b = jump[b][i];
    if (a == b) return a;
    for (int i=MAXLG-1; i>=0; i--)
        if (jump[a][i] != jump[b][i])
            a = jump[a][i], b = jump[b][i];
    return par[a];
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    memset(ind, -1, sizeof(ind));
    dfs(0);
    dfs2(0);
    initlca();

    cin >> k;
    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int c = lca(a, b);
        cout << pre[a] + pre[b] - 2*pre[c] << '\n';
    }
    return 0;
}