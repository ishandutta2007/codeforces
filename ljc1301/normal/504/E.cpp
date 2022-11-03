#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int kcz=666623333; const int k1=37; const int k2=41; const int b1=5; const int b2=7;
const int maxn=300005;
const int maxlog=20;
ull pow1[maxn],ipow1[maxn];
ll pow2[maxn],ipow2[maxn];
struct HasH
{
    ull a; ll b;
    HasH(ull a=0,ll b=0):a(a),b(b) {}
    inline bool operator ==(const HasH &h) const { return a==h.a && b==h.b; }
    inline bool operator !=(const HasH &h) const { return a!=h.a || b!=h.b; }
    inline HasH operator +(char c) const { return HasH(a*k1+c-'a'+b1,(b*k2+c-'a'+b2)%kcz); }
    inline HasH addpre(char c,int len) const { return HasH(a+(c-'a'+b1)*pow1[len],(b+(c-'a'+b2)*pow2[len])%kcz); }
    inline HasH operator <<(int t) const { return HasH(a*pow1[t],b*pow2[t]%kcz); }
    inline HasH operator >>(int t) const { return HasH(a*ipow1[t],b*ipow2[t]%kcz); }
    inline HasH operator -(const HasH &h) const { return HasH(a-h.a,(b+kcz-h.b)%kcz); }
}ha[maxn],revha[maxn];
int n,he[maxn],ne[maxn<<1],to[maxn<<1],tot,m[2],tt;
pair<int,int> a[2][maxn],temp[maxn];
int dep[maxn],fa[maxn],top[maxn],dfn[maxn],id[maxn],sz[maxn],hson[maxn];
char s[maxn];
inline ull qpow1(ull a,ll k)
{
    ull res=1;
    while(k) { if(k&1) res*=a; if(k>>=1) a*=a; }
    return res;
}
inline ll qpow2(ll a,ll k)
{
    ll res=1;
    while(k) { if(k&1) (res*=a)%=kcz; if(k>>=1) (a*=a)%=kcz; }
    return res;
}
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],he[u]=tot++; }
void dfs1(int u)
{
    int i;
    sz[u]=1,hson[u]=0;
    ha[u]=ha[fa[u]]+s[u],revha[u]=revha[fa[u]].addpre(s[u],dep[u]);
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa[u])
        {
            fa[to[i]]=u,dep[to[i]]=dep[u]+1,dfs1(to[i]);
            sz[u]+=sz[to[i]];
            if(!hson[u] || sz[hson[u]]<sz[to[i]])
                hson[u]=to[i];
        }
}
void dfs2(int u,int t)
{
    tot++,dfn[u]=tot,id[tot]=u,top[u]=t;
    if(!hson[u]) return;
    int i;
    dfs2(hson[u],t);
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa[u] && to[i]!=hson[u])
            dfs2(to[i],to[i]);
}
inline HasH split(int u,int v)
{
    assert(top[u]==top[v]);
    if(dep[u]>=dep[v]) return ha[u]-(ha[fa[v]]<<(dep[u]-dep[v]+1));
    return (revha[v]-revha[fa[u]])>>dep[u];
}
inline int walk(int u,int v,int d)
{
    if(u==v) return u;
    if(dep[u]<dep[v]) return id[dfn[u]+d];
    return id[dfn[u]-d];
}
int main()
{
    int i,j,u,v,q,ans,l,r;
    scanf("%d%s",&n,s+1);
    for(tot=0,i=1;i<=n;i++) he[i]=-1;
    for(i=1;i<n;i++) scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
    for(i=1,pow1[0]=pow2[0]=ipow1[0]=ipow2[0]=1;i<=n;i++)
    {
        pow1[i]=pow1[i-1]*k1,pow2[i]=pow2[i-1]*k2%kcz;
        if(i==1) ipow1[i]=qpow1(k1,0x7fffffffffffffffll),ipow2[i]=qpow2(k2,kcz-2);
        else ipow1[i]=ipow1[i-1]*ipow1[1],ipow2[i]=ipow2[i-1]*ipow2[1]%kcz;
    }
    fa[1]=0,dep[1]=0,tot=0,ha[0]=revha[0]=HasH(),dfs1(1),dfs2(1,1);
    scanf("%d",&q);
    while(q--)
    {
        for(i=0;i<=1;i++)
        {
            scanf("%d%d",&u,&v);
            m[i]=tt=0;
            while(top[u]!=top[v])
                if(dep[top[u]]>dep[top[v]])
                    a[i][m[i]++]=make_pair(u,top[u]),u=fa[top[u]];
                else
                    temp[tt++]=make_pair(top[v],v),v=fa[top[v]];
            a[i][m[i]++]=make_pair(u,v);
            while(tt) a[i][m[i]++]=temp[--tt];
        }
        ans=0;
        for(i=0,j=0;i<m[0] && j<m[1];)
        {
#define s first
#define t second
            tt=min(abs(dep[a[0][i].s]-dep[a[0][i].t]),abs(dep[a[1][j].s]-dep[a[1][j].t]))+1;
            if(split(a[0][i].s,walk(a[0][i].s,a[0][i].t,tt-1))!=split(a[1][j].s,walk(a[1][j].s,a[1][j].t,tt-1)))
                break;
            ans+=tt;
            if(abs(dep[a[0][i].s]-dep[a[0][i].t])+1<=tt) i++; else a[0][i].s=walk(a[0][i].s,a[0][i].t,tt);
            if(abs(dep[a[1][j].s]-dep[a[1][j].t])+1<=tt) j++; else a[1][j].s=walk(a[1][j].s,a[1][j].t,tt);
        }
        if(i>=m[0] || j>=m[1]) { printf("%d\n",ans); continue; }
        l=0,r=tt-1;
        while(l<r)
        {
            tt=(l+r+1)>>1;
            if(split(a[0][i].s,walk(a[0][i].s,a[0][i].t,tt-1))!=split(a[1][j].s,walk(a[1][j].s,a[1][j].t,tt-1)))
                r=tt-1;
            else l=tt;
        }
        printf("%d\n",ans+l);
    }
    return 0;   
}