#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
struct Seg
{
    int l,r;
    int lb[31];
    Seg(){l=0,r=0;memset(lb,0,sizeof(lb));}
}T[MAXN<<2];
int n,Q,a[MAXN];
Seg Merge(const Seg &p,const Seg &q)
{
    Seg res;
    res.l=p.l,res.r=q.r;
    for(int i=0;i<=30;i++) res.lb[i]=p.lb[i];
    for(int sub=30;sub>=0;sub--)
        if(q.lb[sub])
        {
            int o=q.lb[sub];
            for(int i=30;i>=0;i--)
                if(o&(1<<i))
                {
                    if(res.lb[i]) o^=res.lb[i];
                    else {res.lb[i]=o;break;}
                }
        }
    return res;
}
void MakeTree(int x,int l,int r)
{
    T[x].l=l,T[x].r=r;
    if(l==r)
    {
        int o=a[l];
        for(int i=30;i>=0;i--)
            if(o&(1<<i))
            {
                if(T[x].lb[i]) o^=T[x].lb[i];
                else {T[x].lb[i]=o;break;}
            }
        return;
    }
    int mid=(l+r)>>1;
    MakeTree(x<<1,l,mid);
    MakeTree(x<<1|1,mid+1,r);
    T[x]=Merge(T[x<<1],T[x<<1|1]);
}
void Change(int x,int pos,int tar)
{
    if(T[x].l==T[x].r)
    {
        int o=tar;
        for(int i=0;i<=30;i++) T[x].lb[i]=0;
        for(int i=30;i>=0;i--)
            if(o&(1<<i))
            {
                if(T[x].lb[i]) o^=T[x].lb[i];
                else {T[x].lb[i]=o;break;}
            }
        return;
    }
    int mid=(T[x].l+T[x].r)>>1;
    if(pos<=mid) Change(x<<1,pos,tar);
    else Change(x<<1|1,pos,tar);
    T[x]=Merge(T[x<<1],T[x<<1|1]);
}
Seg Query(int x,int l,int r)
{
    if(l>r) return Seg();
    if(l==T[x].l&&r==T[x].r) return T[x];
    int mid=(T[x].l+T[x].r)>>1;
    if(r<=mid) return Query(x<<1,l,r);
    else if(l>mid) return Query(x<<1|1,l,r);
    else
    {
        Seg p=Query(x<<1,l,mid);
        Seg q=Query(x<<1|1,mid+1,r);
        return Merge(p,q);
    }
}
int BIT[MAXN];
void Change(int x,int tar)
{
    for(int i=x;i<=n;i+=(i&(-i)))
        BIT[i]^=tar;
}
int Query(int x)
{
    int con=0;
    for(int i=x;i;i^=(i&(-i)))
        con^=BIT[i];
    return con;
}
int main()
{
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) Change(i,a[i]),Change(i+1,a[i]);
    for(int i=n-1;i>=1;i--) a[i+1]^=a[i];
    MakeTree(1,1,n);
    while(Q--)
    {
        int op,l,r,k;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1) scanf("%d",&k);
        if(op==1)
        {
            a[l]^=k;
            Change(1,l,a[l]);
            if(r+1<=n)
            {
                a[r+1]^=k;
                Change(1,r+1,a[r+1]);
            }
            Change(l,k);
            Change(r+1,k);
        }
        else
        {
            Seg res=Query(1,l+1,r);
            int o=Query(l);
            for(int i=30;i>=0;i--)
                if(o&(1<<i))
                {
                    if(res.lb[i]) o^=res.lb[i];
                    else {res.lb[i]=o;break;}
                }
            int k=0;
            for(int i=30;i>=0;i--)
                if(res.lb[i]) k++;
            printf("%d\n",1<<k);
        }
    }
    return 0;
}