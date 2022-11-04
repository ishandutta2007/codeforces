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

const int N=1e5+9,inf=0x3f3f3f3f;

int n,q,fa[N][29],dfn[N],d[N],tick,st[N],top,k,b[N],f[N],g[N];
bool flag=0;
vi e[N],t[N],use;

int lca(int u,int v) {
    if(d[u]<d[v]) swap(u,v);
    per(h,20,0) if(d[fa[u][h]]>=d[v]) u=fa[u][h];
    per(h,20,0) if(fa[u][h]!=fa[v][h]) u=fa[u][h], v=fa[v][h];
    return u==v?u:fa[u][0];
}
void dfs0(int u,int faa) {
    fa[u][0]=faa, d[u]=d[faa]+1, dfn[u]=++tick;;
    rep(h,1,20) fa[u][h]=fa[fa[u][h-1]][h-1];
    for(auto v:e[u]) if(v!=faa) {
        dfs0(v,u);
    }
}
void build(vp a) {
    top=1; st[1]=1; sort(a.begin(),a.end()); use.emplace_back(1);
    for(auto p:a) {
        int x=p.se; if(x==1) continue;
        int y=lca(x,st[top]);
        if(y==st[top]) use.emplace_back(x), st[++top]=x;
        else {
            while(top>1&&d[st[top-1]]>d[y]) t[st[top-1]].emplace_back(st[top]), top--;
            t[y].emplace_back(st[top]); top--;
            if(y!=st[top]) use.emplace_back(y), st[++top]=y;
            use.emplace_back(x), st[++top]=x;
        }
    }
    while(top>1) t[st[top-1]].emplace_back(st[top]), top--;
}

void dfs1(int u) {
    int sg=0; f[u]=0;
    for(auto v:t[u]) {
        dfs1(v);
        f[u]+=f[v], sg+=g[v];
        if(b[u]==1&&b[v]==1&&d[v]-d[u]==1) flag=1;
    }
    if(b[u]) g[u]=1, f[u]+=sg;
    else {
        if(sg>1) g[u]=0, f[u]++;
        else if(sg==1) g[u]=1;
        else g[u]=0;
    }
}

signed main() {
    n=read();
    rep(i,2,n) {
        int u=read(), v=read();
        e[u].emplace_back(v), e[v].emplace_back(u);
    }
    dfs0(1,0);
    q=read();
    while(q--) {
        vp a; k=read(); a.resize(k);
        rep(i,0,k-1) a[i].se=read(), b[a[i].se]=1, a[i].fi=dfn[a[i].se];
        build(a);
        dfs1(1);
        if(flag==1) {
            flag=0;
            puts("-1");
        } else printf("%lld\n",f[1]);
        for(auto x:use) b[x]=0, t[x].clear(), t[x].shrink_to_fit();
        use.clear(), use.shrink_to_fit();
    }
    return 0;
}