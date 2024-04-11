#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 150005, P = 998244353, S = 400;

int n, q, t, a[N], d[N], L[N], R[N], dfn[N], sz[N], fa[N], dfncnt;
int b[N], pos[N], len, s[N], sum, son[S][N];

vector<int> g[N];

int c[N], tag[N];

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

void inline ins(int x, int y) {
    if (x > n) return;
    add(tag[pos[x]], y);
    add(c[x], y);
}

int inline ask(int x) {
    int p = pos[x];
    int res = 0;
    for (int i = 1; i < p; i++)
        add(res, tag[i]);
    for (int i = L[p]; i <= x; i++)
        add(res, c[i]);
    return res;
}

void dfs(int u) {
    sz[u] = 1;
    dfn[u] = ++dfncnt;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa[u]) continue;
        fa[v] = u;
        dfs(v);
        sz[u] += sz[v];
    }
} 

int inline isA(int x, int y) {
    return dfn[x] <= dfn[y] && dfn[y] <= dfn[x] + sz[x] - 1;
}

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % P;
        a = 1ll * a * a % P;
        b >>= 1;
    }
    return res;
}

int inline inv(int x) {
    return power(x, P - 2);
}

void inline upd(int l, int r, int k) {
    ins(l, k);
    ins(r + 1, P - k);
}

int main() {
    scanf("%d%d", &n, &q);
    t = sqrt(n);
    for (int i = 1; i <= n; i++) {
        pos[i] = (i - 1) / t + 1;
        if (!L[pos[i]]) L[pos[i]] = i;
    }
    
    for (int i = 1, u, v; i < n; i++)
        scanf("%d%d", &u, &v), g[u].pb(v), g[v].pb(u), d[v]++, d[u]++;
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (d[i] > t) b[++len] = i;
    for (int i = 1; i <= len; i++) {
        int u = b[i];
        for (int j = 0; j < g[u].size(); j++) {
            int v = g[u][j];
            if (v == fa[u]) continue;
            for (int k = dfn[v]; k < dfn[v] + sz[v]; k++)
                son[i][k] = v;
        }
    }
    int I = inv(n);
    while (q--) {
        int op, v; scanf("%d%d", &op, &v);
        if (op == 1) {
            int w; scanf("%d", &w);
            if (d[v] > t) {
                add(s[v], w);
            } else {
                int bb = 0;
                add(sum, 1ll * w * I % P);
                add(bb, 1ll * w * I % P);
               // cout << " sz" << 1 << endl;
                for (int i = 0; i < g[v].size(); i++) {
                    int k = g[v][i];
                    if (k == fa[v]) {
                        upd(dfn[v], dfn[v] + sz[v] - 1, 1ll * I * (n - sz[v]) % P * w % P);
                        add(bb, 1ll * I * (n - sz[v]) % P * w % P);
                        //cout << " sz " << k << " " << sz[v] << endl;
                    } else {
                        int val = 1ll * I * sz[k] % P * w % P;
                        //cout << " sz " << sz[k]<< " nmd " << k << endl;
                        add(sum, val);
                        upd(dfn[k], dfn[k] + sz[k] - 1, P - val);
                        add(bb, val);
                    }
                }
                //cout << " hhehe" << bb << " ???\n";
            }
        } else {
            int res = ask(dfn[v]);
            add(res, sum);
            for (int i = 1; i <= len; i++) {
                int u = b[i];
                if (isA(u, v)) {
                    int t = son[i][dfn[v]];
                    add(res, 1ll * I * (n - sz[t]) % P * s[u] % P);
                } else {
                    add(res, 1ll * I * sz[u] % P * s[u] % P);
                }
            }
            printf("%d\n", res);
        }
    }
    return 0;
}