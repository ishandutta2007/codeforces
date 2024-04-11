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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN
#define itn int
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    in(a);
    vvi dp(n+1,vi(2,INF));
    dp[0][0]=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<2;j++)
        {
            if (j==0)
            {
                if (i+1<=n)
                    dp[i+1][j^1]=min(dp[i+1][j^1],dp[i][j]+a[i]);
                if (i+2<=n)
                    dp[i+2][j^1]=min(dp[i+2][j^1],dp[i][j]+a[i]+a[i+1]);
            }
            else
            {
                if (i+1<=n)
                    dp[i+1][j^1]=min(dp[i+1][j^1],dp[i][j]);
                if (i+2<=n)
                    dp[i+2][j^1]=min(dp[i+2][j^1],dp[i][j]);
            }
        }
    }
    cout<<min(dp[n][0],dp[n][1])<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in","r",stdin);
    #endif
    int _t;
    cin>>_t;
//    _t=1;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}