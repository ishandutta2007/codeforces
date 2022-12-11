#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,O3,O2")
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
const int MAXN = 2e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
vector <vpii> g;
vector <vector <bitset<MAXN> > > a;
vector <vector <int> > d;
vector <vector <bool> >good;
int n,m,k;
ll ans=0;

void dp(int now,vector <int> &b,int sum)
{
    if (now==k+1)
    {
        if (sum!=n)
            return;
        for (int i=0;i<b.size();i++)
        {
            for (int j=i+1;j<b.size();j++)
                if (good[b[i]][b[j]])
                    return;
        }
        ans++;
        return;
    }
    for (int i=1;i<=now;i++)
    {
        vector <int> c=b;
        c.pb(now*(k+1)+i);
        dp(now+1,c,sum+d[now][i]);
    }
}
void solve()
{
    cin>>n>>m>>k;
    g=vector <vpii>(n);
    vector <pii> ed(m);
    rep(ii,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        ed[ii]={u,v};
        g[u].pb({w,v});
    }
    for (int i=0;i<n;i++)
        sort(all(g[i]));
    a=vector <vector <bitset<MAXN> > > (k+1);
    d=vector <vector <int> > (k+1,vi(k+1));
    good=vector <vector <bool> >((k+1)*(k+1),vector <bool>((k+1)*(k+1),false));
    for (int i=1;i<=k;i++)
        a[i].resize(i+1);
    for (int i=0;i<n;i++)
    {
        int cnt=1;
        for (auto to:g[i])
        {
            a[g[i].size()][cnt][to.se]=true;
            cnt++;
        }
    }
    for (int i=1;i<=k;i++)
    {
        for (int j=1;j<=i;j++)
            d[i][j]=a[i][j].count();
    }
    for (int i=1;i<=k;i++)
    {
        for (int j=1;j<=i;j++)
        {
            for (int i1=i+1;i1<=k;i1++)
            {
                for (int j1=1;j1<=i1;j1++)
                {
                    if ((a[i][j]|a[i1][j1]).count()!=d[i][j]+d[i1][j1])
                        good[i*(k+1)+j][i1*(k+1)+j1]=true,good[i1*(k+1)+j1][i*(k+1)+j]=true;
                }
            }
        }
    }
    vector <int> b;
    dp(1,b,0);
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef Mip182
    freopen("a.in","r",stdin);
#endif
    int _t;
//    cin>>_t;
    _t=1;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}