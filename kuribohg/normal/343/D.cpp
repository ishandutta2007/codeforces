#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=500010;
int n,x,y;
int head[MAXN],to[MAXN<<1],next[MAXN<<1],cnt=1;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int fa[MAXN],size[MAXN],son[MAXN],dep[MAXN];
void DFS(int x)
{
    size[x]=1;
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa[x])
        {
            dep[to[i]]=dep[x]+1;
            fa[to[i]]=x;
            DFS(to[i]);
            size[x]+=size[to[i]];
            if(size[to[i]]>size[son[x]]) son[x]=to[i];
        }
}
int dfn[MAXN],L[MAXN],R[MAXN],top[MAXN],dfs_clock;
void BuildTree(int x,int tp)
{
    dfn[x]=++dfs_clock,L[x]=dfn[x],top[x]=tp;
    if(son[x]) BuildTree(son[x],tp);
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa[x]&&to[i]!=son[x])
            BuildTree(to[i],to[i]);
    R[x]=dfs_clock;
}
struct Seg
{
    int l,r;
    int lazy,dat;
}T[MAXN<<2];
inline void PushDown(int x)
{
    if(T[x].lazy==-1) return;
    T[x<<1].lazy=T[x<<1|1].lazy=T[x<<1].dat=T[x<<1|1].dat=T[x].lazy;
    T[x].lazy=-1;
}
void MakeTree(int x,int l,int r)
{
    T[x].l=l,T[x].r=r,T[x].lazy=-1;
    if(l==r) return;
    int mid=(l+r)>>1;
    MakeTree(x<<1,l,mid);
    MakeTree(x<<1|1,mid+1,r);
}
void Change(int x,int l,int r,int tar)
{
    if(T[x].l==l&&T[x].r==r)
    {
        T[x].lazy=T[x].dat=tar;
        return;
    }
    PushDown(x);
    int mid=(T[x].l+T[x].r)>>1;
    if(r<=mid) Change(x<<1,l,r,tar);
    else if(l>mid) Change(x<<1|1,l,r,tar);
    else Change(x<<1,l,mid,tar),Change(x<<1|1,mid+1,r,tar);
}
int Query(int x,int pos)
{
    if(T[x].l==T[x].r) return T[x].dat;
    PushDown(x);
    int mid=(T[x].l+T[x].r)>>1;
    if(pos<=mid) return Query(x<<1,pos);
    else return Query(x<<1|1,pos);
}
void TreeChange(int p,int q,int tar)
{
    while(top[p]!=top[q])
    {
        if(dep[top[p]]<dep[top[q]]) swap(p,q);
        Change(1,dfn[top[p]],dfn[p],tar);
        p=fa[top[p]];
    }
    if(dfn[p]>dfn[q]) swap(p,q);
    Change(1,dfn[p],dfn[q],tar);
}
int Q,op;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
    DFS(1);
    BuildTree(1,1);
    MakeTree(1,1,n);
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d%d",&op,&x);
        if(op==1) Change(1,L[x],R[x],1);
        else if(op==2) TreeChange(1,x,0);
        else printf("%d\n",Query(1,dfn[x]));
    }
    return 0;
}