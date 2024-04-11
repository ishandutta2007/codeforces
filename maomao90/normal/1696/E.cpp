// time-limit: 2000
// problem-url: https://codeforces.com/contest/1696/problem/E

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
const int MAXN = 400005;
const int MOD = 1000000007;

ll fpow(ll b, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            res = res * b % MOD;
        }
        b = b * b % MOD;
        p >>= 1;
    }
    return res;
}

int n;
int a[MAXN];
ll fact[MAXN], ifact[MAXN];
ll ans;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    REP (i, 0, n + 1) {
        cin >> a[i];
    }
    fact[0] = ifact[0] = 1;
    REP (i, 1, MAXN) {
        fact[i] = fact[i - 1] * i % MOD;
        ifact[i] = fpow(fact[i], MOD - 2);
    }
    REP (i, 0, n + 1) {
        if (a[i] == 0) {
            break;
        }
        a[i]--;
        int s = i + 2, e = s + a[i] - 1;
        ll res = fact[e] * ifact[s - 1] % MOD;
        res = res * ifact[a[i]] % MOD;
        ans += res;
        if (ans >= MOD) {
            ans -= MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}