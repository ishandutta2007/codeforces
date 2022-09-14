#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N,M;
vector<int>G[2<<17];
int deg[2<<17];
bool vis[2<<17];
int dp[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		int u,v;cin>>u>>v;
		u--,v--;
		deg[u]++;
		G[v].push_back(u);
	}
	for(int i=0;i<N;i++)dp[i]=1e9;
	dp[N-1]=0;
	priority_queue<pair<int,int> >Q;
	Q.push(make_pair(0,N-1));
	while(!Q.empty())
	{
		int c=-Q.top().first,u=Q.top().second;
		Q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int v:G[u])
		{
			--deg[v];
			int t=deg[v]+c+1;
			if(dp[v]>t)
			{
				dp[v]=t;
				Q.push(make_pair(-t,v));
			}
		}
	}
	cout<<dp[0]<<"\n";
}