// time-limit: 2000
// problem-url: https://codeforces.com/contest/724/problem/G

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
#define MAXN 200005
#define MAXL 60
#define MOD 1000000007

int n, m;
vector<pll> adj[MAXN];
int ones[MAXL], zeroes[MAXL];
ll ans;
ll pw[MAXN];

ll basis[MAXL];
bool insert(ll x) {
    while (x) {
        int k = 63 - __builtin_clzll(x & -x);
        if (basis[k]) {
            x ^= basis[k];
        } else {
            basis[k] = x;
            return 1;
        }
    }
    return 0;
}

vi comp;
int vis[MAXN];
ll dis[MAXN];
void dfs(int u, int p) {
    vis[u] = 1;
    comp.pb(u);
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        if (vis[v] == 1) {
            ll c = dis[u] ^ dis[v] ^ w;
            cerr << u << ' ' << v << ' ' << c << '\n';
            insert(c);
        } else if (vis[v] == 0) {
            dis[v] = dis[u] ^ w;
            cerr << v << ' ' << dis[v] << '\n';
            dfs(v, u);
        }
    }
    vis[u] = 2;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    pw[0] = 1;
    REP (i, 1, MAXN) {
        pw[i] = pw[i - 1] * 2 % MOD;
    }
    cin >> n >> m;
    REP (i, 0, m) {
        int u, v; ll t; cin >> u >> v >> t;
        adj[u].pb({v, t});
        adj[v].pb({u, t});
    }
    REP (x, 1, n + 1) {
        if (vis[x]) continue;
        memset(basis, 0, sizeof basis);
        memset(ones, 0, sizeof ones);
        memset(zeroes, 0, sizeof zeroes);
        comp.clear();
        dfs(x, -1);
        int rnk = 0;
        REP (i, 0, MAXL) {
            if (basis[i]) {
                rnk++;
            }
        }
        for (int i : comp) {
            REP (j, 0, MAXL) {
                if (dis[i] >> j & 1) {
                    ones[j]++;
                } else {
                    zeroes[j]++;
                }
            }
        }
        REP (i, 0, MAXL) {
            cerr << ones[i] << ' ' << zeroes[i] << '\n';
            bool has = 0;
            REP (j, 0, MAXL) {
                if (basis[j] >> i & 1) {
                    has = 1;
                    break;
                }
            }
            if (has) {
                ans += pw[rnk - 1] * ((ll) comp.size() * (comp.size() - 1) / 2 % MOD) % MOD * pw[i] % MOD;
            } else {
                ans += (ll) ones[i] * zeroes[i] % MOD * pw[i] % MOD * pw[rnk] % MOD;
            }
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}