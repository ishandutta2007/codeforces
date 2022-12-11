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
const int MAXN = 2e5+1;
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

array<array<int,10>,10> mult(array<array<int,10>,10> &a,array<array<int,10>,10> &b) {
    int sz = 10;
    array<array<int,10>,10> c;
    for (int f=0;f<10;f++)
    {
        for (int g=0;g<10;g++)
            c[f][g]=0;
    }
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int f = 0; f < sz; f++)
                c[i][j] = add(c[i][j], mult(a[i][f], b[f][j]));
        }
    }
    return c;
}

array<array<int,10>,10> base_deg[MAXN];


void solve() {
    string s;
    int m;
    cin >> s >> m;
    vector<int> a(10);
    for (auto to:s)
        a[to - '0']++;
    array<array<int,10>,10> ans=base_deg[m];
    vector<int> new_a(10);
    for (int was = 0; was < 10; was++) {
        for (int f = 0; f < 10; f++)
            new_a[was] = add(new_a[was], mult(ans[was][f], a[f]));
    }
    int true_ans = 0;
    for (auto to:new_a)
        true_ans = add(true_ans, to);
    cout << true_ans << '\n';
}

int main() {
    array<array<int,10>,10> base;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
            base[i][j]=0;
    }
    base[0][9] = 1;
    base[1][9] = 1;
    for (int i = 0; i < 9; i++)
        base[i + 1][i] = 1;
    base_deg[1] = base;
    for (int i = 2; i < MAXN; i++)
        base_deg[i] = mult(base_deg[i - 1], base);
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