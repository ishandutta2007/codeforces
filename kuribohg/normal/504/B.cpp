#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,p[MAXN],q[MAXN],a[MAXN],b[MAXN],c[MAXN],ans[MAXN];
int T[MAXN<<2];
void Change(int x,int l,int r,int pos,int tar)
{
    T[x]+=tar;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(pos<=mid) Change(x<<1,l,mid,pos,tar);
    else Change(x<<1|1,mid+1,r,pos,tar);
}
int Query(int x,int l,int r,int K)
{
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(T[x<<1]>=K) return Query(x<<1,l,mid,K);
    else return Query(x<<1|1,mid+1,r,K-T[x<<1]);
}
int Sum(int x,int l,int r,int pos)
{
    if(l==r) return T[x];
    int mid=(l+r)>>1;
    if(pos<=mid) return Sum(x<<1,l,mid,pos);
    else return T[x<<1]+Sum(x<<1|1,mid+1,r,pos);
}
int main()
{
    scanf("%d",&n);
    for(int i=n-1;i>=0;i--) scanf("%d",&p[i]);
    for(int i=n-1;i>=0;i--) scanf("%d",&q[i]);
    for(int i=n-1;i>=0;i--)
    {
        a[i]=p[i]-Sum(1,1,n,p[i]);
        Change(1,1,n,p[i]+1,1);
    }
    memset(T,0,sizeof(T));
    for(int i=n-1;i>=0;i--)
    {
        b[i]=q[i]-Sum(1,1,n,q[i]);
        Change(1,1,n,q[i]+1,1);
    }
    for(int i=0;i<n;i++)
    {
        c[i]+=a[i]+b[i];
        while(c[i]>=i+1) c[i]-=i+1,c[i+1]++; 
    }
    for(int i=n-1;i>=0;i--)
    {
        ans[i]=Query(1,1,n,c[i]+1)-1;
        Change(1,1,n,ans[i]+1,-1);
    }
    for(int i=n-1;i>=0;i--) printf("%d ",ans[i]);
    puts("");
    return 0;
}