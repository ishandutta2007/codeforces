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
int dp[500][500];
int main() {
//    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int n;
    cin>>n;
    vector <int> a(n);
    rep(i,n)
    cin>>a[i];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            dp[i][j]=-INF;
    }
    rep(i,n)
    dp[i][i]=a[i];
    for (int s=2;s<=n;s++)
    {
        for (int i=0;i<=n-s;i++)
        {
            for (int j=i;j<i+s-1;j++)
            {
                if (dp[i][j]!=-INF&&dp[i][j]==dp[j+1][i+s-1])
                    dp[i][i+s-1]=dp[i][j]+1;
            }
        }
    }
//    for (int i=0;i<n;i++)
//    {
//        for (int j=0;j<n;j++)
//            cout<<dp[i][j]<<" ";
//        cout<<'\n';
//    }
    vector <int> pref(n,INF);
    for (int i=0;i<n;i++)
    {
        if (dp[0][i]!=-INF)
            pref[i]=1;
    }
//    for (int i=0;i<n;i++)
//    cout<<pref[i]<<" ";
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if (dp[j+1][i]!=-INF)
            {
                pref[i]=min(pref[i],pref[j]+1);
            }
        }
    }
//    for (int i=0;i<n;i++)
//        cout<<pref[i]<<" ";

    cout<<pref[n-1];




}