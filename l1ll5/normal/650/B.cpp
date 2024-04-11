#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 500005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline int Mx(int a,int b)
{return a>b?a:b;}
inline int Mn(int a,int b)
{return a<b?a:b;}
int n,a,b,T,ans;
char s[N];
ll c[N],d[N],g[N];
int find(ll x,int r)
{
    if(!r)return 0;
    int l=0,ret;
    while(r>=l)
    {
        int mid=(l+r)>>1;
        if(d[mid]<=x)ret=mid,l=mid+1;
        else r=mid-1;
    }
    return ret;
}
int rfind(ll x,int r)
{
    if(!r)return 0;
    int l=2,ret=0;
    while(r>=l)
    {
        int mid=(l+r)>>1;
        if(c[mid]<=x)ret=mid,l=mid+1;
        else r=mid-1;
    }
    return ret;
}
int Cal(ll A[N],ll B[N])
{
    int ans=0;
    for(int i=0;i<n&&A[i]<=T;i++)
    {
        ll rem=T-A[i]-a*i+A[0];
        ans=Mx(ans,i+upper_bound(B,B+n,rem)-(B));
    }
    return ans;
}
int main()
{
    //freopen("data.in","r",stdin);
    n=read(),a=read(),b=read(),T=read();
    scanf("%s",s);
    for(int i=0;i<n;i++)
    s[i]=='h'?g[i]=1:g[i]=b+1;
    c[0]=d[0]=g[0];
    for(int i=1;i<=n-1;i++)
    {
        c[i]=c[i-1]+g[i]+a,d[i]=d[i-1]+g[n-i]+a;
    }
    printf("%d\n",Mn(Mx(Cal(c,d),Cal(d,c)),n));
}