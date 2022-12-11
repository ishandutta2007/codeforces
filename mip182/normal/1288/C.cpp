#include <bits/stdc++.h>
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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()

using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int dp[10+1][1000+2][1000+2];
int pref[1000+2][1000+2][2];

void mod (int &b)
{
    if (b>=mod1)
        b-=mod1;
    if (b<0)
        b+=mod1;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    ll n,m;
    cin>>n>>m;
    for (int i=0;i<=m;i++)
    {
    for (int j=0;j<=n;j++)
    {
        for (int k=0;k<=n;k++)
            dp[i][j][k]=0;
    }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j>=1;j--)
            dp[1][j][i]=1;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++) {
            pref[i][j][0] = pref[i][j - 1][0] + dp[1][i][j];
            pref[i][j][0]%=mod1;
        }
    }
    for (int j=1;j<=n;j++)
    {
        for (int i=1;i<=n;i++) {
            pref[i][j][1] = pref[i - 1][j][1] + pref[i][j][0];
            pref[i][j][1]%=mod1;
        }
    }
    for (int h=2;h<=m;h++)
    {
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
        dp[h][i][j]+=(pref[i][n][1]-pref[i][j-1][1])%mod1;
        dp[h][i][j]%=mod1;
        dp[h][i][j]+=mod1;
        dp[h][i][j]%=mod1;
        }
    }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++) {
                pref[i][j][0] = pref[i][j - 1][0] + dp[h][i][j];
                pref[i][j][0]%=mod1;
            }
        }
        for (int j=1;j<=n;j++)
        {
            for (int i=1;i<=n;i++) {
                pref[i][j][1] = pref[i - 1][j][1] + pref[i][j][0];
                pref[i][j][1]%=mod1;
            }
        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
            ans+=dp[m][i][j],ans%=mod1;
    }
    cout<<ans;




}