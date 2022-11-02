#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 2000005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,k;
int s[N],a[N],nxt[N];
bool b[N];
ll ans,tmp;
int main()
{
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++)b[read()]=1;
    if(b[0])
    {
        puts("-1");
        return 0;
    }
    for(int i=1;i<=k;i++)a[i]=read();
    for(int i=0;i<n;i++)
    if(b[i])nxt[i]=nxt[i-1];
    else nxt[i]=i;
    ans=1e18;
    for(int i=1;i<=k;i++)
    {
        int now=0;
        tmp=0;
        bool ok=0;
        while(now<n)
        {
            if(now+i>=n)
            {
                tmp+=a[i];
                ok=1;
                break ;
            }
            int tp=nxt[now+i];
            if(tp<=now)break ;
            tmp+=a[i];
            now=tp;
        }
        if(ok)ans=min(ans,tmp);
    }
    if(ans==1e18)
    {
        puts("-1");
        return 0;
    }
    cout<<ans<<endl;
}