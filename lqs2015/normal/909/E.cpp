#include<bits/stdc++.h>
using namespace std;
int n,m,a[111111],deg[111111],x,y,cnt,ans;
vector<int> g[111111];
queue<int> qm,qc;
void process_main()
{
	while(!qm.empty())
	{
		int x=qm.front();qm.pop();cnt++;
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i];
			deg[to]--;
			if (!deg[to])
			{
				if (!a[to]) qm.push(to);
				else qc.push(to);
			}
		}
	}
}
void process_c()
{
	while(!qc.empty())
	{
		int x=qc.front();qc.pop();cnt++;
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i];
			deg[to]--;
			if (!deg[to])
			{
				if (!a[to]) qm.push(to);
				else qc.push(to);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);x++;y++;
		deg[x]++;g[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
	{
		if (!deg[i])
		{
			if (!a[i]) qm.push(i);
			else qc.push(i);
		}
	}
	while(cnt<n)
	{
		process_main();
		if (cnt<n) 
		{
			ans++;
			process_c();
		}
	}
	printf("%d\n",ans);
	return 0;
}