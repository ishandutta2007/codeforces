#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=2000010;
int n,m,d[MAXN];
LL t,p,a[MAXN],B[MAXN],b[MAXN],k[MAXN];
LL mul(LL a,LL b)
{
    return (a*b-(LL)((long double)a*b/p)*p)%p;
}
void tf(LL a[],int l,int r)
{
    if(l+1==r) return;
    int mid=(l+r)>>1,len=mid-l;
    tf(a,l,mid),tf(a,mid,r);
    for(int i=l;i<mid;i++)
    {
        LL x1=a[i],x2=a[i+len];
        a[i]=(x1-x2+p)%p;
        a[i+len]=(x1+x2)%p;
    }
}
void utf(LL a[],int l,int r)
{
    if(l+1==r) return;
    int mid=(l+r)>>1,len=mid-l;
    for(int i=l;i<mid;i++)
    {
        LL x1=a[i],x2=a[i+len];
        a[i]=(x1+x2)%p;
        a[i+len]=(x2-x1+p)%p;
    }
    utf(a,l,mid),utf(a,mid,r);
}
LL qpow(LL x,LL n)
{
    LL pp=x,con=1;
    while(n>0)
    {
        if(n&1) con=mul(con,pp);
        pp=mul(pp,pp);
        n>>=1;
    }
    return con;
}
int main()
{
    scanf("%d%I64d%I64d",&m,&t,&p);
    n=1<<m,p*=n;
    for(int i=0;i<n;i++) scanf("%I64d",&a[i]),a[i]%=p;
    for(int i=0;i<=m;i++) scanf("%I64d",&B[i]),B[i]%=p;
    for(int i=1;i<n;i++) d[i]=d[i>>1]+(i&1);
    for(int i=0;i<n;i++) b[i]=B[d[i]];
    tf(a,0,n),tf(b,0,n);
    for(int i=0;i<n;i++) b[i]=qpow(b[i],t);
    for(int i=0;i<n;i++) a[i]=mul(a[i],b[i]);
    utf(a,0,n);
    for(int i=0;i<n;i++) printf("%I64d\n",a[i]>>m);
    return 0;
}