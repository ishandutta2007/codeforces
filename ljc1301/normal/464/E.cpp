#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kcz=1000000007;
const int kcz2=998244353;
const int base2=27;
const int maxn=100005;
const int maxm=100005;
const int maxx=100050;
const int maxlog=18;
const int maxnode=(maxn+maxm*3)*maxlog;
ll powk[maxx+1][2];
struct HasH
{
    int a,b;
    HasH(int a=0,int b=0):a(a),b(b) { }
    inline HasH operator +(const HasH &h) const { return HasH((a+h.a)%kcz,(b+h.b)%kcz2); }
    inline HasH operator <<(int x) const { return HasH(a*powk[x][0]%kcz,b*powk[x][1]%kcz2); }
    inline bool operator ==(const HasH &h) const { return a==h.a && b==h.b; }
};
struct node { int lc,rc; bool ful; HasH h; }p[maxnode];
int n,he[maxn],ne[maxm<<1],to[maxm<<1],val[maxm<<1];
int s,t,dis[maxn],tr[maxn<<2],pre[maxn],tot;
bool vis[maxn];
inline void add_edge(int u,int v,int c) { to[tot]=v,ne[tot]=he[u],val[tot]=c,he[u]=tot++; }
inline void pushup(int rt,int lenl)
{
    p[rt].h=p[p[rt].lc].h+(p[p[rt].rc].h<<lenl),
    p[rt].ful=p[p[rt].lc].ful && p[p[rt].rc].ful;
}
bool add(int &rt,int l,int r,int x)
{
    if(p[rt].ful && x<=l) { rt=0; return 0; }
    p[++tot]=p[rt],rt=tot;
    if(l==r) { p[rt].ful=1,p[rt].h=HasH(1,1); return 1; }
    int mid=(l+r)>>1;
    bool ok=0;
    if(x<=mid) ok=add(p[rt].lc,l,mid,x);
    if(!ok) ok=add(p[rt].rc,mid+1,r,x);
    pushup(rt,mid-l+1);
    return ok;
}
inline bool cmp(int rt1,int rt2) // <
{
    if(rt1==-1 || rt2==-1) return rt1!=-1;
    if(p[rt1].h==p[rt2].h) return 0;
    for(;;)
    {
        if(!rt1 || !rt2) return !rt1;
        if(p[p[rt1].rc].h==p[p[rt2].rc].h)
            rt1=p[rt1].lc,rt2=p[rt2].lc;
        else rt1=p[rt1].rc,rt2=p[rt2].rc;
    }
}
void build(int rt,int l,int r)
{
    tr[rt]=(l<=s && s<=r)?s:l;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(rt<<1,l,mid),build((rt<<1)|1,mid+1,r);
}
inline void pushup(int rt) { tr[rt]=tr[(rt<<1)|cmp(dis[tr[(rt<<1)|1]],dis[tr[rt<<1]])]; }
void update(int rt,int l,int r,int x)
{
    if(l==r) { if(vis[x]) tr[rt]=0; return; }
    int mid=(l+r)>>1;
    if(x<=mid) update(rt<<1,l,mid,x);
    else update((rt<<1)|1,mid+1,r,x);
    pushup(rt);
}
int main()
{
    int m,i,u,v,c;
    scanf("%d%d",&n,&m);
    for(tot=0,i=1;i<=n;i++) he[i]=-1;
    while(m--) scanf("%d%d%d",&u,&v,&c),add_edge(u,v,c),add_edge(v,u,c);
    scanf("%d%d",&s,&t);
    for(i=0;i<=n;i++) dis[i]=(i==s)?0:-1,vis[i]=0;
    for(powk[0][0]=powk[0][1]=1,i=1;i<=maxx;i++)
        powk[i][0]=(powk[i-1][0]<<1)%kcz,
        powk[i][1]=(powk[i-1][1]*base2)%kcz;
    tot=0,p[0].lc=p[0].rc=0,p[0].ful=0,p[0].h=HasH();
    for(build(1,1,n);dis[tr[1]]!=-1;)
    {
        u=tr[1],vis[u]=1,update(1,1,n,u);
        if(u==t) break;
        for(i=he[u];~i;i=ne[i])
            if(!vis[to[i]] && (
                assert(add(c=dis[u],0,maxx,val[i])),cmp(c,dis[to[i]])))
                dis[to[i]]=c,pre[to[i]]=u,update(1,1,n,to[i]);
    }
    if(dis[t]==-1) printf("-1\n");
    else
    {
        printf("%d\n",p[dis[t]].h.a);
        for(he[tot=0]=t;he[tot]!=s;tot++) he[tot+1]=pre[he[tot]];
        printf("%d\n",tot+1);
        for(;tot>=0;tot--) printf("%d%c",he[tot],tot?' ':'\n');
    }
    return 0;
}