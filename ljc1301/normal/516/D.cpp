#include <bits/stdc++.h>
using namespace std;
// convex
// u-v-w => f[u]>=f[v] or f[w]>=f[v]
typedef long long ll;
const int maxn=100005;
const int maxlog=18;
int n,logn,he[maxn],ne[maxn<<1],to[maxn<<1],tot,rt,fa[maxlog][maxn],tag[maxn],ans;
ll val[maxn<<1],mdep[maxn],smdep[maxn],f[maxn];
inline void add_edge(int u,int v,ll c) { to[tot]=v,val[tot]=c,ne[tot]=he[u],he[u]=tot++; }
void prework(int u,int fa)
{
    int i;
    mdep[u]=smdep[u]=0;
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa)
        {
            prework(to[i],u);
            if(mdep[to[i]]+val[i]>mdep[u]) smdep[u]=max(smdep[u],mdep[u]),mdep[u]=mdep[to[i]]+val[i];
            else smdep[u]=max(smdep[u],mdep[to[i]]+val[i]);
        }
}
void calcf(int u,int fa,ll len)
{
    int i;
    f[u]=max(mdep[u],len);
    if(f[rt]>f[u]) rt=u;
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa)
            calcf(to[i],u,max(len,(mdep[u]==mdep[to[i]]+val[i])?smdep[u]:mdep[u])+val[i]);
}
void init(int u)
{
    int i;
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa[0][u])
            fa[0][to[i]]=u,init(to[i]);
}
void solve(int u)
{
    int i;
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa[0][u])
            solve(to[i]),tag[u]+=tag[to[i]];
    ans=max(ans,tag[u]);
}
int main()
{
    int i,u,v,q;
    ll c;
    scanf("%d",&n);
    for(tot=0,i=1;i<=n;i++) he[i]=-1;
    for(i=1;i<n;i++) scanf("%d%d%lld",&u,&v,&c),add_edge(u,v,c),add_edge(v,u,c);
    prework(1,-1),rt=1,calcf(1,-1,0),fa[0][rt]=fa[0][0]=0,init(rt);
    // for(i=1;i<=n;i++) printf("%lld ",f[i]); printf("\n");
    for(logn=0;(1<<logn)<n;logn++);
    for(i=1;i<=logn;i++)
        for(u=0;u<=n;u++)
            fa[i][u]=fa[i-1][fa[i-1][u]];
    scanf("%d",&q);
    while(q--)
    {
        scanf("%lld",&c);
        for(i=0;i<=n;i++) tag[i]=0;
        for(u=1;u<=n;u++)
        {
            for(i=logn,v=u;i>=0;i--)
                if(fa[i][v] && f[u]-f[fa[i][v]]<=c)
                    v=fa[i][v];
            tag[fa[0][v]]--,tag[u]++;
            assert(f[u]-f[v]<=c);
            // printf("%d ",v);
        }
        ans=0,solve(rt),printf("%d\n",ans);
    }
    // for(i=1;i<=n;i++) printf("%lld ",f[i]); printf("\n");
    return 0;
}