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
const int MAXN = 1e6+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 1e9+21;

void solve()
{
    int n;
    cin>>n;
    vector <int> r(n);
    in(r);
    vector <int> pref1(n+1);
    for (int i=1;i<=n;i++)
        pref1[i]=pref1[i-1]+r[i-1];
    int m;
    cin>>m;
    vector <int> b(m);
    in(b);
    vector <int> pref2(m+1);
    for (int i=1;i<=m;i++)
        pref2[i]=pref2[i-1]+b[i-1];
    vector <vector <int> > dp(n+1,vi(m+1));
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=m;j++)
        {
            if (i+1<=n)
                dp[i+1][j]=max({dp[i+1][j],max(dp[i][j],pref1[i+1]+pref2[j])});
            if (j+1<=m)
                dp[i][j+1]=max({dp[i][j+1],max(dp[i][j],pref1[i]+pref2[j+1])});
        }
    }
    cout<<dp[n][m]<<'\n';
}

int main() {
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int _t;
    _t=1;
    cin>>_t;
    while (_t--)
        solve();
    #ifdef Mip182
    cout<<'\n'<<"Time : "<<(double)(clock())/CLOCKS_PER_SEC<<'\n';
    #endif
}