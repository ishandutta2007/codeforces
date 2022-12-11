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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    ll n,h,l,r;
    cin>>n>>h>>l>>r;
    vector <int> dp(h,-1);
    vector <int> dpp(h,-1);
    dp[0]=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        for (int j=0;j<h;j++)
        {
            int y=(j+x)%h;
            int z=(y-1+h)%h;
            if (dp[j]!=-1)
            {
                if (y>=l&&y<=r)
                    dpp[y]=max(dpp[y],dp[j]+1);
                else
                dpp[y]=max(dpp[y],dp[j]);
                if (z>=l&&z<=r)
                    dpp[z]=max(dpp[z],dp[j]+1);
                else
                    dpp[z]=max(dpp[z],dp[j]);
            }
        }
        for (int j=0;j<h;j++)
        {
            dp[j]=dpp[j];
            dpp[j]=-1;
        }
    }
    int ans=0;
    for (int i=0;i<h;i++)
        ans=max(dp[i],ans);
    cout<<ans;
}