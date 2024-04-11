#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 300100;
const int INF = 1e9;

int n, m, q;
vector<int> adj[MAXN];
bool vis[MAXN];
pii dp[MAXN], best;

pii getmax(pii p, int a) {
    if (a>=p.fi) return pii(a, p.fi);
    else if (a>=p.se) return pii(p.fi, a);
    else return p;
}

void dfs(int cur, int p=-1) {
    vis[cur] = 1;
    dp[cur] = pii(-INF, -INF);
    rep(i, adj[cur].size()) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        dfs(nxt, cur);
        dp[cur] = getmax(dp[cur], dp[nxt].fi+1);
    }
    if (dp[cur].fi < 0) dp[cur].fi = 0;
}

vector<int> cmp;

void dfs2(int cur, int p=-1, int d=0) {
    vis[cur] = 1;
    cmp.push_back(cur);
    pii ma = d == 0 ? dp[cur] : getmax(dp[cur], d);
    if (ma < best) best = ma;
    rep(i, adj[cur].size()) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        if (dp[nxt].fi+1 == dp[cur].fi)
            dfs2(nxt, cur, max(dp[cur].se+1, d+1));
        else
            dfs2(nxt, cur, max(dp[cur].fi+1, d+1));
    }
}

struct data {
    int p;
    pii d;
};

data par[MAXN];

data getpar(int a) { return par[a].p == a ? par[a] : par[a] = getpar(par[a].p); }

void merge(int a, int b) {
    data d1 = getpar(a), d2 = getpar(b);
    a = d1.p, b = d2.p;
    if (a == b) return;
    par[a].p = b;
    int x1 = d1.d.fi+d1.d.se, x2 = d2.d.fi+d2.d.se;
    pii p1 = getmax(d1.d, max(d2.d.fi, d2.d.se)+1);
    pii p2 = getmax(d2.d, max(d1.d.fi, d1.d.se)+1);
    if (p1 < p2) par[b].d = p1;
    else par[b].d = p2;
}

int main() { _
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    cin >> n >> m >> q;

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    rep(i, n)
        if (!vis[i])
            dfs(i);

    memset(vis, 0, sizeof(vis));
    rep(i, n)
        if (!vis[i]) {
            cmp.clear();
            best = pii(INF, INF);
            dfs2(i);
            rep(j, cmp.size())
                par[cmp[j]].p = i, par[cmp[j]].d = best;
        }

    rep(i, q) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            x--;
            data d = getpar(x);
            cout << max(d.d.fi, d.d.fi+d.d.se) << '\n';
        } else {
            int x, y;
            cin >> x >> y;
            x--, y--;
            merge(x, y);
        }
    }
    return 0;
}