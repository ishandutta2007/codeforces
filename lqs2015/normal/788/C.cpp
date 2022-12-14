#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> g[2222];
bool used[2222];
int n,k,x,dist[2222];
queue<int> q;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&x);
		used[x]=1;
	}
	for (int i=0;i<=2000;i++)
	{
		for (int j=0;j<=1000;j++)
		{
			if (used[j])
			{
				if (i+j-n<=2000 && i+j-n>=0) g[i].push_back(i+j-n);
			}
		}
	}
	for (int i=0;i<=1000;i++)
	{
		if (used[i]) 
		{
			dist[i-n+1000]=1;
			q.push(i-n+1000); 
		}
	}
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i];
			if (!dist[to])
			{
				dist[to]=dist[x]+1;
				q.push(to); 
			}
		}
	}
	if (!dist[1000]) printf("-1\n");
	else printf("%d\n",dist[1000]);
	return 0;
}