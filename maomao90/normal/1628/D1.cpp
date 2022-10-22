// time-limit: 3000
// problem-url: https://codeforces.com/contest/1628/problem/D1

// No temptation has overtaken you except what is common to mankind. And God 
// is faithful; he will not let you be tempted beyond what you can bear.
// But when you are tempted, he will also provide a way out so that you can 
// endure it.
// 1 Corinthians 10:13
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

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MAXN 2005
#define MOD 1000000007

int t;
int n, m, k;
ll fact[MAXN], ifact[MAXN], inv2[MAXN];

inline ll choose(int n, int r) {
    if (r > n) return 0;
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

int main() {
    scanf("%d", &t);
    ifact[0] = ifact[1] = 1;
    REP (i, 2, MAXN) {
        ifact[i] = MOD - MOD / i * ifact[MOD % i] % MOD;
    }
    fact[0] = 1;
    REP (i, 1, MAXN) {
        fact[i] = fact[i - 1] * i % MOD;
        ifact[i] = ifact[i - 1] * ifact[i] % MOD;
    }
    inv2[0] = 1;
    REP (i, 1, MAXN) {
        inv2[i] = inv2[i - 1] * 500000004 % MOD;
    }
    while (t--) {
        scanf("%d%d%d", &n, &m, &k);
        if (n == m) {
            printf("%lld\n", (ll) m * k % MOD);
            continue;
        }
        ll ans = 0;
        REP (i, 1, m + 1) {
            ll dp = (ll) i * k % MOD;
            ll res = dp * choose(n - i - 1, m - i) % MOD;
            res = res * inv2[n - i] % MOD;
            ans += res;
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}