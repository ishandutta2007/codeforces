//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxn 200010
#define lowbit(i) (i&(-i))
int c[maxn];
int a[maxn],b[maxn];
int ans[maxn];
int n;
int seg[maxn<<2];

int query(int t)
{
    int ans=0;
    for (int i=t;i;i-=lowbit(i))    ans+=c[i];
    return ans;
}
void insert(int t,int delta)
{
    for (int i=t;i<=n;i+=lowbit(i)) c[i]+=delta;
}
void insert1(int t,int l,int r,int pos,int delta)
{
    if (l==r)   {seg[t]+=delta;return;}
    int mid=(l+r)>>1;
    if (pos<=mid)   insert1(t<<1,l,mid,pos,delta);
    if (pos>mid)    insert1(t<<1|1,mid+1,r,pos,delta);
    seg[t]=seg[t<<1]+seg[t<<1|1];
}
int find(int q)
{
    int t=1;
    int l=1,r=n;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (q<=seg[t<<1])   t=t<<1,r=mid;else q-=seg[t<<1],t=t<<1|1,l=mid+1;
    }
    return l;
}
int main()
{
    scanf("%d",&n);
    for (int i=n-1;i>=0;i--)
    {
        int x;
        scanf("%d",&x);
        a[i]=x-query(x);
        insert(x+1,1);
    }
    memset(c,0,sizeof(c));
    for (int i=n-1;i>=0;i--)
    {
        int x;
        scanf("%d",&x);
        b[i]=x-query(x);
        insert(x+1,1);
    }
    int x=0;
    for (int i=0;i<n;i++)
    {
        ans[i]=a[i]+b[i]+x;
        x=0;
        while (ans[i]>i)    x++,ans[i]-=i+1;
    }
    memset(c,0,sizeof(c));
    for (int i=1;i<=n;i++)  insert1(1,1,n,i,1);
    for (int i=n-1;i>=0;i--)
    {
        int x=find(ans[i]+1);
        printf("%d ",x-1);
        insert1(1,1,n,x,-1);
    }
    return 0;
}