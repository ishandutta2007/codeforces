#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
bool u[222222],used[222222];
int n,a[222222],x,y,dist[222222],pos,cnt;
vector<int> g[222222],v;
queue<int> q;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		if (used[a[i]]) 
		{
			printf("No\n");
			return 0;
		}
		used[a[i]]=1;
	}
	if (a[1]!=1) 
	{
		printf("No\n");
		return 0;
	}
	for (int i=1;i<=n;i++) dist[i]=-1;
	dist[1]=0;
	q.push(1);
	pos=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		cnt=0;
		v.clear();
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i];
			if (!~dist[to]) 
			{
				cnt++;
				v.push_back(to);
				u[to]=1; 
			}
		}
		for (int i=1;i<=cnt;i++)
		{
			pos++;
			if (!u[a[pos]])
			{
				printf("No\n");
				return 0;
			}
			dist[a[pos]]=dist[x]+1;
			q.push(a[pos]); 
		}
		for (int i=0;i<v.size();i++) u[v[i]]=0;
	} 
	printf("Yes\n");
	return 0;
}