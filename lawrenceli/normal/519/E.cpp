#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;
const int MAXLG = 17;

int n, m;
vector<int> adj[MAXN];
int dep[MAXN], sub[MAXN], jump[MAXN][MAXLG];

void dfs(int v, int p) {
    dep[v] = dep[p]+1;
    jump[v][0] = p;
    sub[v] = 1;
    for (int i : adj[v]) {
        if (i == p) continue;
        dfs(i, v);
        sub[v] += sub[i];
    }
}

void initlca() {
    for (int k=0; k<MAXLG-1; k++)
        for (int i=1; i<=n; i++)
            jump[i][k+1] = jump[jump[i][k]][k];
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int k=MAXLG-1; k>=0; k--)
        if (dep[jump[b][k]] >= dep[a]) b = jump[b][k];
    if (a == b) return a;
    for (int k=MAXLG-1; k>=0; k--)
        if (jump[a][k] != jump[b][k]) a = jump[a][k], b = jump[b][k];
    return jump[a][0];
}

int dist(int a, int b) { return dep[a] + dep[b] - 2*dep[lca(a, b)]; }

int anc(int a, int k) {
    for (int i=0; i<MAXLG; i++)
        if (k&1<<i)
            a = jump[a][i];
    return a;
}

int main() {
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(1, 1);
    initlca();
    cin >> m;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        if (a == b) { cout << n << '\n'; continue; }
        int d = dist(a, b), l = lca(a, b);
        if (d&1) cout << "0\n";
        else {
            if (dep[a]-dep[l] < dep[b]-dep[l]) swap(a, b);
            int c = anc(a, d/2);
            if (c == l) {
                cout << n-sub[anc(a, d/2-1)]-sub[anc(b, d/2-1)] << '\n';
            } else {
                cout << sub[c]-sub[anc(a, d/2-1)] << '\n';
            }
        }
    }
}