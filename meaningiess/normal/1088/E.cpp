#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define N 300005
#define ll long long
using namespace std;
int fir[N],to[N<<1],nxt[N<<1],cnt,a[N],n;ll g[N],ans,K;
void add(int x,int y){nxt[++cnt]=fir[x];fir[x]=cnt;to[cnt]=y;}
void dfs2(int x,int fa)
{
	g[x]=a[x];for (int i=fir[x];i;i=nxt[i]) if (to[i]!=fa)
		{dfs2(to[i],x);g[x]+=max(g[to[i]],0ll);}
	if (g[x]==ans) K++,g[x]=0;
}
void dfs(int x,int fa)
{
	g[x]=a[x];for (int i=fir[x];i;i=nxt[i]) if (to[i]!=fa)
		{dfs(to[i],x);g[x]+=max(g[to[i]],0ll);}
	ans=max(ans,g[x]);
}
int main()
{
	scanf("%d",&n);int i,x,y;ans=-1e15;
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	dfs(1,0);dfs2(1,0);cout<<ans*K<<' '<<K;
}