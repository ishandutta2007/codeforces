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
const int MAXN = 2e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int tin[MAXN],tout[MAXN];
int d[MAXN];
int times=0;
int par[MAXN];
vvi g;

void dfs(int s,int p,int cnt)
{
    par[s]=p;
    tin[s]=times++;
    d[s]=cnt;
    for (auto to:g[s])
    {
        if (to==p)
            continue;
        dfs(to,s,cnt+1);
    }
    tout[s]=times++;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n,m;
    cin>>n>>m;
    g=vvi(n);
    rep(i,n-1)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,0,0);
    while (m--)
    {
        int k;
        cin>>k;
        vector <int> check(k);
        for (int i=0;i<k;i++)
        {
            cin>>check[i];
            check[i]--;
        }
        vector <pair <int,int> > a(k);
        rep(i,k)
        {
            a[i]={d[check[i]],check[i]};
        }
        sort(all(a));
//        for (auto to:a)
//            cout<<to.fi<<" "<<to.se<<'\n';
        int was=-1;
        int x=-1;
        vector <int> p;
        bool ok=true;
        for (int i=0;i<k;i++)
        {
            if (was!=a[i].fi)
            {
                was=a[i].fi;
                x=par[a[i].se];
                p.pb(x);
            }
            else
            {
                if (x!=par[a[i].se])
                    ok=false;
            }
        }
        if (!ok)
        {
            cout<<"NO\n";
            continue;
        }
        int h=p.size();
        int xx;
        for (int i=h-2;i>=0;i--)
        {
            if (tin[p[i]]<=tin[p[i+1]]&&tout[p[i]]>=tout[p[i+1]])
            {
                xx=1;
            }
            else
                ok=false;
        }
        if (ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }





}