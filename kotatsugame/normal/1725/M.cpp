#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,M;
vector<pair<int,int> >G[1<<17],RG[1<<17];
long long D1[1<<17],D2[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		u--,v--;
		G[u].push_back(make_pair(v,w));
		RG[v].push_back(make_pair(u,w));
	}
	for(int i=0;i<N;i++)D1[i]=1e18;
	D1[0]=0;
	priority_queue<pair<long long,int> >Q;
	Q.push(make_pair(0,0));
	while(!Q.empty())
	{
		long long c=-Q.top().first;
		int u=Q.top().second;
		Q.pop();
		if(D1[u]<c)continue;
		for(pair<int,int>e:G[u])
		{
			int v=e.first;
			long long nc=c+e.second;
			if(D1[v]>nc)
			{
				D1[v]=nc;
				Q.push(make_pair(-nc,v));
			}
		}
	}
	for(int i=0;i<N;i++)Q.push(make_pair(-D1[i],i));
	while(!Q.empty())
	{
		long long c=-Q.top().first;
		int u=Q.top().second;
		Q.pop();
		if(D1[u]<c)continue;
		for(pair<int,int>e:RG[u])
		{
			int v=e.first;
			long long nc=c+e.second;
			if(D1[v]>nc)
			{
				D1[v]=nc;
				Q.push(make_pair(-nc,v));
			}
		}
	}
	for(int i=1;i<N;i++)
	{
		long long ans=D1[i];
		if(ans==(long long)1e18)ans=-1;
		cout<<ans<<(i+1==N?"\n":" ");
	}
}