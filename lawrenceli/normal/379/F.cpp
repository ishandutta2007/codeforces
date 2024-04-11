#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>

using namespace std;

const int MAXN = 1000100;
const int MAXQ = 500100;
const int MAXLG = 20;

int n, q, v[MAXQ], par[MAXN], dep[MAXN], jump[MAXN][MAXLG];
vector<int> adj[MAXN];

void dfs(int cur, int p) {
    par[cur] = p; dep[cur] = dep[p] + 1;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        dfs(nxt, cur);
    }
}

void initlca() {
    for (int i=0; i<n; i++) jump[i][0] = par[i];
    for (int k=1; k<MAXLG; k++) {
        for (int i=0; i<n; i++)
            jump[i][k] = jump[jump[i][k-1]][k-1];
    }
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

inline int dist(int a, int b) {
    return dep[a] + dep[b] - 2*dep[lca(a, b)];
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    for (int i=1; i<=3; i++) adj[0].push_back(i);
    n = 4;

    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> v[i]; v[i]--;
        adj[v[i]].push_back(n++);
        adj[v[i]].push_back(n++);
    }

    dfs(0, 0);
    initlca();

    int maxd = 2, node1 = 1, node2 = 2;

    for (int i=0; i<q; i++) {

        for (int j=4; j<=5; j++) {
            int x = j + 2*i;
            int d = dist(x, node1);
            if (d > maxd)
                maxd = d, node2 = x;

            d = dist(x, node2);
            if (d > maxd)
                maxd = d, node1 = x;
        }

        cout << maxd << endl;
    }

    return 0;
}