#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1600010
#define M 1600010
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct zgz
{
    int next,to,id;
}e[N];
int head[N],cnt=1;
void add(int from,int to,int id)
{
    e[cnt].to=to;
    e[cnt].id=id;
    e[cnt].next=head[from];
    head[from]=cnt++;
}
struct Edge
{
    int u,v,w,id;
}edge[M];
bool cmp_w(const Edge &a,const Edge &b)
{return a.w<b.w;}
bool cmp_id(const Edge &a,const Edge &b)
{return a.id<b.id;}
int fa[N];
int find(int x)
{return fa[x]==x?x:fa[x]=find(fa[x]);}
int n,m,a;
bool is_tree[M];
int ans[N];
inline int Mn(int a,int b)
{return a<b?a:b;}
inline int Mx(int a,int b)
{return a>b?a:b;}
//----------------------------------------------two times dfs----------------------------------
int fa_s[N],deep[N],E_id[N],dfn;
int sz[N],son[N];
void dfs1(int x)
{
    sz[x]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int to=e[i].to;
        if(to==fa_s[x])continue ;
        fa_s[to]=x;
        deep[to]=deep[x]+1;
        E_id[to]=e[i].id;
        dfs1(to);
        sz[x]+=sz[to];
        if(sz[to]>sz[son[x]])son[x]=to;
    }
}
int tim[N],pos[N];
int top[N];
void dfs2(int x,int tp)
{
    tim[x]=++dfn,pos[dfn]=x,top[x]=tp;
    if(son[x])dfs2(son[x],tp);
    for(int i=head[x];i;i=e[i].next)
    {
        int to=e[i].to;
        if(to!=fa_s[x]&&to!=son[x])dfs2(to,to);
    }
}
//--------------------------------------------seq-------------------------------------------------
int mx[N],mn[N],cov[N];
void pushup(int x)
{mx[x]=Mx(mx[x<<1],mx[x<<1|1]);}
void modify(int x,int l,int r,int L,int R,int v);

void pushdown(int x,int l,int r)
{
    if(cov[x]!=inf)
    {
        int mid=(l+r)>>1;
        cov[x<<1]=Mn(cov[x<<1],cov[x]);
        cov[x<<1|1]=Mn(cov[x<<1|1],cov[x]);
        mn[x<<1]=Mn(mn[x<<1],cov[x]);
        mn[x<<1|1]=Mn(mn[x<<1|1],cov[x]);
        cov[x]=inf;
    }
}

void build(int x,int l,int r)
{
    if(l==r)
    {
        mx[x]=edge[E_id[pos[l]]].w;
        mn[x]=cov[x]=inf;
        return ;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid),build(x<<1|1,mid+1,r);
    cov[x]=mn[x]=inf;
    pushup(x);
}
int L,R;
void modify(int x,int l,int r,int v)
{
    if(L<=l&&R>=r)
    {
        cov[x]=Mn(cov[x],v);
        mn[x]=Mn(mn[x],v);
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    if(L<=mid) modify(x<<1,l,mid,v);
    if(R>mid)  modify(x<<1|1,mid+1,r,v);
    pushup(x);
}

int query(int x,int l,int r)
{
    if(L<=l&&R>=r)return mx[x];
    pushdown(x,l,r);
    int ret=0,mid=(l+r)>>1;
    if(L<=mid) ret=Mx(ret,query(x<<1,l,mid));
    if(R>mid)  ret=Mx(ret,query(x<<1|1,mid+1,r));
    return ret;
}

void dfs(int x,int l,int r)
{
    if(l==r)
    {
        ans[E_id[pos[l]]]=mn[x];
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    dfs(x<<1,l,mid),dfs(x<<1|1,mid+1,r);
}
//-------------------------------------------solve-----------------------------------
int ask(int u,int v)
{
    int ret=0;
    while(top[u]!=top[v])
    {
        if(deep[top[u]]<deep[top[v]])swap(u,v);
        L=tim[top[u]],R=tim[u];
        ret=Mx(ret,query(1,1,n));
        u=fa_s[top[u]];
    }
    if(deep[u]<deep[v])swap(u,v);
    if(tim[u]!=tim[v])
    {
        L=tim[v]+1,R=tim[u];
        ret=Mx(ret,query(1,1,n));
    }
    return ret;
}
void Modify(int u,int v,int val)
{
    while(top[u]!=top[v])
    {
        if(deep[top[u]]<deep[top[v]])swap(u,v);
        L=tim[top[u]],R=tim[u];
        modify(1,1,n,val);
        u=fa_s[top[u]];
    }
    if(deep[u]<deep[v])swap(u,v);
    if(tim[u]!=tim[v])
    {
        L=tim[v]+1,R=tim[u];
        modify(1,1,n,val);
    }
}

int main()
{
//    freopen("weight.in","r",stdin);
//    freopen("weight.out","w",stdout);

    register int i;
    n=read(),m=read();
    for(i=1;i<=m;++i)
    {
        edge[i].u=read(),edge[i].v=read(),edge[i].w=read();
        edge[i].id=i;
    }
    sort(edge+1,edge+m+1,cmp_w);
    for(i=1;i<=n;++i)fa[i]=i;
    for(i=1;i<=m;++i)
    {
        int u=edge[i].u,v=edge[i].v,id=edge[i].id;
        int fa_u=find(u),fa_v=find(v);
        if(fa_u==fa_v)continue ;
        fa[fa_u]=fa_v;is_tree[id]=1;
        add(u,v,id),add(v,u,id);
    }
    sort(edge+1,edge+m+1,cmp_id);
    fa[1]=1,deep[1]=1;
    dfs1(1);
    dfs2(1,1);
    build(1,1,n);
    for(i=1;i<=m;++i)
    {
        if(is_tree[i])continue ;
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        ans[i]=ask(u,v)-1;
        Modify(u,v,w-1);
    }
    dfs(1,1,n);
    for(i=1;i<=m;++i)
    {
        if(ans[i]==inf)printf("-1 ");
        else printf("%d ",ans[i]);
    }

//    fclose(stdin);
//    fclose(stdout);
}