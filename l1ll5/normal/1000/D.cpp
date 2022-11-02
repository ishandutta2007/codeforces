#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1005
#define ll long long
using namespace std;
#define mod 998244353
char xB[1<<15],*xS=xB,*xT=xB;
#define getchar() (xS==xT&&(xT=(xS=xB)+fread(xB,1,1<<15,stdin),xS==xT)?0:*xS++)
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline int add(int x,int y){return (x+=y)>=mod?x-mod:x;}
inline int mul(int x,int y){return (ll)x*y%mod;}
int Qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)ret=mul(ret,a);
        a=mul(a,a),b>>=1;
    }
    return ret;
}
int n;
int a[N*N],f[N*N],g[N*N];
int fac[N],inv[N];
inline int C(int n,int m)
{return mul(fac[n],mul(inv[m],inv[n-m]));}
void init()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
    inv[n]=Qpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i]=mul(inv[i+1],i+1);
}
int main()
{
    //freopen("data.in","r",stdin);
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=0;i<=n;i++)f[i]=1;
    init();

    for(int i=1;i<=n;i++)
    if(a[i]>0&&a[i]<=n)for(int j=i+a[i];j<=n;j++)f[j]=add(f[j],mul(f[i-1],C(j-i,a[i])));
    f[n]--,f[n]+=mod,f[n]%=mod;
    printf("%d\n",f[n]);
}//896429175