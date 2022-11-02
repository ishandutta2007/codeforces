#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
int a[N],ans,sum[N];
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    a[++n]=m;
    for(int i=1;i<=n;i++)
    if(i&1) sum[i]=sum[i-1]+(a[i]-a[i-1]);
    else sum[i]=sum[i-1];

    ans=sum[n];

    for(int i=1;i<n;i++)
    if(i&1)
    {
        if(a[i]+1<a[i+1])
        {
            int ret=sum[i];
            ret+=a[i+1]-a[i]-1;
            int tmp=m-a[i+1]-sum[n]+sum[i+1];
            ret+=tmp;
            ans=max(ans,ret);
        }
        if(a[i]-1>a[i-1])
        {
            int ret=sum[i]-1;
            int tmp=m-a[i]-sum[n]+sum[i];
            ret+=tmp;
            ans=max(ans,ret);
        }
    }
    cout<<ans<<endl;
}