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
vector <vector <int> > g;
ll pes[400000];
vector <int> used,used1;
ll cnt=0,cnt1;
bool ok=false,ok1=false;

void dfs(int s,int f)
{
    if (ok==false)
        return;
    used[s]=f;
    if (f&1)
        cnt++;
    for (auto to:g[s])
    {
        if (used[to]==0)
            dfs(to,3-f);
        else
        {
            if (used[to]!=3-f)
            {
                ok=false;
                return;
            }
        }
    }
}
void dfs1(int s,int f)
{
    if (ok1==false)
        return;
    used1[s]=f;
    if (f&1)
        cnt1++;
    for (auto to:g[s])
    {
        if (used1[to]==0)
            dfs1(to,3-f);
        else
        {
            if (used1[to]!=3-f)
            {
                ok1=false;
                return;
            }
        }
    }
}
int main() {
  //  ios_base::sync_with_stdio(0);
  //  cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    ll f=1;
    for (int i=0;i<400000;i++)
    {
        pes[i]=f,f*=2,f%=mod1;
    }
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        ll ans=1;
        cin>>n>>m;
        g=vvi (n);
        used=vi(n,0);
        used1=vi(n,0);
        while (m--)
        {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
        }
        bool ko=false;
        for (int i=0;i<n;i++)
        {
            if (used[i]==0)
            {
                ok=true,ok1=true;
                cnt=0,cnt1=0;
                dfs(i,2);
                dfs1(i,1);
                if (!ok&&!ok1)
                {
                    ko=true;
                    break;
                }
                else
                {
                    ll tt=0;
                    if (ok)
                    {
                        tt+=pes[cnt];
                        tt%=mod1;
                    }
                    if (ok1)
                    {
                        tt+=pes[cnt1];
                        tt%=mod1;
                    }
                    ans*=tt;
                    ans%=mod1;
                }
            }
        }
        if (ko)
        {
            cout<<0<<'\n';
        }
        else
            cout<<ans<<'\n';
    }




}