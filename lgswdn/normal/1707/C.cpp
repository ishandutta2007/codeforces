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

int n,m,tot,fa[N][29],d[N],sz[N],dfn[N],tick,tag[N];

int id[N];
int find(int i) {return i==id[i]?i:id[i]=find(id[i]);}
void unite(int u,int v) {id[find(u)]=find(v);}

vi e[N];
pii p[N];

void dfs(int u,int ff) {
    dfn[u]=++tick, sz[u]=1;
    d[u]=d[ff]+1;
    fa[u][0]=ff;
    rep(h,1,20) fa[u][h]=fa[fa[u][h-1]][h-1];
    for(auto v:e[u]) if(v!=ff) {
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
void dfs2(int u,int ff) {
    tag[u]+=tag[ff];
    for(auto v:e[u]) if(v!=ff) {
        dfs2(v,u);
    }
}

signed main() {
    n=read(), m=read();
    rep(i,1,n) id[i]=i;
    rep(i,1,m) {
        int u=read(), v=read();
        if(find(u)!=find(v)) {
            unite(u,v);
            e[u].emplace_back(v), e[v].emplace_back(u);
        } else {
            p[++tot]=pii(u,v);
        }
    }
    dfs(1,0);
    rep(i,1,tot) {
        int u=p[i].fi, v=p[i].se;
        if(d[u]>d[v]) swap(u,v);
        if(dfn[u]<=dfn[v]&&dfn[v]<dfn[u]+sz[u]) {
            tag[v]++;
            per(h,20,0) if(d[fa[v][h]]>d[u]) v=fa[v][h];
            tag[v]--;
            tag[1]++;
        } else {
            tag[u]++, tag[v]++;
        }
    }
    dfs2(1,0);
    rep(i,1,n) {
        if(tag[i]==tot) putchar('1');
        else putchar('0');
    }
    puts("");
    return 0;
}