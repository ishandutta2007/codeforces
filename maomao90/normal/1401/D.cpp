// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/1401/D

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
#define MOD 1000000007

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cerr << n << '\n';
        vector<vi> adj(n + 1);
        REP (i, 1, n) {
            int a, b; cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        int m; cin >> m;
        vi p(m, 0);
        REP (i, 0, m) {
            cin >> p[i];
        }
        sort(ALL(p));
        while (m > n - 1) {
            m--;
            int tmp = p.back(); p.pop_back();
            p[m - 1] = (ll) p[m - 1] * tmp % MOD;
        }
        reverse(ALL(p));
        while (m < n - 1) {
            p.pb(1);
            m++;
        }
        vll prs;
        auto dfs = [&] (auto &&self, int u, int p) -> int {
            int sub = 1;
            for (int v : adj[u]) {
                if (v == p) continue;
                sub += self(self, v, u);
            }
            ll cur = (ll) sub * (n - sub);
            if (cur > 0) {
                cerr << ' ' << cur << '\n';
                prs.pb(cur);
            }
            return sub;
        };
        dfs(dfs, 1, -1);
        sort(ALL(prs), greater<ll>());
        ll ans = 0;
        REP (i, 0, m) {
            ans += p[i] * prs[i] % MOD;
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}