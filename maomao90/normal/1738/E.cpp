// time-limit: 2000
// problem-url: https://codeforces.com/contest/1738/problem/E

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
const int MOD = 998244353;

int t;
int n;
int a[MAXN];
ll pw[MAXN];
ll fact[MAXN], ifact[MAXN];

ll ncr(int n, int r) {
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    pw[0] = 1;
    REP (i, 1, MAXN) {
        pw[i] = pw[i - 1] * 2 % MOD;
    }
    fact[0] = 1;
    REP (i, 1, MAXN) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    ifact[0] = ifact[1] = 1;
    REP (i, 2, MAXN) {
        ifact[i] = MOD - MOD / i * ifact[MOD % i] % MOD;
    }
    REP (i, 1, MAXN) {
        ifact[i] = ifact[i - 1] * ifact[i] % MOD;
    }
    while (t--) {
        cin >> n;
        REP (i, 1, n + 1) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        int l = 1, r = n;
        ll ls = a[1], rs = a[n];
        ll ans = 1;
        while (1) {
            cerr << l << ' ' << r << '\n';
            if (l >= r) {
                break;
            }
            if (ls < rs) {
                ls += a[++l];
                continue;
            }
            if (ls > rs) {
                rs += a[--r];
                continue;
            }
            int lc = 1, rc = 1;
            while (l + 1 <= n - 1 && a[l + 1] == 0) {
                lc++;
                l++;
            }
            while (r - 1 >= 1 && a[r - 1] == 0) {
                rc++;
                r--;
            }
            if (l >= r) {
                ans = ans * pw[lc] % MOD;
                break;
            } else {
                ll tmp = 0;
                REP (i, 0, min(lc, rc) + 1) {
                    tmp += ncr(lc, i) % MOD * ncr(rc, i) % MOD;
                    if (tmp >= MOD) {
                        tmp -= MOD;
                    }
                }
                ans = ans * tmp % MOD;
                ls += a[++l];
                rs += a[--r];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}