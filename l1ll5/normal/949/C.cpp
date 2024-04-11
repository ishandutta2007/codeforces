#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,h;
int u[N];
struct zgz
{
    int next,to;
}edge[N<<1];
int head[N],cnt=1;
void add(int from,int to)
{
    edge[cnt].to=to;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}
int vis[N],stk[N],dfn[N],low[N],tot,top,scnt;
int out[N],siz[N],belong[N];
int U,V;
void tarjan(int x)
{
	vis[x]=1;
	dfn[x]=low[x]=++tot;
	stk[++top]=x;
	for(int i=head[x];i;i=edge[i].next)
	{
		int to=edge[i].to;
		if(!dfn[to])
		{
			tarjan(to);
			low[x]=min(low[x],low[to]);
		}
		else if(vis[to])
		{
			low[x]=min(low[x],dfn[to]);
		}
	}
	if(low[x]==dfn[x])
	{
		scnt++;
		do{
			V=stk[top--];
			belong[V]=scnt;
			siz[scnt]++;
			vis[V]=0;
		}while(V!=x);
	}
}
void rebuild()
{
	for(int i=1;i<=n;i++)
	 for(int j=head[i];j;j=edge[j].next)
	 {
	 	int to=edge[j].to;
	 	if(i!=to&&belong[to]!=belong[i])
	 	{
	 		out[belong[i]]++;
 		}
	 }
}
int main()
{
    n=read(),m=read(),h=read();
    for(int i=1;i<=n;i++)u[i]=read();
    for(int i=1;i<=m;i++)
    {
        int x=read(),y=read();
        if(u[x]>u[y])swap(x,y);
        if(u[x]+1==u[y])add(x,y);
        if((u[y]+1)%h==u[x])add(y,x);
    }
    for(int i=1;i<=n;i++)
	if(!dfn[i])
    tarjan(i);

	rebuild();
    siz[0]=1000000000;
    int ans=0;
    for(int i=1;i<=scnt;i++)
    if(!out[i])
    if(siz[ans]>siz[i])ans=i;

    printf("%d\n",siz[ans]);
    for(int i=1;i<=n;i++)
    if(belong[i]==ans)printf("%d ",i);
}