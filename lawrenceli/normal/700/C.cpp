#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 1005;
const int maxm = 30100;
const int maxlg = 10;

int n, m, s, t;
int ea[maxm], eb[maxm], ew[maxm];
vector<pair<int, pair<int, int> > > adj[maxn], chd[maxn];

bool vis[maxn];
int par[maxn], pn[maxn];
int jump[maxn][maxlg], dep[maxn];

vector<pair<int, int> > back[maxn];

void dfs(int v, int p = -1, int parn = -1) {
    par[v] = p;
    pn[v] = parn;
    vis[v] = 1;
    jump[v][0] = p == -1 ? v : p;
    dep[v] = p == -1 ? 0 : dep[p] + 1;
    for (auto i : adj[v])
        if (i.B.A != parn) {
            if (!vis[i.A]) {
                chd[v].push_back(i);
                dfs(i.A, v, i.B.A);
            } else if (dep[i.A] < dep[v]) back[v].push_back(MP(i.A, i.B.A));
        }
}

void initlca() {
    for (int k = 0; k < maxlg - 1; k++)
        for (int i = 1; i <= n; i++)
            jump[i][k + 1] = jump[jump[i][k]][k];
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int k = maxlg - 1; k >= 0; k--)
        if (dep[jump[b][k]] >= dep[a])
            b = jump[b][k];

    if (a == b) return a;

    for (int k = maxlg - 1; k >= 0; k--)
        if (jump[a][k] != jump[b][k])
            a = jump[a][k], b = jump[b][k];
    return jump[a][0];
}

int U[maxn], I[maxn];
int numb[maxn][maxn]; //num backedges from subtree of i to ancestors of j
int indb[maxn][maxn]; //index

void dfs3(int a, int v, int k = 0, int l = -1) {
    k += U[v];
    l = max(l, I[v]);
    numb[a][v] = k;
    indb[a][v] = l;

    for (auto i : chd[v])
        dfs3(a, i.A, k, l);
}

void dfs2(int v) {
    memset(U, 0, sizeof(U));
    memset(I, -1, sizeof(I));
    for (auto i : back[v]) {
        U[i.A]++;
        I[i.A] = i.B;
    }

    dfs3(v, s);

    for (auto i : chd[v]) {
        dfs2(i.A);
        for (int j = 1; j <= n; j++) {
            numb[v][j] += numb[i.A][j];
            indb[v][j] = max(indb[v][j], indb[i.A][j]);
        }
    }
}

int best = (2e9) + 5;
int ba = -1, bb = -1;

void updans(int a, int b) {
    int k = (a == -1 ? 0 : ew[a]) + (b == -1 ? 0 : ew[b]);
    //cout << k << ' ' << a << ' ' << b << endl;
    if (k < best) {
        best = k;
        ba = a, bb = b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        cin >> ea[i] >> eb[i] >> ew[i];
        if (ea[i] != eb[i]) {
            adj[ea[i]].push_back(MP(eb[i], MP(i, ew[i])));
            adj[eb[i]].push_back(MP(ea[i], MP(i, ew[i])));
        }
    }

    dfs(s);

    if (!vis[t]) {
        cout << "0\n0\n";
        return 0;
    }

    initlca();
    memset(indb, -1, sizeof(indb));
    dfs2(s);
/*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << numb[i][j] << ' ';
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) cout << par[i] << ' ' << pn[i] << endl;
*/

    for (int i = 1; i <= n; i++)
        if (i != s && lca(i, t) == i) {
            if (numb[i][par[i]] == 0) {
                updans(pn[i], -1);
            } else if (numb[i][par[i]] == 1) {
                updans(pn[i], indb[i][par[i]]);
            }
        }

    for (int i = 1; i <= n; i++)
        if (i != s && lca(i, t) == i && numb[i][par[i]] > 0)
            for (int j = 1; j <= n; j++)
                if (j != s && j != i && lca(i, j) == i) {
                    if (lca(j, t) == j) {
                        if (numb[j][par[j]] == 0) {
                            updans(pn[j], pn[i]);
                        }
                    } else {
                        if (numb[j][par[j]] == numb[i][par[i]] && numb[j][par[i]] == numb[i][par[i]]) {
                            updans(pn[j], pn[i]);
                        }
                    }
                }

    if (ba == -1) cout << "-1\n";
    else {
        cout << best << '\n';
        int k = int(ba != -1) + (bb != -1);
        cout << k << '\n';
        if (k == 2) cout << ba + 1 << ' ' << bb + 1 << '\n';
        else if (ba != -1) cout << ba + 1 << '\n';
        else cout << bb + 1 << '\n';
    }
}