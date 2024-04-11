// time-limit: 2000
// problem-url: https://codeforces.com/contest/1671/problem/E

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
#define MOD 998244353
#define MAXN 300000

int n;
string s;
ll ans;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int x[MAXN];

vi vec[MAXN];
int dfs(int u, int lvl) {
    int l = u << 1, r = u << 1 ^ 1;
    if (lvl + 1 < n) {
        int lh = dfs(l, lvl + 1), rh =  dfs(r, lvl + 1);
        cerr << u << ' ' << lh << ' ' << rh << '\n';
        if (lh != rh) {
            ans = ans * 2 % MOD;
        }
        int res = (ll) (lh + x[lvl]) * (rh + x[lvl]) % MOD + s[u] - 'A' + 1;
        if (res >= MOD) {
            res -= MOD;
        }
        return res;
    } else {
        return s[u] - 'A' + 1;
    }
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    REP (i, 0, MAXN) {
        x[i] = rnd();
    }
    cin >> n;
    cin >> s;
    s = '$' + s;
    ans = 1;
    dfs(1, 0);
    cout << ans << '\n';
    return 0;
}