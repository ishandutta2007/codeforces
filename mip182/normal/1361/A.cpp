//#define _GLIBCXX_DEBUG
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
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN


const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
vvi g;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int n,m;
    cin>>n>>m;
    g=vvi(n);
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector <pair <int,int> > p(n);
    for (int i=0;i<n;i++)
        cin>>p[i].fi,p[i].se=i;
    vector <int> ans;
    bool ok=true;
    sort(all(p));
    vector <int> now(n,-1);
    for (int i=0;i<n;i++)
    {
        vector <int> f;
        for (auto to:g[p[i].se])
        {
            if (now[to]!=-1)
                f.pb(now[to]);
        }
        sort(all(f));
        f.resize(unique(all(f))-f.begin());
        f.pb(1e9);
        int cur=1;
        while (cur<f.size())
        {
            if (f[cur-1]==cur)
                cur++;
            else
                break;
        }
        if (cur!=p[i].fi)
        {
            ok=false;
            break;
        }
        now[p[i].se]=p[i].fi;
    }
    if (ok)
    {
        for (auto to:p)
            cout<<to.se+1<<" ";
    }
    else
        cout<<-1;


    //n=1 ?
    //recursion - matrix exponential
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
}