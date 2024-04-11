#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1010
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,V;
int w[N];
int b[N];
int fa[N],anc[N],ans;
int group[N][N],top[N];
int dp[N];
int find(int x)
{return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
    n=read(),m=read(),V=read();
    for(int i=1;i<=n;i++)w[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    for(int i=1;i<=n;i++)fa[i]=i;
    while(m--)
    {
        int x=read(),y=read();
        x=find(x),y=find(y);
        if(x!=y)fa[x]=y;
    }
    for(int i=1;i<=n;i++)anc[i]=find(i);
    for(int i=1;i<=n;i++)
        group[anc[i]][++top[anc[i]]]=i;

    for(int i=1;i<=n;i++)
    if(anc[i]==i)
    for(int j=V;j>=0;j--)
    {
        int sumw=0,sumb=0;
        for(int k=1;k<=top[i];k++)
        {
            int nw=w[group[i][k]],nb=b[group[i][k]];
            sumw+=nw,sumb+=nb;
            if(j>=nw)
                dp[j]=max(dp[j],dp[j-nw]+nb);
        }
        if(j>=sumw)
            dp[j]=max(dp[j],dp[j-sumw]+sumb);
        ans=max(ans,dp[j]);
    }
    printf("%d\n",ans);
}