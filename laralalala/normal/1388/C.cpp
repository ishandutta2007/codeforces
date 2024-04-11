#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
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
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<ll> g[MAXN];
ll a[MAXN],h[MAXN];
ll s2[MAXN];
bool ok;
bool mk[MAXN];

void dfs(int u)
{
    mk[u]=1;
    ll sum=0;
    s2[u]=0;
    for(auto v : g[u])
    {
        if(mk[v])
            continue;
        dfs(v);
        sum+=h[v];
        s2[u]+=s2[v];
    }
    s2[u]+=a[u];
    sum-=a[u];
    if(sum>h[u])
        ok=0;
    if((h[u]-sum)&1)
        ok=0;
    if(h[u]>s2[u])
        ok=0;
//    db("")
//    db(u)
//    cout << h[u] << ' ' << sum << ' ' << h[u]-sum << ' ' << 2*a[u] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        ok=1;
        for(int i=0;i<n;i++)
        {
            g[i].clear();
            mk[i]=0;
        }
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<n;i++)
            cin >> h[i];
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0);

        if(ok)
            db("YES")
        else
            db("NO")
    }

    return 0;
}
/**
2
7 4
1 0 1 1 0 1 0
4 0 0 -1 0 -1 0
1 2
1 3
1 4
3 5
3 6
3 7
5 11
1 2 5 2 1
-11 -2 -6 -2 -1
1 2
1 3
1 4
3 5

2
4 4
1 1 1 1
4 1 -3 -1
1 2
1 3
1 4
3 13
3 3 7
13 1 4
1 2
1 3
**/