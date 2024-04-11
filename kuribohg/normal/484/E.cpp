#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
struct Node
{
    int x,sub;
    friend bool operator<(const Node &p,const Node &q)
    {
        return p.x>q.x;
    }
}A[MAXN];
struct Seg
{
    int lch,rch;
    int l,r;
    int lcon,rcon,con;
}T[MAXN*30],res;
int tot,root[MAXN];
Seg Merge(const Seg &p,const Seg &q,int lc,int rc)
{
    Seg con;
    con.lch=lc,con.rch=rc;
    con.l=p.l,con.r=q.r;
    con.lcon=p.lcon,con.rcon=q.rcon;
    if(p.lcon==p.r-p.l+1) con.lcon=p.lcon+q.lcon;
    if(q.rcon==q.r-q.l+1) con.rcon=q.rcon+p.rcon;
    con.con=max(p.rcon+q.lcon,max(p.con,q.con));
    return con;
}
int MakeTree(int l,int r)
{
    int o=++tot;
    T[o].l=l,T[o].r=r;
    if(l==r) return o;
    int mid=(l+r)>>1;
    T[o].lch=MakeTree(l,mid);
    T[o].rch=MakeTree(mid+1,r);
    return o;
}
int Change(int x,int pos)
{
    int o=++tot;
    T[o]=T[x];
    if(T[x].l==T[x].r)
    {
        T[o].lcon=T[o].rcon=T[o].con=1;
        return o;
    }
    int mid=(T[x].l+T[x].r)>>1;
    if(pos<=mid) T[o].lch=Change(T[x].lch,pos);
    else T[o].rch=Change(T[x].rch,pos);
    T[o]=Merge(T[T[o].lch],T[T[o].rch],T[o].lch,T[o].rch);
    return o;
}
Seg Query(int x,int l,int r)
{
    if(T[x].l==l&&T[x].r==r) return T[x];
    int mid=(T[x].l+T[x].r)>>1;
    if(r<=mid) return Query(T[x].lch,l,r);
    else if(l>mid) return Query(T[x].rch,l,r);
    else return Merge(Query(T[x].lch,l,mid),Query(T[x].rch,mid+1,r),0,0);
}
int n,Q,l,r,w;
int L,R,mid;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&A[i].x),A[i].sub=i;
    sort(A+1,A+n+1);
    root[0]=MakeTree(1,n);
    for(int i=1;i<=n;i++) root[i]=Change(root[i-1],A[i].sub);
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d%d%d",&l,&r,&w);
        L=1,R=n;
        while(L<R)
        {
            mid=(L+R)>>1;
            res=Query(root[mid],l,r);
            if(res.con>=w) R=mid;
            else L=mid+1;
        }
        printf("%d\n",A[L].x);
    }
    return 0;
}