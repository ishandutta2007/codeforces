#include<cstdio>
#include<vector>
using namespace std;
int N,M,K;
vector<int>G[1<<17];
vector<int>now,roop;
int depth[1<<17];
void dfs(int u,int p)
{
	now.push_back(u);
	depth[u]=now.size();
	int gt=0;
	for(int v:G[u])if(v!=p)
	{
		if(depth[v])
		{
			if(gt<depth[v])gt=depth[v];
		}
	}
	if(gt>0&&roop.empty())
	{
		roop=vector<int>(now.begin()+gt-1,now.end());
	}
	for(int v:G[u])if(v!=p)
	{
		if(!depth[v])
		{
			dfs(v,u);
		}
	}
	now.pop_back();
}
main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	if(!roop.empty())
	{
		if(roop.size()<=K)
		{
			printf("2\n%d\n",(int)roop.size());
			for(int i=0;i<roop.size();i++)printf("%d%c",roop[i],roop.size()==i+1?'\n':' ');
		}
		else
		{
			K=(K+1)/2;
			printf("1\n");
			for(int i=0;i<K;i++)printf("%d%c",roop[i*2],i+1==K?'\n':' ');
		}
	}
	else
	{
		vector<int>A[2];
		for(int i=1;i<=N;i++)A[depth[i]%2].push_back(i);
		K=(K+1)/2;
		printf("1\n");
		if(A[0].size()>=K)
		{
			for(int i=0;i<K;i++)printf("%d%c",A[0][i],i+1==K?'\n':' ');
		}
		else
		{
			for(int i=0;i<K;i++)printf("%d%c",A[1][i],i+1==K?'\n':' ');
		}
	}
}