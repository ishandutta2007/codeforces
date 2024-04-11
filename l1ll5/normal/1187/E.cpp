#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define N 1000005
#define ll long long
using namespace std;
int cnt,head[N],n,a,b,deep[N],size[N],fa[N];
ll ans[N],maxans,maxnum;
struct a
{
    int to,next;
}edge[N<<1];
void add(int from,int to)
{
    edge[++cnt].to=to;
    edge[cnt].next=head[from];
    head[from]=cnt;
}
void dfs1(int x)
{
    for(int i=head[x];i;i=edge[i].next)
    {
        if(edge[i].to==fa[x])continue;
        deep[edge[i].to]=deep[x]+1;
        fa[edge[i].to]=x;
        dfs1(edge[i].to);
        size[x]+=size[edge[i].to];
    }
    size[x]++;
}
void dfs2(int x)
{
    for(int i=head[x];i;i=edge[i].next)
    {
        if(edge[i].to==fa[x])continue;
            ans[edge[i].to]=ans[x]-size[edge[i].to]+n-size[edge[i].to];
            dfs2(edge[i].to);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        add(a,b);add(b,a);
    }
    dfs1(1);
    for(int i=1;i<=n;i++)
    ans[1]+=deep[i];
    dfs2(1);
    for(int i=1;i<=n;i++)
    {
        if(ans[i]>maxans)
        {
            maxans=ans[i];
            maxnum=i;
        }
    }
    printf("%lld",ans[maxnum]+n);
    return 0;
}