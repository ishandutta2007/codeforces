#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 400005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,Cnt;
int fa[N],s[N];
int find(int x)
{return fa[x]==x?x:fa[x]=find(fa[x]);}
struct zgz
{
    int next,to,id;
    bool r;
}edge[N];
int cnt=1,head[N];
void add(int from,int to,int id,bool r)
{
    edge[cnt].to=to;
    edge[cnt].id=id;
    edge[cnt].r=r;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}
ll sum[N],ans[N];
void dfs(int x,int f)
{
    sum[x]=s[x];
    for(int i=head[x];i;i=edge[i].next)
    {
        int to=edge[i].to,id=edge[i].id;
        if(to==f)continue ;
        dfs(to,x);
        ans[id]=sum[to];
        if(edge[i].r)ans[id]=-ans[id];
        sum[x]+=sum[to];
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)fa[i]=i,s[i]=read();
    ll ret=0;
    for(int i=1;i<=n;i++)ret+=s[i];
    if(ret!=0)
    {
        puts("Impossible");
        return 0;
    }
    m=read();
    for(int i=1;i<=m;i++)
    {
        int x=read(),y=read();
        if(find(x)!=find(y))
        {
            add(x,y,i,0),add(y,x,i,1);
            fa[find(x)]=find(y);
            Cnt++;
        }
        if(Cnt==n-1)break ;
    }
    dfs(1,0);
    puts("Possible");
    for(int i=1;i<=m;i++)
    printf("%lld\n",ans[i]);
}