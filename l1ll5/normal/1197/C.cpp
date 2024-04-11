#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 300005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,k;
int a[N],d[N];
ll ans;
int main()
{
    n=read(),k=read();
    for(int i=0;i<n;i++)a[i]=read();
    for(int i=0;i<n-1;i++)d[i]=a[i+1]-a[i];
    sort(d,d+n-1);
    ans=a[n-1]-a[0];
    int t=n-2;
    while(--k)ans-=d[t--];
    printf("%lld\n",ans);
    return 0;
}