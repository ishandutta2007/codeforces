// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/1420/D

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
#define MAXN 300005
#define MOD 998244353

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    int n, k; cin >> n >> k;
    vii ev;
    REP (i, 0, n) {
        int l, r; cin >> l >> r;
        ev.pb(MP(l, 1));
        ev.pb(MP(r + 1, -1));
    }
    vll fact(n + 5, 1), ifact(n + 5, 1);
    REP (i, 2, n + 1) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    REP (i, 2, n + 1) {
        ifact[i] = MOD - MOD / i * ifact[MOD % i] % MOD;
    }
    REP (i, 2, n + 1) {
        ifact[i] = ifact[i] * ifact[i - 1] % MOD;
    }
    auto choose = [&] (int n, int r) -> ll {
        if (n < r) {
            return 0;
        }
        return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
    };
    sort(ALL(ev));
    int cnt = 0;
    ll ans = 0;
    for (auto [i, x] : ev) {
        if (x == 1) {
            cnt++;
        } else {
            cnt--;
            ans += choose(cnt, k - 1);
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}