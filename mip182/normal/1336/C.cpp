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
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3000+100;
const ll INF = 1e9;
const ll mod1=998244353;
const ll mod2=2e9+11;
int dp[MAXN][MAXN];
ll add(ll a,ll b)
{
    a+=b;
    if (a>=mod1)
        return a-mod1;
    return a;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    for (int i=0;i<m;i++)
    {
        if (s[0]==t[i])
            dp[1][i]+=2;
    }
    for (int i=m;i<=n;i++)
        dp[1][i]=2;
    for (int i=2;i<=n;i++)
    {
        for (int j=n;j>=0;j--)
        {
            int x=i+j-1;
            if (x>=m||s[i-1]==t[x])
                dp[i][j]=add(dp[i][j],dp[i-1][j]);
            if (j-1>=m||(j>0&&s[i-1]==t[j-1]))
                dp[i][j-1]=add(dp[i][j-1],dp[i-1][j]);
        }
    }
    ll ans=0;
  //  cout<<dp[1][0]<<" "<<dp[1][1]<<" "<<dp[2][0]<<" "<<dp[2][1]<<'\n';
    for (int i=m;i<=n;i++) {
        ans = add(ans, dp[i][0]);
    }
    cout<<ans;



}