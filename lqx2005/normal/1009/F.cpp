#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000;
struct E
{
	int to,nxt;
}e[maxn*2+5];
int n,h[maxn+5],cnt=0,ans[maxn+5],sz[maxn+5],dep[maxn+5];
map<int,int> s[maxn+5];
void add(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].nxt=h[u];
	h[u]=cnt;
	return;
}
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	sz[u]=1;
	s[u][dep[u]]++;
	ans[u]=dep[u];
	for(int now=h[u];now;now=e[now].nxt)
	{
		int v=e[now].to;
		if(v==fa) continue;
		dfs(v,u);
		if(sz[u]<sz[v]) 
		{
			swap(sz[u],sz[v]);
			ans[u]=ans[v];
			s[u].swap(s[v]);
		}
	}
	for(int now=h[u];now;now=e[now].nxt)
	{
		int v=e[now].to;
		if(v==fa) continue;
		map<int,int>::iterator it;
		for(it=s[v].begin();it!=s[v].end();it++)
		{
			int Dep=it->first;
			s[u][Dep]+=s[v][Dep];
			if(s[u][Dep]>s[u][ans[u]]||(s[u][Dep]==s[u][ans[u]]&&Dep<ans[u])) ans[u]=Dep;
		}
		sz[u]+=sz[v];
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
	dfs(1,0);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]-dep[i]);
	return 0;
}