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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	#ifdef LOCAL
    freopen("a.in","r",stdin);
	#endif
    int q;
    cin>>q;
    while (q--)
    {
    int n;
    cin>>n;
    vector <ll> a(n),b(n);
    rep(i,n)
    cin>>a[i]>>b[i];
    ll dp[n][3];
    for (int i=0;i<n;i++) {
        for (int j=0;j<3;j++)
            dp[i][j]=INFLL;}
        dp[0][0]=0;
        dp[0][1]=b[0];
        dp[0][2]=b[0]*2;
        for (int i=1;i<n;i++)
        {
        for (int j=0;j<3;j++)
        {
            if (a[i]!=a[i-1]+j)
                dp[i][0]=min(dp[i][0],dp[i-1][j]);
            if (a[i]+1!=a[i-1]+j)
                dp[i][1]=min(dp[i][1],dp[i-1][j]+b[i]);
            if (a[i]+2!=a[i-1]+j)
                dp[i][2]=min(dp[i][2],dp[i-1][j]+2*b[i]);
        }
        }
        cout<<min({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<'\n';
    }




}