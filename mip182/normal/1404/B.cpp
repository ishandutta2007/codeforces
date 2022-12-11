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
int n,a,b,da,db;
vvi g;
int ind;
int mx;
vector <bool> used;
int h;
void dfs(int s,int p,int ok)
{
    if (mx<ok)
        mx=ok,ind=s;
    if (ok<=h)
    used[s]=true;
    for (auto to:g[s])
    {
        if (to==p)
            continue;
        dfs(to,s,ok+1);
    }
}
void solve()
{
    cin>>n>>a>>b>>da>>db;
  //  cout<<n<<" "<<a<<" "<<b<<" "<<da<<" "<<db<<'\n';
    a--,b--;
    g=vvi(n);
    mx=-1,ind=-1;
    for (int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    used=vb(n);
    dfs(0,-1,0);
    int w=ind;
    mx=-1,ind=-1;
    dfs(w,-1,0);
    int diam=mx+1;
    if (1+2*da>=diam)
    {
        cout<<"Alice\n";
        return;
    }
    used=vb(n);
    h=da;
    dfs(a,-1,0);
    if (used[b])
    {
        cout<<"Alice\n";
        return;
    }
    if (db>=2*da+1)
    {
        cout<<"Bob\n";
        return;
    }
    cout<<"Alice\n";
//    cout<<diam<<'\n';
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