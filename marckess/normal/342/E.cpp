#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005, LMX = 20;
int n, u, v, st[LMX][MX], lvl[MX], p[MX], stsz[MX];
vi adj[MX];

void dfs (int u, int l) {
    lvl[u] = l;
    stsz[u] = 1;

    for (int v : adj[u]) {
        if (v != p[u]) {
            p[v] = u;
            dfs(v, l+1);
            stsz[u] += stsz[v];
        }
    }
}

void obtST () {
    for (int i = 1; i <= n; i++)
        st[0][i] = p[i];

    for (int j = 1; j < LMX; j++)
        for (int i = 1; i <= n; i++)
            st[j][i] = st[j-1][st[j-1][i]];
}

int lca (int u, int v) {
    if (lvl[u] < lvl[v])
        swap(u, v);

    int dis = lvl[u] - lvl[v];
    for (int j = LMX - 1; j >= 0; j--)
        if (dis & (1 << j))
            u = st[j][u];

    if (u == v)
        return u;

    for (int j = LMX - 1; j >= 0; j--)
        if (st[j][u] != st[j][v]) {
            u = st[j][u];
            v = st[j][v];
        }

    return p[u];
}

//---------------Centroid Decomposition--------------//
bitset<MX> cent;
int cdp[MX];

int decomp (int u) {
    int tam = 1;

    for (int v : adj[u])
        if (!cent[v])
            tam += stsz[v];

    while (1) {
        int ind = -1;

        for (int v : adj[u])
            if (!cent[v] && 2 * stsz[v] > tam)
                ind = v;

        if (ind == -1)
            break;

        stsz[u] = tam - stsz[ind];
        u = ind;
    }

    cent[u] = 1;

    for (int v : adj[u])
        if (!cent[v])
            cdp[decomp(v)] = u;

    return u;
}

//---------------------------------------------------//

int mn[MX], root, q;

#define obtDist(u,v) (lvl[u] + lvl[v] - 2 * lvl[lca(u, v)])

void updateCD (int u) {
    int v = u;

    while (1) {
        mn[v] = min(mn[v], obtDist(u, v));
        
        if (v == root)
            break;
        v = cdp[v];
    }
}

int obtRes (int u) {
    int v = u, res = 1e9;

    while (1) {
        res = min(res, mn[v] + obtDist(u, v));
        
        if (v == root)
            break;
        v = cdp[v];
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fill(mn, mn + MX, 1e9);

    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    p[1] = 1;
    dfs(1, 0);
    obtST();
    root = decomp(1);

    updateCD(1);

    while (q--) {
        cin >> u >> v;

        if (u == 1)
            updateCD(v);
        else
            cout << obtRes(v) << endl;
    }

    return 0;
}