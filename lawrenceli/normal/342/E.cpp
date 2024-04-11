#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 100100;
const int MAXLG = 17;
const int INF = 1e9;

int n, m;
vector<int> adj[MAXN];
int jump[MAXN][MAXLG], dep[MAXN];
int par[MAXN], sub[MAXN], num[MAXN], val[MAXN];

void dfs(int cur, int p=-1) {
    jump[cur][0] = p == -1 ? cur : p;
    dep[cur] = p == -1 ? 0 : dep[p] + 1;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        dfs(nxt, cur);
    }
}

void initlca() {
    for (int k=1; k<MAXLG; k++)
        for (int i=0; i<n; i++)
            jump[i][k] = jump[jump[i][k-1]][k-1];
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int k=MAXLG-1; k>=0; k--)
        if (dep[jump[b][k]] >= dep[a])
            b = jump[b][k];
    if (a == b) return a;
    for (int k=MAXLG-1; k>=0; k--)
        if (jump[a][k] != jump[b][k])
            a = jump[a][k], b = jump[b][k];
    return jump[a][0];
}

int dist(int a, int b) {
    int l = lca(a, b);
    return dep[a]+dep[b]-2*dep[l];
}

void dfs2(int cur, int p=-1) {
    sub[cur] = 1;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p || num[nxt] < num[cur]) continue;
        dfs2(nxt, cur);
        sub[cur] += sub[nxt];
    }
}

int getcen(int cur, int sze, int p=-1) {
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p || num[nxt] < num[cur]) continue;
        if (sub[nxt] > sze/2) return getcen(nxt, sze, cur);
    }
    return cur;
}

//d is depth of centroid
void go(int cur, int p=-1, int d=0) {
    dfs2(cur);
    cur = getcen(cur, sub[cur]);
    num[cur] = d;
    par[cur] = p;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (num[nxt] == n) go(nxt, cur, d+1);
    }
}

void update(int st) {
    int cur = st;
    while (cur >= 0) {
        val[cur] = min(val[cur], dist(cur, st));
        cur = par[cur];
    }
}

int query(int st) {
    int ret = INF;
    int cur = st;
    while (cur >= 0) {
        ret = min(ret, val[cur]+dist(cur, st));
        cur = par[cur];
    }
    return ret;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0; i<n; i++) num[i] = n;
    for (int i=0; i<n; i++) val[i] = INF;

    dfs(0);
    initlca();
    go(0);
    update(0);

    for (int i=0; i<m; i++) {
        int t, v;
        cin >> t >> v;
        v--;
        if (t == 1) update(v);
        else cout << query(v) << '\n';
    }
    return 0;
}