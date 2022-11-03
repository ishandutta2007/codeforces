#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
const int maxm=200005<<1;
const int maxk=200005;
const int maxlog=19;
int n,logn,he[maxn],ne[maxm],to[maxm],tot,dfn[maxn],low[maxn],clk,sta[maxn],top,c[maxn];
int he1[maxn],ne1[maxn<<1],to1[maxn<<1],tot1,fa[maxlog][maxn],dep[maxn],tag1[maxn],tag2[maxn];
bool vis[maxn];
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],he[u]=tot++; }
inline void add_edge1(int u,int v) { to1[tot1]=v,ne1[tot1]=he1[u],he1[u]=tot1++; }
void dfs(int u,int pre)
{
    int i;
    low[u]=dfn[u]=clk++,sta[++top]=u;
    for(i=he[u];~i;i=ne[i])
        if((i^pre)!=1)
        {
            if(dfn[to[i]]==-1) dfs(to[i],i),low[u]=min(low[u],low[to[i]]);
            else low[u]=min(low[u],dfn[to[i]]);
        }
    if(low[u]==dfn[u])
    {
        c[u]=++tot1;
        while(sta[top]!=u) c[sta[top]]=tot1,top--;
        top--;
    }
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
void prework(int u)
{
    int i;
    vis[u]=1;
    for(i=he1[u];~i;i=ne1[i])
        if(!vis[to1[i]])
            fa[0][to1[i]]=u,dep[to1[i]]=dep[u]+1,prework(to1[i]);
}
void check(int u)
{
    int i;
    vis[u]=1;
    for(i=he1[u];~i;i=ne1[i])
        if(!vis[to1[i]])
            check(to1[i]),tag1[u]+=tag1[to1[i]],tag2[u]+=tag2[to1[i]];
    // if(tag1[u]>0 && tag1[u]<tag2[u]) throw 0xdead;
    if(tag1[u] && tag2[u]) throw 0xdead;
}
int main()
{
    int m,u,v,l,q,i;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1,tot=0;i<=n;i++) he[i]=-1,dfn[i]=-1;
    while(m--) scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
    for(clk=0,tot1=0,u=1;u<=n;u++)
        if(dfn[u]==-1)
            top=-1,dfs(u,-1);
    for(i=1,n=tot1;i<=n;i++) he1[i]=-1,vis[i]=0,tag1[i]=tag2[i]=0;
    for(i=0,tot1=0;i<tot;i+=2)
        if(c[to[i]]!=c[to[i]^1])
            add_edge1(c[to[i]],c[to[i^1]]),add_edge1(c[to[i^1]],c[to[i]]);
    for(u=1,fa[0][0]=0;u<=n;u++)
        if(!vis[u])
            fa[0][u]=0,dep[u]=0,prework(u);
    for(logn=0;(1<<logn)<n;logn++);
    for(i=1;i<=logn;i++)
        for(u=0;u<=n;u++)
            fa[i][u]=fa[i-1][fa[i-1][u]];
    try
    {
        while(q--)
        {
            scanf("%d%d",&u,&v),u=c[u],v=c[v],l=lca(u,v);
            if(l==0) throw 0xdead;
            tag1[u]++,tag1[l]--;
            // tag2[u]++,tag2[v]++,tag2[l]-=2;
            tag2[v]++,tag2[l]--;
        }
        for(u=1;u<=n;u++) vis[u]=0;
        for(u=1;u<=n;u++)
            if(!vis[u])
                check(u);
        printf("Yes\n");
    }
    catch(int) { printf("No\n"); }
    return 0;
}