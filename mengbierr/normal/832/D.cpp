#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
    int f=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
    return f;
}
int fa[100005],dep[100005],son[100005],pos[100005],npos[100005],size[100005],tot,cnt,n,m;
int head[100005],top[100005],num=1;
struct node
{
    int from;
    int to;
    int next;
}edge[200005];
struct segtree
{
    int ls;
    int rs;
    int sum;
    int mark;
}tree[200005];
inline void build(int p,int l,int r)
{
    int mid=l+r>>1;
    if(l==r)
    return;
    tree[p].ls=++num;
    tree[p].rs=++num;
    build(tree[p].ls,l,mid);
    build(tree[p].rs,mid+1,r);
}
inline void add(int u,int v)
{
    edge[tot].from=u;
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
inline void dfs1(int x)
{
    dep[x]=dep[fa[x]]+1;
    size[x]=1;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        if(edge[i].to!=fa[x])
        {
        	fa[edge[i].to]=x;
            dfs1(edge[i].to);
            size[x]+=size[edge[i].to];
            if(size[edge[i].to]>size[son[x]])
            son[x]=edge[i].to;
        }
    }
}
inline void dfs2(int x)
{
    pos[x]=++cnt;
    npos[cnt]=x;
    if(son[fa[x]]==x)
    {
        top[x]=top[fa[x]];
    }
    else top[x]=x;
    if(son[x])
    dfs2(son[x]);
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        if(edge[i].to!=fa[x]&&edge[i].to!=son[x])
        dfs2(edge[i].to);
    }
}
inline void modify(int p,int x,int y,int l,int r,int z)
{
    int mid=l+r>>1;
    if(l==x&&r==y)
    {
        tree[p].sum+=(r-l+1)*z;
        tree[p].mark+=z;
        return;
    }
    tree[tree[p].ls].sum+=(mid-l+1)*tree[p].mark;
    tree[tree[p].rs].sum+=(r-mid)*tree[p].mark;
    tree[tree[p].ls].mark+=tree[p].mark;
    tree[tree[p].rs].mark+=tree[p].mark;
    tree[p].mark=0;
    if(y<=mid)
    modify(tree[p].ls,x,y,l,mid,z);
    else if(x>mid)
    modify(tree[p].rs,x,y,mid+1,r,z);
    else
    {
        modify(tree[p].ls,x,mid,l,mid,z);
        modify(tree[p].rs,mid+1,y,mid+1,r,z);
    }
    tree[p].sum=tree[tree[p].ls].sum+tree[tree[p].rs].sum;
}
inline void modify(int x,int y,int z)
{
    int fy=top[y],fx=top[x];
    while(fx!=fy)
    {
        if(dep[fx]<dep[fy])
        swap(x,y),swap(fx,fy);
        modify(1,pos[fx],pos[x],1,n,z);
        x=fa[fx],fx=top[x];
    }
    if(dep[x]<dep[y])
    swap(x,y);
    modify(1,pos[y],pos[x],1,n,z);
}
inline int getsum(int p,int x,int y,int l,int r)
{
    int mid=l+r>>1;
    if(l==x&&r==y)
    {
        return tree[p].sum;
    }
    tree[tree[p].ls].sum+=(mid-l+1)*tree[p].mark;
    tree[tree[p].rs].sum+=(r-mid)*tree[p].mark;
    tree[tree[p].ls].mark+=tree[p].mark;
    tree[tree[p].rs].mark+=tree[p].mark;
    tree[p].mark=0;
    if(y<=mid)
    return getsum(tree[p].ls,x,y,l,mid);
    else if(x>mid)
    return getsum(tree[p].rs,x,y,mid+1,r);
    return (getsum(tree[p].ls,x,mid,l,mid)+getsum(tree[p].rs,mid+1,y,mid+1,r));
}
inline int  getsum(int x,int y)
{
    int fx=top[x],fy=top[y];long long sum=0;
    while(fx!=fy)
    {
        if(dep[fx]<dep[fy])
        swap(x,y),swap(fx,fy);
        sum+=getsum(1,pos[fx],pos[x],1,n);
        x=fa[fx];fx=top[x];
    }
    if(dep[x]<dep[y])
    swap(x,y);
    sum+=getsum(1,pos[y],pos[x],1,n);
    return sum;
}
int main()
{
    //freopen("input.txt","r",stdin);
    memset(head,-1,sizeof(head));
    n=read(),m=read();
    for(int i=2;i<=n;i++)
    {
        int x=read();
        add(i,x);
        add(x,i);
    }
    dfs1(2);
    dfs2(2);
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int x=read(),y=read(),z=read();
        modify(x,y,1);
        int ans=getsum(x,z);
        ans=max(ans,getsum(y,z));
        modify(x,y,-1);
        modify(x,z,1);
        ans=max(ans,getsum(y,z));
        printf("%d\n",ans);
        modify(x,z,-1);
    }
}