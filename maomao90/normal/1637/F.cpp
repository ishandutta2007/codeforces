// time-limit: 2000
// problem-url: https://codeforces.com/contest/1637/problem/F

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
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 200005

int n;
int h[MAXN];
vi adj[MAXN];
int mxh, rt;

int dp[MAXN], c[MAXN];
void dfs(int u, int p) {
    dp[u] = -1;
    c[u] = -1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (mxto(dp[u], dp[v])) {
            c[u] = v;
        }
    }
    mxto(dp[u], h[u]);
}

ll solve(int u, int p) {
    ll res = 0;
    while (c[u] != -1) {
        for (int v : adj[u]) {
            if (v == p || v == c[u]) continue;
            res += dp[v];
            res += solve(v, u);
        }
        p = u;
        u = c[u];
    }
    return res;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    REP (i, 1, n + 1) {
        cin >> h[i];
    }
    REP (i, 1, n) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    REP (i, 1, n + 1) {
        if (mxto(mxh, h[i])) {
            rt = i;
        }
    }
    dfs(rt, -1);
    int ca = -1, cb = -1, a = -1, b = -1;
    for (int v : adj[rt]) {
        if (ca <= dp[v]) {
            cb = ca;
            b = a;
            ca = dp[v];
            a = v;
        } else if (cb < dp[v]) {
            cb = dp[v];
            b = v;
        }
    }
    ll ans = 2 * mxh;
    ans += solve(a, rt);
    if (b != -1) {
        ans += solve(b, rt);
    }
    for (int v : adj[rt]) {
        if (v == a || v == b) continue;
        ans += dp[v];
        ans += solve(v, rt);
    }
    cout << ans << '\n';
}