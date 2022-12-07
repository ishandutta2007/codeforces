#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=200010;
struct Seg
{
    int l,r;
    LL sum,lazy;
}T[MAXN<<2];
void MakeTree(int x,int l,int r)
{
    T[x].l=l,T[x].r=r;
    if(l==r) return;
    int mid=(l+r)>>1;
    MakeTree(x<<1,l,mid);
    MakeTree(x<<1|1,mid+1,r);
}
inline void PushDown(int x)
{
    int lc=x<<1,rc=x<<1|1;
    LL ls=T[lc].r-T[lc].l+1,rs=T[rc].r-T[rc].l+1;
    T[lc].lazy+=T[x].lazy,T[rc].lazy+=T[x].lazy;
    T[lc].sum+=ls*T[x].lazy,T[rc].sum+=rs*T[x].lazy;
    T[x].lazy=0;
}
void Modify(int x,int pos,int tar)
{
    if(T[x].l==T[x].r)
    {
        T[x].sum=tar;
        return;
    }
    PushDown(x);
    int mid=(T[x].l+T[x].r)>>1;
    if(pos<=mid) Modify(x<<1,pos,tar);
    else Modify(x<<1|1,pos,tar);
    T[x].sum=T[x<<1].sum+T[x<<1|1].sum;
}
void Change(int x,int l,int r,LL tar)
{
    if(T[x].l==l&&T[x].r==r)
    {
        T[x].lazy+=tar;
        T[x].sum+=(T[x].r-T[x].l+1)*tar;
        return;
    }
    PushDown(x);
    int mid=(T[x].l+T[x].r)>>1;
    if(r<=mid) Change(x<<1,l,r,tar);
    else if(l>mid) Change(x<<1|1,l,r,tar);
    else Change(x<<1,l,mid,tar),Change(x<<1|1,mid+1,r,tar);
    T[x].sum=T[x<<1].sum+T[x<<1|1].sum;
}
int n,size=1,op,x,y;
int main()
{
    scanf("%d",&n);
    MakeTree(1,1,200001);
    while(n--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&x,&y);
            Change(1,1,x,y);
        }
        else if(op==2)
        {
            scanf("%d",&x);
            ++size;
            Modify(1,size,x);
        }
        else
        {
            Modify(1,size,0);
            size--;
        }
        printf("%.06lf\n",T[1].sum*1.0/size);
    }
    return 0;
}