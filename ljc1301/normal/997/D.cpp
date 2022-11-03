#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kcz=998244353;
const int maxn=4005;
const int maxk=40;
int n,k,he[maxn],ne[maxn<<1],to[maxn<<1],tot;
ll f[maxn][maxk],g[maxn][maxk],ttt[maxn][maxk],h[maxk],t[maxk],inv[maxk<<1],fac[maxk<<1],invfac[maxk<<1];
#define add(x,y) (((x)+=(y))>=kcz)?(x)-=kcz:0
#define sub(x,y) (((x)-=(y))<0)?(x)+=kcz:0
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],he[u]=tot++; }
inline void calcinv(const ll *f,ll *g) // f[0]=1
{
    int i,j;
    for(i=0;i<=k;i++) g[i]=!i;
    for(i=0;i<k;i++)
        for(j=1;i+j<=k;j++)
            (g[i+j]+=(kcz-f[j])*g[i])%=kcz;
}
void dfs1(int u,int fa) // calc f: ignore to-fa; 1+xf+x^2f^2+...=1/(1-xf)
{
    int i,j;
    for(i=0;i<=k;i++) f[u][i]=!i;
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa)
            for(dfs1(to[i],u),j=0;j<k;j++)
                sub(f[u][j+1],g[to[i]][j]);
    calcinv(f[u],g[u]);
}
void dfs2(int u,int fa)
{
    int i,j;
    for(i=0;i<=k;i++) ttt[u][i]=g[u][i];
    if(fa==-1)
        for(i=0;i<=k;i++)
            add(h[i],g[u][i]);
    else
    {
        for(i=0;i<k;i++) sub(f[u][i+1],g[fa][i]);
        calcinv(f[u],g[u]);
        for(i=0;i<=k;i++) add(h[i],g[u][i]);
        // printf("%d:",u); for(i=0;i<=k;i++) printf(" %lld",f[fa][i]); printf("\n");
    }
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa)
        {
            for(j=0;j<k;j++) add(f[u][j+1],g[to[i]][j]);
            calcinv(f[u],g[u]),dfs2(to[i],u);
            for(j=0;j<k;j++) sub(f[u][j+1],g[to[i]][j]);
        }
    for(i=0;i<=k;i++) g[u][i]=ttt[u][i];
}
inline void solve()
{
    int i,u,v;
    for(tot=0,i=1;i<=n;i++) he[i]=-1;
    for(i=1;i<n;i++) scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
    for(i=0;i<=k;i++) h[i]=0;
    dfs1(1,-1),dfs2(1,-1);
}
int main()
{
    int k_,i,m;
    ll ans;
    scanf("%d%d%d",&n,&m,&k_),k=k_>>1;
    if(k_&1) { printf("0\n"); return 0; }
    solve();
    for(i=0;i<=k;i++) t[i]=h[i];
    n=m,solve();
    for(inv[1]=fac[0]=fac[1]=invfac[0]=invfac[1]=1,i=2;i<=(k<<1);i++)
    {
        inv[i]=kcz-(kcz/i)*inv[kcz%i]%kcz;
        fac[i]=fac[i-1]*i%kcz;
        invfac[i]=invfac[i-1]*inv[i]%kcz;
    }
    // for(i=0;i<=k;i++) printf("%lld ",t[i]); printf("\n");
    // for(i=0;i<=k;i++) printf("%lld ",h[i]); printf("\n");
    for(i=0,ans=0;i<=k;i++)
        (ans+=h[i]*t[k-i]%kcz*invfac[i<<1]%kcz*invfac[k_-(i<<1)])%=kcz;
    printf("%lld\n",ans*fac[k_]%kcz);
    return 0;
}