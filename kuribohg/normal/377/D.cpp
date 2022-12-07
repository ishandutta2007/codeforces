#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=300000;
const int MAXN=1000010;
struct Node
{
    int x,l,r,type;
    friend bool operator<(const Node &p,const Node &q)
    {
        return (p.x==q.x)?(p.type<q.type):(p.x<q.x);
    }
}Q[MAXN];
int n,L[MAXN],R[MAXN],V[MAXN],tot,ans,ansL,ansR,con;
struct Seg
{
    int l,r;
    int lazy;
    int M,pos;
}T[MAXN<<1];
Seg Merge(const Seg &p,const Seg &q)
{
    Seg con;
    con.l=p.l,con.r=q.r,con.lazy=0;
    con.M=max(p.M,q.M);
    if(con.M==p.M) con.pos=p.pos;
    if(con.M==q.M) con.pos=q.pos;
    return con;
}
void PushDown(int x)
{
    T[x<<1].lazy+=T[x].lazy;
    T[x<<1].M+=T[x].lazy;
    T[x<<1|1].lazy+=T[x].lazy;
    T[x<<1|1].M+=T[x].lazy;
    T[x].lazy=0;
}
void MakeTree(int x,int l,int r)
{
    T[x].l=l,T[x].r=r,T[x].pos=l;
    if(l==r) return;
    int mid=(l+r)>>1;
    MakeTree(x<<1,l,mid);
    MakeTree(x<<1|1,mid+1,r);
}
void Change(int x,int l,int r,int tar)
{
    if(T[x].l==l&&T[x].r==r)
    {
        T[x].M+=tar,T[x].lazy+=tar;
        return;
    }
    int mid=(T[x].l+T[x].r)>>1;
    PushDown(x);
    if(r<=mid) Change(x<<1,l,r,tar);
    else if(l>mid) Change(x<<1|1,l,r,tar);
    else Change(x<<1,l,mid,tar),Change(x<<1|1,mid+1,r,tar);
    T[x]=Merge(T[x<<1],T[x<<1|1]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&L[i],&V[i],&R[i]);
    for(int i=1;i<=n;i++)
    {
        Q[++tot].x=L[i],Q[tot].l=V[i],Q[tot].r=R[i],Q[tot].type=1;
        Q[++tot].x=V[i],Q[tot].l=V[i],Q[tot].r=R[i],Q[tot].type=3;
    }
    for(int i=1;i<=n;i++) Q[++tot].x=L[i],Q[tot].type=2;
    sort(Q+1,Q+tot+1);
    MakeTree(1,1,N);
    for(int i=1;i<=tot;i++)
    {
        if(Q[i].type==1) Change(1,Q[i].l,Q[i].r,1);
        else if(Q[i].type==3) Change(1,Q[i].l,Q[i].r,-1);
        else if(Q[i].type==2&&T[1].M>ans) ans=T[1].M,ansL=Q[i].x,ansR=T[1].pos;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        if(L[i]<=ansL&&R[i]>=ansR&&V[i]<=ansR&&V[i]>=ansL) printf("%d ",i);
    puts("");
    return 0;
}