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
#define dbg(x); {cout<<#x<<"="<<x<<", ";}
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 2e9+11;

void solve()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    vector <vector <int> > dp(n+1,vi(m+1,0));
    dp[0][0]=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            dp[i][j]=max({dp[i][j],dp[i-1][j]-1,dp[i][j-1]-1});
            {
                if (s[i-1]==t[j-1])
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
                else
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]-2);
            }
        }
    }
    int ans=0;
//    for (int i=1;i<=n;i++)
//    {
//        for (int j=1;j<=m;j++)
//            cout<<dp[i][j]<<" ";
//        cout<<'\n';
//    }
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=m;j++)
            ans=max(ans,dp[i][j]);
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #endif
    int _t;
    _t=1;
//    cin>>_t;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}