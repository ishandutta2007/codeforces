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
const int MAXN = 1e6 + 100;
const ll INF = 1e9;
const int mod1 = 998244353;
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

vvi g;
int n, k;
int f[5001][5001];

void dfs(int s, int p) {
    f[s][0]++;
    for (auto to:g[s]) {
        if (to == p)
            continue;
        dfs(to, s);
        vector<int> now(k + 1);
        int total = 0;
        for (int i = 0; i <= k; i++)
            total = add(total, f[to][i]);
        for (int i = 0; i <= k; i++)
            now[i] = mult(f[s][i], total);
        vector <int> pref_s(k+1);
        pref_s[0]=f[s][0];
        for (int i=1;i<=k;i++)
            pref_s[i]=add(pref_s[i-1],f[s][i]);
        vector <int> pref_to(k+1);
        pref_to[0]=f[to][0];
        for (int i=1;i<=k;i++)
            pref_to[i]=add(pref_to[i-1],f[to][i]);
        for (int i = 1; i < k; i++) {
//            for (int j = 0; j + 1 <= i; j++) {
//                int sz = i + j + 1;
//                if (sz <= k) {
//                    ad(now[i], mult(f[s][i], f[to][j]));
//                }
//            }
// j<=k-i-1 && j<=i-1
            ad(now[i],mult(f[s][i],pref_to[min(k-i-1,i-1)]));
        }
        for (int j = 0; j < k; j++) {
//            for (int i = 0; i <= j; i++) {
//                int sz = i + j + 1;
//                if (sz <= k) {
//                    ad(now[j + 1], mult(f[s][i], f[to][j]));
//                }
//            }
//            i+j+1<=k && i<=k
                ad(now[j+1],mult(f[to][j],pref_s[min(j,k-j-1)]));
        }
        for (int i = 0; i <= k; i++)
            f[s][i] = now[i];
    };
}

void solve() {
    cin >> n >> k;
    g = vvi(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0, 0);
    int ans = 0;
    for (int i = 0; i <= k; i++)
        ans = add(ans, f[0][i]);
    cout << ans << '\n';
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