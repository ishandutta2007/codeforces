#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=2e5+9;
int n,m,q,w[N],tot,f[N][29],d[N],dfn[N],tick;
vi e[N];

int id[N];
int find(int i) {return i==id[i]?i:id[i]=find(id[i]);}

void dfs(int u) {
    if(u<=n) dfn[u]=++tick;
    rep(h,1,18) f[u][h]=f[f[u][h-1]][h-1];
    for(auto v:e[u]) {
        f[v][0]=u, d[v]=d[u]+1;
        dfs(v);
    }
}
int lca(int u,int v) {
    if(d[u]<d[v]) swap(u,v);
    per(h,18,0) if(d[f[u][h]]>=d[v]) u=f[u][h];
    per(h,18,0) if(f[u][h]!=f[v][h]) u=f[u][h], v=f[v][h];
    return u==v?u:f[u][0];
}

namespace SegT {
    int ls[N<<1],rs[N<<1],tot=1;
    pii t[N<<1];
    pii operator + (pii x,pii y) {
        pii r(0,0);
        if(dfn[x.fi]<dfn[y.fi]) r.fi=x.fi; else r.fi=y.fi;
        if(dfn[x.se]>dfn[y.se]) r.se=x.se; else r.se=y.se;
        return r;
    }
    void build(int p,int l,int r) {
        t[p]=pii(l,l); if(l==r) return; int mid=l+r>>1;
        build(ls[p]=++tot,l,mid), build(rs[p]=++tot,mid+1,r);
        t[p]=t[ls[p]]+t[rs[p]];
    }
    pii qry(int p,int l,int r,int x,int y) {
        if(l==x&&r==y) return t[p]; int mid=l+r>>1;
        if(y<=mid) return qry(ls[p],l,mid,x,y);
        else if(x>mid) return qry(rs[p],mid+1,r,x,y);
        else return qry(ls[p],l,mid,x,mid)+qry(rs[p],mid+1,r,mid+1,y);
    }
    void init() {
        rep(i,1,tot) ls[i]=rs[i]=0, t[i].fi=t[i].se=0;
        tot=1;
    }
}

signed main() {
    int T=read();
    while(T--) {
        n=read(), m=read(), q=read(); tot=n, tick=0;
        rep(i,1,2*n) {
            id[i]=i, e[i].clear(), e[i].shrink_to_fit(), d[i]=w[i]=0;
            rep(h,0,18) f[i][h]=0;
        }
        rep(i,1,m) {
            int u=read(), v=read();
            if(find(u)!=find(v)) {
                u=find(u), v=find(v);
                w[++tot]=i;
                e[tot].emplace_back(u), e[tot].emplace_back(v);
                id[u]=tot, id[v]=tot;
            }
        }
        d[tot]=1; dfs(tot);
        SegT::build(1,1,n);
        rep(i,1,q) {
            int l=read(), r=read();
            pii p=SegT::qry(1,1,n,l,r);
            int x=lca(p.fi,p.se);
            printf("%lld ",w[x]);
        }
        puts("");
    }
    return 0;
}