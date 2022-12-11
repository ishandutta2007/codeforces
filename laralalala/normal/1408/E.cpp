#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

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
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll a[MAXN];
ll b[MAXN];
vector<pii> vp[MAXN];
vector<int> gg[MAXN];
int cant[MAXN];
int el_tipo[MAXN];
int d[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

bool join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return 0;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
    return 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m,n;
    cin >> m >> n;
    for(int i=0;i<m;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];

    ll base=0;
    for(int i=0;i<m;i++)
    {
        int x;
        cin >> x;
        cant[i]=x;
        for(int j=0;j<x;j++)
        {
            int v;
            cin >> v;
            v--;
            gg[i].push_back(v);
            vp[v].push_back(pii(a[i],i));
            base+=b[v]+a[i];
        }
    }
//    db(base)

    ll res=0;
    for(int i=0;i<n;i++)
    {
        if(vp[i].empty())
            continue;
        sort(allr(vp[i]));
//        db("")
//        db(vp[i].size())
//        db(i)
        int pos=0;
//        while(pos<vp[i].size() && cant[vp[i][pos].s]==1)
//            pos++;
        if(pos==vp[i].size())
        {
            el_tipo[i]=-1;
            continue;
        }
        int p=vp[i][pos].s;
//        db(p)
        el_tipo[i]=p;
        cant[p]--;
        res+=a[p]+b[i];
    }
//    db("r1")
//    db(res)
//    db("")

    vector<pip> edges;
    for(int i=0;i<m;i++)
    {
        for(auto y : gg[i])
        {
            if(el_tipo[y]==i)
                continue;
//            if(el_tipo[y]==-1)
//            {
//                res+=a[i]+b[y];
//                continue;
//            }
//            cout << y << ' ' << a[i]+b[y] << ' ' << i << ' ' << el_tipo[y] << '\n';
            edges.push_back(pip(a[i]+b[y],pii(i,el_tipo[y])));
        }
    }

    for(int i=0;i<m;i++)
        d[i]=-1;
    sort(allr(edges));
    for(auto y : edges)
    {
        ll w=y.f;
        int u=y.s.f;
        int v=y.s.s;
        if(join(u,v))
        {
//            cout << u << ' ' << v << '\n';
            res+=w;
        }
    }

    db(base-res)

    return 0;
}
/**
3 2
1 2 3
4 5
2 1 2
2 1 2
2 1 2
**/