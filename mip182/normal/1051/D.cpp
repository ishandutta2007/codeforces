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
const ll mod1=998244353;
const ll mod2=2e9+11;
int dp[1001][2001][4];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n,k;
    cin>>n>>k;
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=k+1;j++)
        {
            for (int f=0;f<4;f++)
                dp[i][j][f]=0;
        }
    }
    dp[1][1][3]=1;
    dp[1][1][0]=1;
    dp[1][2][1]=1;
    dp[1][2][2]=1;
    for (int i=2;i<=n;i++)
    {
    for (int j=0;j<=2*n;j++)
    {
        for (int f=0;f<4;f++)
        {
                int a=(f&1);
                int b=((f>>1)&1);
                if (a==0&&b==0)
                {
                    dp[i][j+1][3]+=dp[i-1][j][f];
                    dp[i][j+1][2]+=dp[i-1][j][f];
                    dp[i][j+1][1]+=dp[i-1][j][f];
                    dp[i][j][0]+=dp[i-1][j][f];
                }
                if (a==1&&b==1)
                {
                    dp[i][j][3]+=dp[i-1][j][f];
                    dp[i][j+1][2]+=dp[i-1][j][f];
                    dp[i][j+1][1]+=dp[i-1][j][f];
                    dp[i][j+1][0]+=dp[i-1][j][f];
                }
                if (a==0&&b==1)
                {
                    dp[i][j][3]+=dp[i-1][j][f];
                    dp[i][j][2]+=dp[i-1][j][f];
                    dp[i][j+2][1]+=dp[i-1][j][f];
                    dp[i][j][0]+=dp[i-1][j][f];
                }
                if (a==1&&b==0)
                {
                    dp[i][j][3]+=dp[i-1][j][f];
                    dp[i][j+2][2]+=dp[i-1][j][f];
                    dp[i][j][1]+=dp[i-1][j][f];
                    dp[i][j][0]+=dp[i-1][j][f];
                }
                for (int h=0;h<4;h++) {
                    dp[i][j][h] %= mod1;
                    dp[i][j + 1][h] %= mod1;
                }

        }
    }
    }
    cout<<((dp[n][k][0]+dp[n][k][1])%mod1+dp[n][k][2]+dp[n][k][3])%mod1;



}