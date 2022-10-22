// time-limit: 3000
// problem-url: https://codeforces.com/contest/1023/problem/F

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 500005

int n, m, k;
vii eg;
viii eg2;
vii adj[MAXN];
int ans[MAXN];

ii par[MAXN];
int lvl[MAXN];
void dfs(int u, int p) {
    for (auto [v, id] : adj[u]) {
        if (v == p) continue;
        par[v] = {u, id};
        lvl[v] = lvl[u] + 1;
        dfs(v, u);
    }
}

int p[MAXN], rnk[MAXN], rt[MAXN];
void init() {
    REP (i, 0, n + 5) {
        p[i] = i;
        rnk[i] = 0;
        rt[i] = i;
    }
}
int findp(int u) {
    if (p[u] == u) return u;
    return p[u] = findp(p[u]);
}
inline bool join(int a, int b) {
    int pa = findp(a), pb = findp(b);
    int op = rt[pb];
    if (pa == pb) {
        return 0;
    }
    if (rnk[pa] < rnk[pb]) swap(pa, pb);
    if (rnk[pa] == rnk[pb]) rnk[pa]++;
    p[pb] = pa;
    rt[pa] = op;
    return 1;
}
inline int getrt(int u) {
    return rt[findp(u)];
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> k >> m;
    init();
    REP (i, 0, k) {
        int u, v; cin >> u >> v;
        eg.pb({u, v});
        assert(join(u, v));
    }
    REP (i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        if (join(u, v)) {
            eg.pb({u, v});
        } else {
            eg2.pb({u, v, w});
        }
    }
    REP (i, 0, eg.size()) {
        auto [u, v] = eg[i];
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }
    dfs(1, -1);
    init();
    for (auto [u, v, w] : eg2) {
        cerr << u << ' ' << v << '\n';
        u = getrt(u), v = getrt(v);
        while (u != v) {
            if (lvl[u] < lvl[v]) swap(u, v);
            cerr << ' ' << u << ' ' << v << '\n';
            //assert(ans[par[u].SE] == 0);
            ans[par[u].SE] = w;
            assert(join(u, par[u].FI));
            u = getrt(u);
        }
    }
    ll sm = 0;
    REP (i, 0, k) {
        sm += ans[i];
        if (ans[i] == 0) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << sm << '\n';
    return 0;
}