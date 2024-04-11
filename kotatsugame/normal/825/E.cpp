#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,M;
vector<int>G[1<<17];
int deg[1<<17];
int ans[1<<17];
main()
{
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		int u,v;cin>>u>>v;
		u--,v--;
		G[v].push_back(u);
		deg[u]++;
	}
	priority_queue<int>P;
	for(int i=0;i<N;i++)if(!deg[i])P.push(i);
	int sz=N;
	while(!P.empty())
	{
		int u=P.top();P.pop();
		ans[u]=sz--;
		for(int v:G[u])if(!--deg[v])P.push(v);
	}
	for(int i=0;i<N;i++)cout<<ans[i]<<(i+1==N?"\n":" ");
}