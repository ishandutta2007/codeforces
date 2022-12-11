//#define _GLIBCXX_DEBUG
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
ll m,d;
//ll bin_pow(ll base,ll deg)
//{
//    if (deg==0)
//        return 1;
//    ll t=bin_pow(base,deg/2);
//    if (deg&1)
//        return (((t*t)%m)*base)%m;
//    else
//        return (t*t)%m;
//}
ll dp[32][32];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int t;
    cin>>t;
    while (t--)
    {
        cin>>d>>m;
        int x=0;
        ll was=d;
        while (was)
            x++,was/=2;
        x--;
        for (int i=0;i<32;i++)
        {
            for (int j=0;j<32;j++)
                dp[i][j]=0;
        }
        ll y=d-(1ll<<x)+1;
        for (int i=0;i<x;i++)
            dp[1][i]=(1<<i),dp[1][i]%=m;
        dp[1][x]=y;
        dp[1][x]%=m;
        y%=m;
        for (int i=2;i<=x+1;i++)
        {
            for (int j=0;j<=x;j++)
            {
                for (int k=j+1;k<x;k++)
                    dp[i][k]+=dp[i-1][j]*((1<<k)%m),dp[i][k]%=m;
                if (x>j)
                dp[i][x]+=dp[i-1][j]*y,dp[i][x]%=m;
            }
        }
        ll ans=0;
        for (int i=1;i<=x+1;i++)
        {
            for (int j=0;j<=x;j++)
                ans+=dp[i][j],ans%=m;
        }
        cout<<ans<<'\n';




    }





}