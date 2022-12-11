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

const ll INFLL = 1e18;
const int MAXN = 4e5 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;

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

//int C(int n,int k)
//{
//    if (k>n)
//        return 0;
//    int ans=fact[n];
//    ans=mult(ans,ifact[k]);
//    return mult(ans,ifact[n-k]);
//}
void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> x(n);in(x);
    int y = 0;
    for (int i = 0; i < 30; i++) {
        bool ok = true;
        for (auto to:x)
            ok &= ((to >> i) & 1) == 1;
        if (ok)
            continue;
        y ^= (1 << i);
    }
//    cout << y << '\n';
    int cnt = 0;
    for (auto to:x)
        cnt += (y & to) == 0;
    ans = 1ll * cnt * (cnt - 1)%mod1;
    int f = 1;
    for (int i = 1; i <= n - 2; i++)
        f = mult(f, i);
    cout << mult(ans, f) << '\n';
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
    cin >> _t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}