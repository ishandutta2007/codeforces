#include<bits/stdc++.h>
using namespace std;
const int maxn=510000;
struct edge
{
	int to,nxt;
}e[maxn*2];
int n;
int h[maxn],E=0;
int l[maxn],r[maxn],tot=0;
void add(int u,int v)
{
	E++;
	e[E].to=v;
	e[E].nxt=h[u];
	h[u]=E;
	return;
}
void dfs(int u,int fa)
{
	int deg=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa) continue;
		deg++;
	}
	tot+=deg+1;
	r[u]=tot;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa) continue;
		tot--;
		l[v]=tot;
	}
	tot+=deg;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
	}
	return;
	
}
int main()
{
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	l[1]=++tot;
	dfs(1,0);
	for(int i=1;i<=n;i++) printf("%d %d\n",l[i],r[i]);
	return 0;
}