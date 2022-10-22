// time-limit: 2000
// problem-url: https://codeforces.com/contest/1648/problem/C

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
#define MOD 998244353

int n, m;
int s[MAXN], t[MAXN];
ll fact[MAXN], ifact[MAXN];
int occ[MAXN];
ll ans;

int fw[MAXN];
void incre(int i, int x) {
    for (; i < MAXN; i += i & -i) fw[i] += x;
}
int qsm(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) res += fw[i];
    return res;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> m;
    REP (i, 0, n) {
        cin >> s[i];
        incre(s[i], 1);
    }
    REP (i, 0, m) {
        cin >> t[i];
    }
    fact[0] = 1;
    REP (i, 1, MAXN) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    ifact[0] = ifact[1] = 1;
    REP (i, 2, MAXN) {
        ifact[i] = (MOD - (MOD / i) * ifact[MOD % i] % MOD) % MOD;
    }
    REP (i, 2, MAXN) {
        ifact[i] = ifact[i - 1] * ifact[i] % MOD;
    }
    REP (i, 0, n) {
        occ[s[i]]++;
    }
    ll curi = 1;
    REP (i, 0, MAXN) {
        if (occ[i] == 0) continue;
        curi = curi * ifact[occ[i]] % MOD;
    }
    bool done = 0;
    REP (i, 0, min(n, m)) {
        int sm = qsm(t[i] - 1);
        cerr << i << '\n';
        ll tmp = (ll) sm * fact[n - i - 1] % MOD * curi % MOD;
        cerr << ' ' << sm << ' ' << tmp << '\n';
        cerr << n - i - 1 << ' ' << fact[n - i - 1] << ' ' << curi << '\n';
        ans += tmp;
        if (ans >= MOD) {
            ans -= MOD;
        }
        if (occ[t[i]] == 0) {
            done = 1;
            break;
        }
        curi = curi * fact[occ[t[i]]] % MOD;
        occ[t[i]]--;
        curi = curi * ifact[occ[t[i]]] % MOD;
        incre(t[i], -1);
    }
    if (!done && n < m) {
        ans++;
        if (ans >= MOD) {
            ans -= MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}