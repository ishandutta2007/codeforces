#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3,Os")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
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
const int MAXN = 1e4+100;
const int MAXR = 1000;
const int INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int dp[MAXN][MAXR];
int dd[MAXN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    clock_t times=clock();
    int n,m;
    cin>>n>>m;
    rep(i,m)
        cin>>dd[i];
    sort(dd,dd+m);
    int g,r;
    cin>>g>>r;
    for (int i=0;i<MAXN;i++)
    {
        for (int j=0;j<MAXR;j++)
            dp[i][j]=INF;
    }
    dp[0][0]=0;
    priority_queue <pair <int,int > > s;
    s.push({0,0});
    while (!s.empty())
    {
        if (clock()-times>=990)
           break;
        auto to=s.top();
        int d=-(to).fi;
        short x=(to).se%m,y=(to).se/m;
        s.pop();
        if (d<dp[x][y])
            continue;
        if (x!=m-1)
        {
            int ha=(y+dd[x+1]-dd[x])%g;
            if (y+dd[x+1]-dd[x]<=g&&dp[x+1][ha]>d+dd[x+1]-dd[x]+((ha)==0)*r) {
                dp[x + 1][ha] =
                        d + dd[x + 1] - dd[x] + ((ha) == 0) * r;
                //     cout<<x+1<<" "<<(y+dd[x+1]-dd[x])%g<<" "<<dp[x+1][(y+dd[x+1]-dd[x])%g]<<'\n';
                s.push({-dp[x + 1][ha], x + 1+ m*ha});
            }
        }
        //    cout<<x<<" "<<y<<" "<<y+dd[x]-dd[x-1]<<" "<<dp[x-1][(y+dd[x]-dd[x-1])%g]<<" "<<d+dd[x]-dd[x-1]+(((y+dd[x]-dd[x-1])%g)==0)*r<<'\n';
        if (x!=0)
        {
            // s.erase({dp[x-1][(y+dd[x]-dd[x-1])%g],{x-1,(y+dd[x]-dd[x-1])%g}});
            int ha=(y+dd[x]-dd[x-1])%g;
            if (y+dd[x]-dd[x-1]<=g&&dp[x-1][ha]>d+dd[x]-dd[x-1]+((ha)==0)*r) {
                dp[x - 1][ha] =
                        d + dd[x] - dd[x - 1] + ((ha) == 0) * r;
                //cout<<x-1<<" "<<(y+dd[x]-dd[x-1])%g<<" "<<dp[x][(y+dd[x]-dd[x-1])%g]<<'\n';
                s.push({-dp[x - 1][ha], x - 1+m*ha});
            }
        }
    }
//    for (int i=0;i<m;i++)
//    {
//        for (int j=0;j<g;j++)
//            cout<<dp[i][j]<<" ";
//        cout<<'\n';
//    }
    int mx=INF;
    for (int j=0;j<g;j++) {
        if (j!=0)
            mx = min(mx, dp[m - 1][j]);
        else {
            if (dp[m-1][j]!=INF)
                mx = min(mx, dp[m - 1][j] - r);
        }
    }
    if (mx==INF)
        cout<<-1;
    else
        cout<<mx;





}