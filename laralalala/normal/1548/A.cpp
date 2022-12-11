#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

set<int> g[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> mk(n);
    int cant=n;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].insert(-v);
        g[v].insert(-u);
        if(v>u && !mk[u])
        {
            cant--;
            mk[u]=1;
        }
        if(u>v && !mk[v])
        {
            cant--;
            mk[v]=1;
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t==3)
            db(cant)
        if(t==1)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            cant+=mk[u];
            cant+=mk[v];
            mk[u]=0;
            mk[v]=0;
            g[u].insert(-v);
            g[v].insert(-u);
            if(*g[u].begin()<-u)
                mk[u]=1;
            if(*g[v].begin()<-v)
                mk[v]=1;
            cant-=mk[u];
            cant-=mk[v];
        }
        if(t==2)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            cant+=mk[u];
            cant+=mk[v];
            mk[u]=0;
            mk[v]=0;
            g[u].erase(-v);
            g[v].erase(-u);
            if(!g[u].empty() && *g[u].begin()<-u)
                mk[u]=1;
            if(!g[v].empty() && *g[v].begin()<-v)
                mk[v]=1;
            cant-=mk[u];
            cant-=mk[v];
        }
    }

    return 0;
}