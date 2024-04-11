#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
const int INF=1000000000;
int n,tag[MAXN];
struct Seg
{
    int l,r;
    int lazy,dat;
}T[MAXN<<2];
Seg Merge(const Seg &p,const Seg &q)
{
    Seg res;
    res.l=p.l,res.r=q.r;
    res.dat=min(p.dat,q.dat);
    res.lazy=0;
    return res;
}
void PushDown(int x)
{
    T[x<<1].dat+=T[x].lazy;
    T[x<<1].lazy+=T[x].lazy;
    T[x<<1|1].dat+=T[x].lazy;
    T[x<<1|1].lazy+=T[x].lazy;
    T[x].lazy=0;
}
void MakeTree(int x,int l,int r)
{
    T[x].l=l,T[x].r=r;
    if(l==r) return;
    int mid=(l+r)>>1;
    MakeTree(x<<1,l,mid);
    MakeTree(x<<1|1,mid+1,r);
}
void Change(int x,int l,int r,int tar)
{
    if(T[x].l==l&&T[x].r==r)
    {
        T[x].lazy+=tar;
        T[x].dat+=tar;
        return;
    }
    PushDown(x);
    int mid=(T[x].l+T[x].r)>>1;
    if(r<=mid) Change(x<<1,l,r,tar);
    else if(l>mid) Change(x<<1|1,l,r,tar);
    else Change(x<<1,l,mid,tar),Change(x<<1|1,mid+1,r,tar);
    T[x]=Merge(T[x<<1],T[x<<1|1]);
}
Seg Query(int x,int l,int r)
{
    if(T[x].l==l&&T[x].r==r) return T[x];
    int mid=(T[x].l+T[x].r)>>1;
    PushDown(x);
    if(r<=mid) return Query(x<<1,l,r);
    else if(l>mid) return Query(x<<1|1,l,r);
    else return Merge(Query(x<<1,l,mid),Query(x<<1|1,mid+1,r));
}
int main()
{
    scanf("%d",&n);
    MakeTree(1,1,n);
    for(int i=1;i<=n;i++)
    {
        int pos,type,x;
        scanf("%d%d",&pos,&type);
        if(type==1) scanf("%d",&x);
        if(type==1)
        {
            Change(1,1,pos,-1);
            tag[pos]=x;
        }
        else Change(1,1,pos,1);
        int l=1,r=n;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            Seg o=Query(1,mid,n);
            if(o.dat<=-1) l=mid;
            else r=mid-1;
        }
        Seg o=Query(1,l,n);
        if(o.dat==-1) printf("%d\n",tag[l]);
        else puts("-1");
    }
    return 0;
}