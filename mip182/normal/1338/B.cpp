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
const int MAXN = 1e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
vvi g;
int dp[MAXN];
int sz[MAXN];
int dpp[MAXN];
int ans=0;
bool ok=false;
void dfs(int s,int p)
{
    if (ok)
        return;
    int one=0,one1=0;
    for (auto to:g[s])
    {
        if (to==p)
            continue;
        dfs(to,s);
        if (dp[to]==1)
            one1++;
        else
            one++;
    }
    if (one>0&&one1>0)
    {
        ok=true;
        return;
    } else
    {
        if (one1>0)
            dp[s]=0;
        else
            dp[s]=1;
    }
}
void dfss(int s,int p)
{
    int cnt=0,nol=0;
    int other=0;
    for (auto to:g[s])
    {
        if (to==p)
            continue;
        dfss(to,s);
        dpp[s]+=dpp[to];
        cnt++;
        if (dpp[to]==0)
            nol++;
        else
            other++;
    }
    if (cnt==0&&nol==0)
        dpp[s]=0;
    else
    {
        if (nol>0)
        {
           if (nol==1)
               dpp[s]+=cnt;
           else
               dpp[s]+=cnt-nol+1;
        }
        else
            dpp[s]+=cnt;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n;
    cin>>n;
    g=vvi(n);
    for (int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int ind=0;
    for (int i=0;i<n;i++)
    {
        if (g[i].size()>1)
            ind=i;
    }
    dfs(ind,ind);
 //   sas(0,0);
    if (ok)
        cout<<3<<" ";
    else
        cout<<1<<" ";
    dfss(ind,ind);
    cout<<dpp[ind]<<'\n';
//    for (int i=0;i<n;i++)
//        cout<<dpp[i]<<" ";


}