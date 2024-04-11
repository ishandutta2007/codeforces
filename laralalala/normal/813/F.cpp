#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

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
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (int)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

map<pii,int> last;
vector<pip> inis[MAXN];
vector<pip> fins[MAXN];
int d[MAXN],t[MAXN];
bool res[MAXN];

struct update{
    int u,v;
    int du,dv;
    update(int _u,int _v,int _du,int _dv) : u(_u),v(_v),du(_du),dv(_dv) {}
};

stack<update> updates;

void rollback()
{
    update tt=updates.top();
    updates.pop();
    d[tt.u]=tt.du;
    d[tt.v]=tt.dv;
    t[tt.v]=0;
}

pii find(int u,int dis)
{
    if(d[u]<0)
        return pii(u,dis);
    return find(d[u],dis+t[u]);
}

bool join(pii p)
{
    int u=p.first;
    int v=p.s;
    pii uu=find(u,0);
    pii vv=find(v,0);
    int sum=uu.s+vv.s+1;
    sum&=1;
    u=uu.first;
    v=vv.first;
    updates.push(update(u,v,d[u],d[v]));
    if(uu.f==vv.f)
    {
        if(sum)
            return 0;
        else
            return 1;
    }

    if(d[u]>d[v])
        swap(u,v);

    d[u]+=d[v];
    d[v]=u;
    t[v]=sum;
    return 1;
}

void solve(int l,int r)
{
    if(l==r)
        return ;
    int mid=(l+r)>>1;
    ///l,mid
    int sz=updates.size();

    bool ok=1;
    for(int i=mid+1;i<=r;i++)
        if(fins[i].size() && fins[i].back().first<=l)
            ok&=join(fins[i].back().second);
    if(ok)
        solve(l,mid);
    else
    {
        for(int i=l;i<=mid;i++)
            res[i]=1;
    }
    while(updates.size()!=sz)
        rollback();

    ///mid+1,r
    ok=1;
    for(int i=l;i<=mid+1;i++)
        if(inis[i].size() && inis[i].back().first>r)
            ok&=join(inis[i].back().second);
    if(ok)
        solve(mid+1,r);
    else
    {
        for(int i=mid+1;i<=r;i++)
            res[i]=1;
    }
    while(updates.size()!=sz)
        rollback();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    for(int i=0;i<q;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        pii x=pii(u,v);
        if(last[x])
        {
            int p=last[x]-1;
            inis[p].push_back(pip(i,x));
            fins[i].push_back(pip(p,x));
            last[x]=0;
        }
        else
            last[x]=i+1;
    }

    for(auto y : last)
        if(y.second)
        {
            inis[y.second-1].push_back(pip(q,y.first));
            fins[q].push_back(pip(y.second-1,y.first));
        }

    for(int i=0;i<n;i++)
        d[i]=-1;
    if(inis[0][0].first==q)
        join(inis[0][0].second);

    solve(0,q-1);

    for(int i=0;i<q;i++)
    {
        if(!res[i])
            db("YES")
        else
            db("NO")
    }

    return 0;
}
/**
3 5
2 3
1 3
1 2
1 2
1 2
**/