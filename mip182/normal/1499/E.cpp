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

//int C(int n,int k)
//{
//    if (k>n)
//        return 0;
//    int ans=fact[n];
//    ans=mult(ans,ifact[k]);
//    return mult(ans,ifact[n-k]);
//}
int dp[1001][1001][26];

void solve() {
    string x, y;
    cin >> x >> y;
    int ans = 0;
    int n = x.size();
    int m = y.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i + 1][j][x[i] - 'a']++;
            dp[i][j + 1][y[j] - 'a']++;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int was = 0; was < 26; was++) {
                if (dp[i][j][was] == 0)
                    continue;
                ans = add(ans, dp[i][j][was]);
                if (i != n && was != x[i] - 'a')
                    ad(dp[i + 1][j][x[i] - 'a'], dp[i][j][was]);
                if (j != m && was != y[j] - 'a')
                    ad(dp[i][j + 1][y[j] - 'a'], dp[i][j][was]);
            }
        }
    }
    {
        int i=0;
        while (i<x.size())
        {
            int j=i+1;
            int cnt=1;
            while (j<x.size()&&x[j-1]!=x[j])
                j++,cnt++;
            ll g=1ll*cnt*(cnt+1)/2;
            g%=mod1;
            ans=sub(ans,mult(g,m));
            i=j;
        }
    }
    swap(x,y);
    swap(n,m);
    {
        int i=0;
        while (i<x.size())
        {
            int j=i+1;
            int cnt=1;
            while (j<x.size()&&x[j-1]!=x[j])
                j++,cnt++;
            ll g=1ll*cnt*(cnt+1)/2;
            g%=mod1;
            ans=sub(ans,mult(g,m));
            i=j;
        }
    }
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