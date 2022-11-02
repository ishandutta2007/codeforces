#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

const int MAXN = 100100;
const int MAXLG = 17;
const int MOD = 1e9 + 7;

int n, m, K;
vector<int> adj[MAXN], adj2[MAXN];
int par[MAXN], pow[MAXN], ind[MAXN], lowlink[MAXN], cnt;
int cyc[MAXN], jmp[MAXN][MAXLG], dep[MAXN], pre[MAXN];
stack<int> stk;

void dfs(int cur, int p) {
    ind[cur] = lowlink[cur] = cnt++;
    stk.push(cur);
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (ind[nxt] == -1) {
            dfs(nxt, cur);
            lowlink[cur] = min(lowlink[cur], lowlink[nxt]);
        } else if (nxt != p)
            lowlink[cur] = min(lowlink[cur], ind[nxt]);
    }
    if (lowlink[cur] == ind[cur]) {
        if (stk.top() != cur) cyc[cur] = 1;
        while (stk.top() != cur) {
            par[stk.top()] = cur;
            stk.pop();
        }
        stk.pop();
    }
}

void dfs2(int cur, int p) {
    jmp[cur][0] = p;
    dep[cur] = dep[p] + 1;
    pre[cur] = pre[p] + cyc[cur];
    for (int i=0; i<adj2[cur].size(); i++) {
        int nxt = adj2[cur][i];
        if (nxt != p) dfs2(nxt, cur);
    }
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int k=MAXLG-1; k>=0; k--)
        if (dep[jmp[b][k]] >= dep[a])
            b = jmp[b][k];
    if (a == b) return a;
    for (int k=MAXLG-1; k>=0; k--)
        if (jmp[a][k] != jmp[b][k])
            a = jmp[a][k], b = jmp[b][k];
    return jmp[a][0];
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pow[0] = 1;
    for (int i=1; i<=n; i++) pow[i] = (pow[i-1]*2)%MOD;
    for (int i=0; i<n; i++) par[i] = i;
    memset(ind, -1, sizeof(ind));

    dfs(0, 0);
    for (int i=0; i<n; i++)
        for (int j=0; j<adj[i].size(); j++) {
            int nxt = adj[i][j];
            if (par[i] != par[nxt])
                adj2[par[i]].push_back(par[nxt]);
        }

    for (int i=0; i<n; i++)
        if (par[i] == i) {
            sort(adj2[i].begin(), adj2[i].end());
            adj2[i].resize(unique(adj2[i].begin(), adj2[i].end())-adj2[i].begin());
        }

    dfs2(0, 0);
    for (int k=1; k<MAXLG; k++)
        for (int i=0; i<n; i++)
            jmp[i][k] = jmp[jmp[i][k-1]][k-1];

    scanf("%d", &K);
    for (int i=0; i<K; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        a = par[a], b = par[b];
        int l = lca(a, b);
        int mul;
        if (l) mul = pre[a]+pre[b]-2*pre[l]+cyc[l];
        else mul = pre[a]+pre[b]-cyc[l];
        printf("%d\n", pow[mul]);
    }
    return 0;
}