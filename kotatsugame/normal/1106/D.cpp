#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
int n,m;
vector<int>G[1<<17];
priority_queue<int,vector<int>,greater<int> >P;
bool used[1<<17];
main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	P.push(1);
	vector<int>ans;
	used[1]=1;
	while(!P.empty())
	{
		int u=P.top();
		P.pop();
		ans.push_back(u);
		for(int i=0;i<G[u].size();i++)
		{
			if(!used[G[u][i]])
			{
				P.push(G[u][i]);
				used[G[u][i]]=1;
			}
		}
	}
	for(int i=0;i<n;i++)printf("%d%c",ans[i],i==n-1?'\n':' ');
}