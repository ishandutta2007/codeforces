#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005, LMX = 18;

struct PST {
    PST *izq, *der;
    int cn;

    PST () : izq(0), der(0), cn(0) {}
    PST (PST *_izq, PST *_der) {
        izq = _izq;
        der = _der;
        cn = izq->cn + der->cn;
    }
    PST (int cn) : izq(0), der(0), cn(cn) {}

    void init (int i, int j) {
        if (i == j)
            return;

        int m = (i+j)/2;
        (izq = new PST)->init(i, m);
        (der = new PST)->init(m+1, j);
    }

    PST *insert (int i, int j, int x) {
        if (x < i || j < x)
            return this;

        if (i == j)
            return new PST(cn + 1);

        int m = (i+j)/2;
        return new PST ( izq->insert(i, m, x), der->insert(m+1, j, x) );
    }
};

int n, m, q, u, v, a, lvl[MX], p[LMX][MX];
vi adj[MX], hab[MX], res;
PST *st[MX];

void dfs (int u, int l) {
    st[u] = st[p[0][u]];
    lvl[u] = l;

    for (int x : hab[u])
        st[u] = st[u]->insert(1, m+1, x);

    for (int v : adj[u]) {
        if (v != p[0][u]) {
            p[0][v] = u;
            dfs(v, l+1);
        }
    }
}

void preLCA () {
    for (int j = 1; j < LMX; j++)
        for (int i = 1; i <= n; i++)
            p[j][i] = p[j-1][p[j-1][i]];
}

int LCA (int u, int v) {
    if (lvl[u] < lvl[v])
        swap(u, v);

    for (int j = LMX - 1; j >= 0; j--)
        if ((lvl[u] - lvl[v]) & (1 << j))
            u = p[j][u];

    if (u == v)
        return u;

    for (int j = LMX - 1; j >= 0; j--)
        if (p[j][u] != p[j][v]) {
            u = p[j][u];
            v = p[j][v];
        }
    
    return p[0][u];
}

int busc (int k, PST *a, PST *b, PST *lca, PST *anc) {
    int i = 1, j = m + 1;
    while (i < j) {
        int d = a->izq->cn + b->izq->cn - lca->izq->cn - anc->izq->cn;
        int m = (i+j)/2;
        if (d >= k) {
            j = m;
            a = a->izq;
            b = b->izq;
            lca = lca->izq;
            anc = anc->izq;
        } else {
            k -= d;
            i = m + 1;
            a = a->der;
            b = b->der;
            lca = lca->der;
            anc = anc->der;
        }
    }

    return i;
}

void obtRes () {
    int lca = LCA(u, v);
    res.clear();
    
    for (int i = 1; i <= a; i++) {
        int e = lca;
        if (e == 1)
            e = 0;
        else
            e = p[0][lca];

        int d = busc(i, st[u], st[v], st[lca], st[e]);
        if (d != m + 1)
            res.push_back(d);
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m >> q;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= m; i++) {
        cin >> u;
        hab[u].push_back(i);
    }

    st[0] = new PST();
    st[0]->init(1, m+1);

    st[1] = new PST();
    st[1]->init(1, m+1);

    p[0][1] = 1;
    dfs(1, 0);
    preLCA();

    while (q--) {
        cin >> u >> v >> a;
        obtRes();

        cout << res.size();
        for (int x : res)
            cout << " " << x;
        cout << endl;
    }

    return 0;
}