#include<bits/stdc++.h>
using namespace std;
int n,sub[2222],c[2222],x,rt,ans[2222];
vector<int> g[2222];
bool f[2222];
void dfs(int x)
{
	sub[x]=1;
	for (int i=0;i<g[x].size();i++)
	{
		dfs(g[x][i]);
		sub[x]+=sub[g[x][i]];
	}
}
int calc(int l,int r)
{
	int res=0;
	for (int i=l;i<=r;i++)
	{
		if (!f[i]) res++;
	}
	return res;
}
int calc(int l,int r,int x)
{
	int res=0;
	for (int i=l;i<=r;i++)
	{
		if (!f[i])
		{
			res++;
			if (res==x) return i;
		}
	}
	return 0;
}
void solve(int l,int r,int i)
{
	if (calc(l,r)<=c[i])
	{
		printf("NO\n");
		exit(0);
	}
	ans[i]=calc(l,r,c[i]+1);
	f[ans[i]]=1;
	int cur=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		solve(calc(l,r,cur),calc(l,r,cur+sub[to]-1),to);
		cur+=sub[to];
	}
	f[ans[i]]=0;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&c[i]);
		if (x) g[x].push_back(i);
		else rt=i;
	}
	dfs(rt);
	solve(1,n,rt);
	printf("YES\n");
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}