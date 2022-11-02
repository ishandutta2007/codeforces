#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 5010
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define int long long
#define eps 1e-8
const long double pi = 4*atan((long double)1);
long double k[N<<2];
ll x[N],y[N];
int n,bas,ans;
ll cal(int n)
{
    return (n-1)*(n-2)*(n-3)/6;
}
ll cc(int x)
{
    return (x)*(x-1)/2;
}
ll ask(int X)
{
    int top=0;
    for(int i=1;i<=n;i++)
    if(i!=X)
    {
        long double hh=atan2(y[i]-y[X],x[i]-x[X]);
        if(hh<=-eps) hh+=pi*2;

        if(X>i)k[i]=hh;else k[i-1]=hh;//k[++top]=hh;
    }
    sort(k+1,k+n);
    for(int i=1;i<n;i++) k[i+n-1]=k[i]+pi+pi;
    int ret=0,pos=1,num=1;
    for(int i=1;i<n;i++)
    {
        while(fabs(k[pos]-k[i])<pi)pos++;
        if(pos>i) ret+=cc(pos-i-1);
    }
    return bas-ret;
}
// 633389467153248

/*
F(j,1,n)
if(j^i){
    ss=atan2(A[j].y-A[i].y,A[j].x-A[i].x);
    if(ss<=-eps)ss+=Pi*2;
    if(i>j)H[j]=ss;else H[j-1]=ss;
}
sort(H+1,H+n); u=1;
F(j,1,n-1)H[j+n-1]=H[j]+Pi+Pi;
F(j,1,n-1){
    while(fabs(H[u]-H[j])<Pi)++u;
    if(u>j)Ans-=C[u-j-1][2];
}
Ans+=C[n-1][3];
*/
main()
{
    //freopen("data.in","r",stdin);
    n=read();
    bas=cal(n);

    for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();

    for(int i=1;i<=n;i++) ans+=ask(i);

    ans=ans*(n-4);
    ans/=2;
    cout<<ans<<endl;
}