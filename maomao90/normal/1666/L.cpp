// time-limit: 3000
// problem-url: https://codeforces.com/contest/1666/problem/L

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

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 200005

int n, m, s;
vi adj[MAXN];
int vis[MAXN];
int comp[MAXN];
int par[MAXN];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        cerr << u << ' ' << v << '\n';
        vis[v] = 1;
        if (p == -1) {
            comp[v] = v;
        } else {
            comp[v] = comp[u];
        }
        par[v] = u;
        dfs(v, u);
    }
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> m >> s;
    REP (i, 0, m) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
    }
    comp[s] = s;
    vis[s] = 1;
    dfs(s, -1);
    REP (u, 1, n + 1) {
        cerr << u << '\n';
        if (!vis[u]) continue;
        for (int v : adj[u]) {
            if (par[v] == u || v == s || !vis[v]) {
                continue;
            }
            cerr << ' ' << v << '\n';
            if (comp[v] != comp[u]) {
                vi fi, se;
                int x = v;
                fi.pb(v);
                int cnt = 0;
                while (x != s) {
                    assert(++cnt <= n);
                    x = par[x];
                    fi.pb(x);
                }
                se.pb(v);
                x = u;
                se.pb(u);
                while (x != s) {
                    x = par[x];
                    se.pb(x);
                }
                reverse(ALL(fi));
                reverse(ALL(se));
                cout << "Possible\n";
                cout << fi.size() << '\n';
                for (int i : fi) {
                    cout << i << ' ';
                }
                cout << '\n';
                cout << se.size() << '\n';
                for (int i : se) {
                    cout << i << ' ';
                }
                cout << '\n';
                return 0;
            }
        }
    }
    cout << "Impossible\n";
    return 0;
}