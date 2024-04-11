#include<cstdio>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int N,M,K;
vector<string>T;
vector<pair<int,int> >G[2<<17];
int dist[2<<17];
int ans[2<<17];
vector<int>es[2<<17];
vector<int>vs;
bool dfs(int id)
{
	if(id==vs.size())
	{
		string now="";
		for(int i=0;i<M;i++)now+=ans[i]+'0';
		T.push_back(now);
		return T.size()==K;
	}
	for(int ei:es[vs[id]])
	{
		ans[ei]=1;
		if(dfs(id+1))return true;
		ans[ei]=0;
	}
	return false;
}
main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(make_pair(v,i));
		G[v].push_back(make_pair(u,i));
	}
	for(int i=1;i<N;i++)dist[i]=1e9;
	queue<int>P;
	P.push(0);
	while(!P.empty())
	{
		int u=P.front();P.pop();
		for(pair<int,int>e:G[u])
		{
			int v=e.first;
			if(dist[v]>dist[u]+1)
			{
				dist[v]=dist[u]+1;
				es[v].push_back(e.second);
				ans[e.second]=1;
				P.push(v);
			}
			else if(dist[v]==dist[u]+1)
			{
				es[v].push_back(e.second);
			}
		}
	}
	for(int i=0;i<N;i++)if(es[i].size()>=2)vs.push_back(i);
	dfs(0);
	printf("%d\n",T.size());
	for(int i=0;i<T.size();i++)printf("%s\n",T[i].c_str());
}