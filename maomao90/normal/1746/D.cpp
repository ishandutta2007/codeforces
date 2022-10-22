// time-limit: 3000
// problem-url: https://codeforces.com/contest/1746/problem/D

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int) _a.size()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 200005;

int t;
int n, k;
int p[MAXN];
int s[MAXN];
vi adj[MAXN];

pll dp(int u, int k) {
    pll res = {(ll) s[u] * k, (ll) s[u] * (k + 1)};
    if (SZ(adj[u]) == 0) {
        return res;
    }
    int nk = k / SZ(adj[u]);
    ll base = 0;
    vll diff;
    for (int v : adj[u]) {
        pll tmp = dp(v, nk);
        base += tmp.FI;
        diff.pb(tmp.SE - tmp.FI);
    }
    sort(ALL(diff), greater<ll>());
    int need = k - nk * SZ(adj[u]);
    REP (i, 0, need) {
        base += diff[i];
    }
    res.FI += base; res.SE += base;
    res.SE += diff[need];
    return res;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n >> k;
        REP (i, 1, n + 1) {
            adj[i].clear();
        }
        REP (i, 2, n + 1) {
            cin >> p[i];
            adj[p[i]].pb(i);
        }
        REP (i, 1, n + 1) {
            cin >> s[i];
        }
        cout << dp(1, k).FI << '\n';
    }
    return 0;
}