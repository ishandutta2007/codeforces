#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kcz=1000000007;
const int maxn=500005;
const int maxlogn=21;
int n,logn,x[maxn],tot,he[maxn],ne[maxn<<1],to[maxn<<1],pre[maxn<<1],suf[maxn<<1],st[maxn],en[maxn];
int tofa[maxn],fa[maxlogn][maxn],dep[maxn],f[maxn<<1];
ll fac[maxn];
int father(int x) { return (f[x]==x)?x:(f[x]=father(f[x])); }
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],pre[tot]=suf[tot]=-1,f[tot]=tot,he[u]=tot++; }
void dfs(int u)
{
    int i;
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa[0][u])
            tofa[to[i]]=i^1,fa[0][to[i]]=u,dep[to[i]]=dep[u]+1,dfs(to[i]);
}
inline int nex(int u,int v)
{
    int i;
    for(i=logn;i>=0;i--)
        if(dep[v]-(1<<i)>dep[u])
            v=fa[i][v];
    if(fa[0][v]==u) return tofa[v]^1;
    return tofa[u];
}
void solve(int u,int s,int v)
{
    if(s!=-1) s^=1;
    if(s==-1 && u==v) throw 0xdead;
    if(u==v) { if(en[u]!=-1 || suf[s]!=-1) throw 0xdead; en[u]=s; return; }
    int t=nex(u,v);
    if(s==-1)
    {
        if(st[u]!=-1 || pre[t]!=-1) throw 0xdead;
        st[u]=t;
    }
    else
    {
        if(en[u]==s || suf[s]!=-1 || st[u]==t || pre[t]!=-1) throw 0xdead;
        if(father(s)==father(t)) throw 0xdead;
        suf[s]=t,pre[t]=s,f[f[s]]=f[t];
    }
    solve(to[t],t,v);
}
int main()
{
    int i,cnt,u,v;
    ll ans;
    scanf("%d",&n);
    for(i=1,tot=0;i<=n;i++) he[i]=-1,st[i]=en[i]=-1;
    for(i=1;i<n;i++) scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
    tot=0,tofa[1]=-1,fa[0][1]=0,dep[1]=0,dfs(1);
    for(logn=0;(1<<logn)<n;logn++);
    for(i=1;i<=logn;i++)
        for(u=0;u<=n;u++)
            fa[i][u]=fa[i-1][fa[i-1][u]];
    try
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&u);
            if(u) solve(i,-1,u);
        }
        for(fac[0]=1,i=1;i<=n;i++) fac[i]=fac[i-1]*i%kcz;
        ans=1;
        for(u=1;u<=n;u++)
        {
            if(st[u]!=-1 && en[u]!=-1)
            {
                cnt=0;
                for(i=st[u];~suf[i];i=suf[i]) cnt++;
                cnt++;
                if(i==en[u])
                {
                    for(i=he[u];~i;i=ne[i]) cnt--;
                    if(cnt) throw 0xdead;
                    continue;
                }
            }
            cnt=0;
            for(i=he[u];~i;i=ne[i])
                if(pre[i]==-1 && st[u]!=i)
                    cnt++;
            if(en[u]!=-1) cnt--;
            (ans*=fac[cnt])%=kcz;
        }
        printf("%lld\n",ans);
    }
    catch(int) { printf("0\n"); }
    return 0;
}