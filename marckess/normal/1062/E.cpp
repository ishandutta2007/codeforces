#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, LMX = 18, no[2] = {int(1e9), 0};

struct ST {
    ii st[2][4*MX];

    ii merge (ii a, ii b, int f) {
        vi v = {a.fi, a.se, b.fi, b.se};
        sort(all(v));
        if (f) return ii(v[3], v[2]);
        return ii(v[0], v[1]);
    }

    void build (int i, int j, int pos, int a[]) {
        if (i == j) {
            st[0][pos] = ii(a[i], no[0]);
            st[1][pos] = ii(a[i], no[1]);
            return;
        }

        int m = (i+j)/2;
        build(i, m, pos*2, a);
        build(m+1, j, pos*2+1, a);

        st[0][pos] = merge(st[0][pos*2], st[0][pos*2+1], 0);
        st[1][pos] = merge(st[1][pos*2], st[1][pos*2+1], 1);
    }

    ii query (int i, int j, int pos, int a, int b, int f) {
        if (b < i || j < a) return ii(no[f], no[f]);
        if (a <= i && j <= b) return st[f][pos];
        int m = (i+j)/2;
        return merge(
                query(i, m, pos*2, a, b, f),
                query(m+1, j, pos*2+1, a, b, f),
                f
            );
    }
}st;

int n, q, p[MX][LMX], l, r, pos[MX], lvl[MX], cn = 1;
int inv[MX];
vi adj[MX];

void dfs (int u, int l) {
    inv[cn] = u;
    lvl[cn] = l;
    pos[u] = cn++;

    for (int v : adj[u]) {
        dfs(v, l+1);
        p[pos[v]][0] = pos[u];
    }
}

int lca (int u, int v) {
    if (lvl[u] < lvl[v]) swap(u, v);

    for (int j = 0; j < LMX; j++)
        if (lvl[u] - lvl[v] & (1 << j))
            u = p[u][j];

    if (u == v) return u;

    for (int j = LMX-1; j >= 0; j--)
        if (p[u][j] != p[v][j]) {
            u = p[u][j];
            v = p[v][j];
        }

    return p[u][0];
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> p[i][0];
        adj[p[i][0]].pb(i);
    }

    dfs(1, 0);
    st.build(1, n, 1, pos);

    for (int j = 1; j < LMX; j++)
        for (int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j-1]][j-1];

    while (q--) {
        cin >> l >> r;
        ii izq = st.query(1, n, 1, l, r, 0);
        ii der = st.query(1, n, 1, l, r, 1);

        int a = lca(izq.fi, der.se);
        int b = lca(izq.se, der.fi);

        if (lvl[a] > lvl[b]) {
            cout << inv[der.fi] << " " << lvl[a] << endl;
        } else {
            cout << inv[izq.fi] << " " << lvl[b] << endl;
        }
    }

    return 0;
}