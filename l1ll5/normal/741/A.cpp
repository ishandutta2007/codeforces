#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 110
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int deg[N],a[N],n,ans;
bool vis[N];
bool ok;
int gcd(int a,int b)
{return b==0?a:gcd(b,a%b);}
int solve()
{
    int ret=1;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    if(!vis[i])
    {
        int tmp=1;
        int tp=a[i];
        vis[i]=1;
        while(!vis[tp])
        {
            vis[tp]=1;
            tp=a[tp];
            tmp++;
        }
        ret=ret/gcd(ret,tmp)*tmp;
    }
    if(!(ret&1))ret>>=1;
    return ret;
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        deg[a[i]]++;
    }
    ok=1;
    for(int i=1;i<=n;i++)
    if(!deg[i])ok=0;
    if(!ok)
    {
        puts("-1");
        return 0;
    }
    ans=solve();
    printf("%d\n",ans);
}