#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

template<class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const ll INFLL = 1e18;
const int MAXN = 1e5 + 100;
const ll INF = 1e9;
const int mod2 = 1e9 + 21;
int mod1;

int add(int a, int b) {
    a += b;
    if (a >= mod1)
        return a - mod1;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod1;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        return a + mod1;
    return a;
}

void ad(int &x, int y) {
    x = add(x, y);
}

int bin_pow(int base, ll deg) {
    if (deg == 0)
        return 1;
    int t = bin_pow(base, deg / 2);
    if (deg & 1)
        return 1ll * t * t % mod1 * base % mod1;
    else
        return 1ll * t * t % mod1;
}

int fact[MAXN], ifact[MAXN];

int C(int n, int k) {
    if (k > n)
        return 0;
    int ans = fact[n];
    ans = mult(ans, ifact[k]);
    return mult(ans, ifact[n - k]);
}

// number of ways with cnt_left and cnt_right
int two[MAXN];

int f(int k) {
    return two[k - 1];
}

void solve() {
    int n;
    cin >> n >> mod1;
    fact[0] = 1;
    two[0] = 1;
    for (int i = 1; i < MAXN; i++)
        two[i] = mult(two[i - 1], 2);
    for (int i = 1; i < MAXN; i++) {
        fact[i] = mult(fact[i - 1], i);
    }
    ifact[MAXN - 1] = bin_pow(fact[MAXN - 1], mod1 - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        ifact[i] = mult(ifact[i + 1], i + 1);
    vector<vector<int>> dp(n + 1, vi(n + 1));
    for (int fir = 1; fir <= n; fir++) {
        for (int was = fir; was <= n; was++) {
            ad(dp[fir][was - fir], mult(f(fir), C(was, fir)));
        }
    }
    for (int nex = 2; nex <= n; nex++) {
        for (int was = 1; was <= n; was++) {
            for (int till = nex; till <= n && was - (till - nex + 1) >= 0; till++) {
                int sz = till - nex + 1;
                ad(dp[till][was-sz],mult(dp[nex-2][was],mult(f(sz),C(was,sz))));
            }
        }
    }
    cout << dp[n][0] << '\n';
}

int main() {
#ifdef Mip182
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int _t;
    _t = 1;
//    cin>>_t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}