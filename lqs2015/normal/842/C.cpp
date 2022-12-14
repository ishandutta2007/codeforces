#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<int> g[222222],pr[222222];
bool f[222222];
int prime[111111],cnt,n,pos,a[222222],x,y,ans[222222],num[222222],mx;
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
void dfs(int i,int fa,int dep,int z)
{
	if (!fa) ans[i]=a[i];
	else
	{
		mx=0;
		for (int j=0;j<pr[a[i]].size();j++)
		{
			if (num[pr[a[i]][j]]>=dep-1) mx=pr[a[i]][j]; 
		}
		ans[i]=max(z,mx);
	}
	for (int j=0;j<pr[a[i]].size();j++)
	{
		num[pr[a[i]][j]]++;
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (i==1) dfs(to,i,dep+1,a[1]);
		else dfs(to,i,dep+1,gcd(z,a[i]));
	}
	for (int j=0;j<pr[a[i]].size();j++)
	{
		num[pr[a[i]][j]]--;
	}
}
int main()
{
	for (int i=2;i<=200000;i++)
	{
		if (!f[i])
		{
			for (int j=i+i;j<=200000;j+=i) f[j]=1;
		}
	}
	for (int i=2;i<=200000;i++) 
	{
		if (!f[i]) prime[++cnt]=i;
	}
	for (int i=1;i<=200000;i++)
	{
		for (int j=i;j<=200000;j+=i)
		pr[j].push_back(i); 
	}
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	dfs(1,0,0,0);
	for (int i=1;i<=n;i++) 
	printf("%d ",ans[i]);
	return 0;
}