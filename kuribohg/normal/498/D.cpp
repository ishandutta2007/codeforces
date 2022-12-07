#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=100010;
struct Seg_Tree
{
    int l,r;
    int d[60],res[60];
}T[MAXN<<2],ans;
int n,m,a[MAXN],l,r;
char op[10];
Seg_Tree Merge(const Seg_Tree &p,const Seg_Tree &q)
{
    Seg_Tree con;
    con.l=p.l,con.r=q.r;
    for(int i=0;i<60;i++)
    {
        con.d[i]=p.d[i]+q.d[p.res[i]];
        con.res[i]=q.res[p.res[i]];
    }
    return con;
}
void MakeTree(int x,int l,int r)
{
    T[x].l=l,T[x].r=r;
    if(l==r)
    {
        for(int i=0;i<60;i++)
            if(i%a[l]==0) T[x].d[i]=1,T[x].res[i]=(i+2)%60;
            else T[x].d[i]=0,T[x].res[i]=(i+1)%60;
        return;
    }
    int mid=(T[x].l+T[x].r)>>1;
    MakeTree(x<<1,l,mid);
    MakeTree(x<<1|1,mid+1,r);
    T[x]=Merge(T[x<<1],T[x<<1|1]);
}
void Change(int x,int pos,int tar)
{
    if(T[x].l==T[x].r)
    {
        for(int i=0;i<60;i++)
            if(i%tar==0) T[x].d[i]=1,T[x].res[i]=(i+2)%60;
            else T[x].d[i]=0,T[x].res[i]=(i+1)%60;
        return;
    }
    int mid=(T[x].l+T[x].r)>>1;
    if(pos<=mid) Change(x<<1,pos,tar);
    else Change(x<<1|1,pos,tar);
    T[x]=Merge(T[x<<1],T[x<<1|1]);
}
Seg_Tree Query(int x,int l,int r)
{
    if(T[x].l==l&&T[x].r==r) return T[x];
    int mid=(T[x].l+T[x].r)>>1;
    if(r<=mid) return Query(x<<1,l,r);
    else if(l>mid) return Query(x<<1|1,l,r);
    else return Merge(Query(x<<1,l,mid),Query(x<<1|1,mid+1,r));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    MakeTree(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%s%d%d",op,&l,&r);
        if(op[0]=='C') Change(1,l,r);
        else
        {
            ans=Query(1,l,r-1);
            printf("%d\n",r-l+ans.d[0]);
        }
    }
    return 0;
}