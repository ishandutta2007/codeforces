#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define int ll

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int oo = 1100000000000LL;
void mxm(int &a, int b) { if (a < b) a = b; }
int N, M, W;
int dad[1005];
int a[1005], b[1005];
int f[1005][1005];
bool g[1005][1005];
int sz1[1005];
int sz2[1005];
vi sax[1005];
int S;
int id[1005];
int root[1005];

int anc(int u) { if (dad[u] == u) return u; return dad[u] = anc(dad[u]); }
void join(int u, int v) {
    u = anc(u), v = anc(v);
    if (u > v) swap(u, v);
    if (u == v) return;
    dad[v] = u; sz1[u] += sz1[v]; sz2[u] += sz2[v];
}

int cal(int n, int m) {
    if (m < 0) return -oo;
    if (g[n][m]) return f[n][m];
    g[n][m] = 1;
    if (n == 0) return f[n][m] = 0;
    f[n][m] = cal(n - 1, m);
    mxm(f[n][m], cal(n - 1, m - sz1[root[n]]) + sz2[root[n]]);
    ff(i, 0, (int)sax[n].size() - 1) mxm(f[n][m], cal(n - 1, m - a[sax[n][i]]) + b[sax[n][i]]);
    return f[n][m];
}

signed main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> W;
    ff(i, 1, N) cin >> a[i];
    ff(i, 1, N) cin >> b[i];
    ff(i, 1, N) dad[i] = i, sz1[i] = a[i], sz2[i] = b[i];
    int u, v;
    ff(i, 1, M) cin >> u >> v, join(u, v);
    ff(i, 1, N) if (dad[i] == i) id[i] = ++S, root[S] = i; else id[i] = id[anc(i)];
    ff(i, 1, N) sax[id[i]].pb(i);
    cout << cal(S, W) << endl;
    return 0;
}