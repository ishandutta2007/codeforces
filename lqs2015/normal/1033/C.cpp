#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n,a[111111],dp[111111],deg[111111],v[111111],cnt;
vector<int> g[111111];
queue<int> q;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=i-a[i];j>=1;j-=a[i]) 
		{
			if (a[j]>a[i]) 
			{
				g[i].push_back(j);	
				deg[j]++;
			} 
		}
		for (int j=i+a[i];j<=n;j+=a[i])
		{
			if (a[j]>a[i]) 
			{
				g[i].push_back(j);
				deg[j]++;
			} 
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!deg[i]) q.push(i); 
	}
	while(!q.empty())
	{
		int x=q.front();q.pop();
		v[++cnt]=x;
		for (int i=0;i<g[x].size();i++) 
		{
			deg[g[x][i]]--;
			if (!deg[g[x][i]]) q.push(g[x][i]); 
		}
	}
	for (int i=cnt;i>=1;i--)
	{
		for (int j=0;j<g[v[i]].size();j++)
		{
			int to=g[v[i]][j];
			if (!dp[to]) dp[v[i]]=1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (dp[i]) printf("A");
		else printf("B");
	}
	return 0;
}