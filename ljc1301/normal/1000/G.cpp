#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300005;
const int maxlog=20;
int n,logn,tot,he[maxn],ne[maxn<<1],to[maxn<<1],fa[maxlog][maxn],dep[maxn];
ll a[maxn],val[maxn<<1],md[maxn],smd[maxn],mu[maxn],upc[maxn],dnc[maxn];
// md: from u downto subtree max(contain u), mu: up; smd: md[]-a[]-max(0,val[]-val[]+md[]) to root
// upc: to root; dnc: root to u (contain a[u] not a[rt])
inline void add_edge(int u,int v,int c) { to[tot]=v,val[tot]=c,ne[tot]=he[u],he[u]=tot++; }
void dfs1(int u)
{
    int i;
    md[u]=a[u];
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa[0][u])
        {
            fa[0][to[i]]=u;
            dnc[to[i]]=dnc[u]-val[i]+a[to[i]];
            upc[to[i]]=upc[u]-val[i^1]+a[to[i]];
            dep[to[i]]=dep[u]+1;
            dfs1(to[i]);
            md[u]+=max(0ll,-val[i]-val[i^1]+md[to[i]]);
        }
}
void dfs2(int u)
{
    int i;
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa[0][u])
        {
            mu[to[i]]=a[to[i]]+max(0ll,mu[u]+md[u]-a[u]-val[i]-val[i^1]-max(0ll,-val[i]-val[i^1]+md[to[i]]));
            smd[to[i]]=smd[u]+md[to[i]]-a[to[i]]-max(0ll,-val[i]-val[i^1]+md[to[i]]);
            dfs2(to[i]);
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
int main()
{
    int q,i,u,v,x,l;
    scanf("%d%d",&n,&q);
    for(i=1,tot=0;i<=n;i++) he[i]=-1,scanf("%lld",&a[i]);
    for(i=1;i<n;i++) scanf("%d%d%d",&u,&v,&x),add_edge(u,v,x),add_edge(v,u,x);
    for(logn=0;(1<<logn)<n;logn++);
    fa[0][1]=fa[0][0]=0,upc[1]=dnc[1]=0,dep[0]=0,dfs1(1),mu[1]=a[1],smd[1]=0,dfs2(1);
    for(i=1;i<=logn;i++)
        for(u=0;u<=n;u++)
            fa[i][u]=fa[i-1][fa[i-1][u]];
    while(q--)
    {
        scanf("%d%d",&u,&v),l=lca(u,v);
        printf("%lld\n",upc[u]+dnc[v]+mu[l]-upc[l]-dnc[l]+smd[u]+smd[v]-2*smd[l]+md[l]-a[l]);
    }
    return 0;
}