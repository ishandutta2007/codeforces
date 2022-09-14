#include<cstdio>
#include<vector>
#include<map>
using namespace std;
int N;
int A[2<<17];
vector<int>G[2<<17];
int add[2<<17];
map<int,int>ret;
int r;
void dfs1(int u,int p)
{
	map<int,int>all;
	for(int v:G[u])if(v!=p)
	{
		dfs1(v,u);
		if(ret.find(A[u])!=ret.end())
		{
			add[r]++;
			add[v]--;
			add[ret[A[u]]]++;
		}
		if(ret.size()>all.size())all.swap(ret);
		for(pair<int,int>p:ret)
		{
			if(all.find(p.first)!=all.end())
			{
				add[p.second]++;
				add[all[p.first]]++;
			}
			all[p.first]=p.second;
		}
	}
	all[A[u]]=u;
	ret.swap(all);
}
map<int,int>ac;
int dfs2(int u,int p)
{
	int ret=0;
	if(add[u]==0)ret++;
	for(int v:G[u])if(v!=p)
	{
		add[v]+=add[u];
		ret+=dfs2(v,u);
	}
	return ret;
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		ac[A[i]]++;
	}
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	while(r<N&&ac[A[r]]>1)r++;
	if(r==N)puts("0");
	else
	{
		dfs1(r,-1);
		printf("%d\n",dfs2(r,-1));
	}
}