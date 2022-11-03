// thinking: ~1h
// Lemma: u,v in an edge biconnected component
//        <=> there are two disjoint paths from u to v
//   <= obvious
//   => let's prove if there are two disjoint paths from u to w
//      and w-v then there are two disjoint paths from u to v
//      w-v is not a bridge => another path
//      find the path first intersect u-w u-w then done
// * some vertice on tree <-> virtual tree
//   writing: 45min
// debugging: 33min
#include <bits/stdc++.h>
using namespace std;
const int maxn=300005;
const int maxlog=20;
const int maxm=300005;
int n,he[maxn],ne[maxm<<2],to[maxm<<2],tot,dfn[maxn],low[maxn],sc[maxn],cnt;
int sta[maxn],top,fa[maxlog][maxn],logn;
int he_[maxn],ne_[maxm<<1],to_[maxm<<1],dep[maxn],dfn_[maxn],sz[maxn];
int n_,b[maxn],a[maxn*3];
bool vis[maxn];
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],he[u]=tot++; }
inline void add_edge_(int u,int v) { to_[tot]=v,ne_[tot]=he_[u],he_[u]=tot++; }
void dfs(int u,int pre,bool f)
{
    int i;
    sta[++top]=u,dfn[u]=low[u]=tot++;
    for(i=he[u];~i;i=ne[i])
        if(dfn[to[i]]==-1) dfs(to[i],i,f),low[u]=min(low[u],low[to[i]]);
        else if(i!=(pre^1)) low[u]=min(low[u],dfn[to[i]]);
    if(dfn[u]==low[u])
    {
        if(f)
        {
            do sc[sta[top--]]=cnt; while(sta[top+1]!=u);
            cnt++;
        }
        else if(pre!=-1)
            for(;sta[top--]!=u;);
    }
}
void clear(int u)
{
    int i;
    dfn[u]=-1;
    for(i=he[u];~i;i=ne[i])
        if(dfn[to[i]]>=0)
            clear(to[i]);
}
void dfs(int u)
{
    int i;
    dfn_[u]=tot++,dep[u]=dep[fa[0][u]]+1,sz[u]=1;
    for(i=he_[u];~i;i=ne_[i])
        if(to_[i]!=fa[0][u])
            fa[0][to_[i]]=u,dfs(to_[i]),sz[u]+=sz[to_[i]];
}
inline int lca(int u,int v)
{
    int i;
    if(dep[u]<dep[v]) swap(u,v);
    for(i=logn;i>=0;i--)
        if(dep[u]-(1<<i)>=dep[v])
            u=fa[i][u];
    if(u==v) return u;
    for(i=logn;i>=0;i--)
        if(fa[i][u]!=fa[i][v])
            u=fa[i][u],v=fa[i][v];
    return fa[0][u];
}
inline bool cmp(int x,int y) { return dfn_[x]<dfn_[y]; }
int main()
{
    int i,m,q,u,v,la,_,l;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n;i++) he[i]=-1,dfn[i]=-1;
    while(m--) scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
    for(i=1,cnt=0,top=-1;i<=n;i++)
        if(dfn[i]==-1)
            dfs(i,-1,1);
    for(i=0;i<cnt;i++) he_[i]=-1,/*dfn*/dfn_[i]=-1;
    for(u=1,tot=0;u<=n;u++)
        for(i=he[u];~i;i=ne[i])
            if(sc[u]!=sc[to[i]])
                add_edge_(sc[u],sc[to[i]]);
    for(i=0,fa[0][cnt]=cnt,dep[cnt]=0,tot=0;i<cnt;i++)
        if(/*dfn*/dfn_[i]==-1)
            fa[0][i]=cnt,dfs(i);
    for(logn=0;(2<<logn)<=cnt;logn++);
    for(i=1;i<=logn;i++)
        for(u=0;u<=cnt;u++)
            fa[i][u]=fa[i-1][fa[i-1][u]];
    for(i=0;i<cnt;i++) he[i]=-1,dfn[i]=-1,vis[i]=0;
    for(_=1,la=0;_<=q;_++)
    {
        scanf("%d%d",&n_,&m);
        for(i=0;i<n_;i++) scanf("%d",&b[i]),a[i]=b[i]=sc[(b[i]+la-1)%n+1];
        for(tot=0,l=n_,i=0;i<m;i++)
            scanf("%d%d",&u,&v),u=sc[(u+la-1)%n+1],v=sc[(v+la-1)%n+1],
            a[l++]=u,a[l++]=v,add_edge(u,v),add_edge(v,u);
        sort(a,a+l,cmp),l=unique(a,a+l)-a;
        for(i=0;i<l-1;i++) a[i+l]=lca(a[i],a[i+1]);
        sort(a,a+(l<<1)-1,cmp),l=unique(a,a+(l<<1)-1)-a;
        for(top=-1,i=0;i<l;i++)
        {
            while(top>=0 && dfn_[a[i]]/*>*/>=dfn_[sta[top]]+sz[sta[top]]) top--;
            if(top>=0 && /**/sta[top]!=cnt && a[i]!=cnt)
                add_edge(sta[top],a[i]),add_edge(a[i],sta[top]);
            sta[++top]=a[i];
        }
        top=-1,dfs(b[0],-1,0);
        for(i=0;i<=top;i++) vis[sta[i]]=1;
        for(i=0;i<n_;i++)
            if(!vis[b[i]])
                break;
        if(i>=n_) printf("YES\n"),(la+=_)%=n;
        else printf("NO\n");
        for(i=0;i<=top;i++) vis[sta[i]]=0;
        // for(i=0;i<l;i++) he[i]=-1;
        clear(b[0]);
        for(i=0;i<l;i++) he[a[i]]=-1;
    }
    return 0;
}