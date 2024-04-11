// LUOGU_RID: 90784371
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define eb emplace_back
#define y1 yylyylyylyyl
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
 
long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=1e5+9;
int n,q,f[N][2],g[N],rt,dfn[N],sz[N],son[N],tick;
vp e[N];
pii p[N];

void dfs1(int u,int fa) {
    for(auto ed:e[u]) {
        int v=ed.fi, w=ed.se;
        if(v==fa) continue;
        dfs1(v,u);
        if(f[v][0]+w>f[u][1]) f[u][1]=f[v][0]+w;
        if(f[u][1]>f[u][0]) swap(f[u][0],f[u][1]), son[u]=v;
    }
}
void dfs2(int u,int fa) {
    for(auto ed:e[u]) {
        int v=ed.fi, w=ed.se;
        if(v==fa) continue;
        if(v==son[u]) g[v]=max(g[u],f[u][1])+w;
        else g[v]=max(g[u],f[u][0])+w;
        dfs2(v,u);
    }
}
void dfs3(int u,int fa) {
    dfn[u]=++tick, sz[u]=1;
    for(auto ed:e[u]) {
        int v=ed.fi; if(v==fa) continue;
        dfs3(v,u); sz[u]+=sz[v];
    }
}

int s[N];
int lb(int x) {return x&-x;}
void add(int x,int y) {for(;x<=n;x+=lb(x)) s[x]+=y;}
int sum(int x,int y=0) {for(;x;x-=lb(x)) y+=s[x]; return y;}
int qry(int x,int y) {return sum(y)-sum(x-1);}

signed main() {
    n=read();
        rep(i,2,n) {
        int u=read(), v=read(), w=read();
        e[u].eb(pii(v,w)), e[v].eb(pii(u,w));
    }
    dfs1(1,0);
    dfs2(1,0);
    rep(i,1,n) p[i]=pii(max(g[i],f[i][0]),i);
    sort(p+1,p+n+1);
    rt=p[1].se;
    dfs3(rt,0);
    q=read();
    while(q--) {
        int l=1, x=read(), ans=0;
        rep(r,1,n) {
            while(l<=n&&p[l].fi+x<p[r].fi) {
                int u=p[l].se;
                ans=max(ans,qry(dfn[u],dfn[u]+sz[u]-1));
                add(dfn[u],-1);
                l++;
            }
            add(dfn[p[r].se],1);
        }
        while(l<=n) {
            int u=p[l].se;
            ans=max(ans,qry(dfn[u],dfn[u]+sz[u]-1));
            add(dfn[u],-1);
            l++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}