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
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 1e9+21;
int add(int a,int b)
{
    a+=b;
    if (a>=mod1)
        return a-mod1;
    return a;
}

int mult(int a,int b)
{
    return 1ll*a*b%mod1;
}

int sub(int a,int b)
{
    a-=b;
    if (a<0)
        return a+mod1;
    return a;
}

int bin_pow(int base,ll deg)
{
    if (deg==0)
        return 1;
    int t=bin_pow(base,deg/2);
    if (deg&1)
        return 1ll*t*t%mod1*base%mod1;
    else
        return 1ll*t*t%mod1;
}
int par[MAXN],ranks[MAXN],xm[MAXN];
void make_set(int s)
{
    par[s]=s;
    ranks[s]=0;
    xm[s]=s;
}
int find_set(int s)
{
    if (par[s]==s)
        return s;
    return par[s]=find_set(par[s]);
}
void union_sets(int u,int v)
{
    u=find_set(u);
    v=find_set(v);
    if (u!=v)
    {
        if (ranks[u]<ranks[v])
            swap(u,v);
        par[v]=u;
        xm[u]=min(xm[u],xm[v]);
        if (ranks[u]==ranks[v])
            ranks[u]++;
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii > a(n);
    for (int i=0;i<m;i++)
        make_set(i+1);
    make_set(0);
    rep(i, n) {
        int k;
        cin >> k;
        if (k == 2) {
            cin >> a[i].fi >> a[i].se;
            if (a[i].fi < a[i].se)
                swap(a[i].fi, a[i].se);
        } else
            cin >> a[i].fi;
    }
    vector<pair<int, int> > b(m + 1,{-1,-1});
    for (int i=0;i<n;i++)
    {
        pii now=a[i];
        now={xm[find_set(now.fi)],xm[find_set(now.se)]};
        if (now.fi!=now.se)
        {
            if (now.fi<now.se)
                swap(now.fi,now.se);
            assert(b[now.fi].fi==-1);
            b[now.fi]={now.se,i};
            union_sets(now.fi,now.se);
        }
    }
    vector <int> ans;
    for (int i=1;i<=m;i++)
    {
        if (b[i].se!=-1)
            ans.pb(b[i].se);
    }
    cout<<bin_pow(2,ans.size())<<" "<<ans.size()<<'\n';
    sort(all(ans));
    for (auto to:ans)
        cout<<to+1<<" ";
    cout<<'\n';
}

int main() {
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int _t;
    _t=1;
//    cin>>_t;
    while (_t--)
        solve();
    #ifdef Mip182
    cout<<'\n'<<"Time : "<<(double)(clock())/CLOCKS_PER_SEC<<'\n';
    #endif
}