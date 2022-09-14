#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int N,f[3<<17];
vector<int>G[3<<17];
pair<int,int>dfs(int u)
{
	pair<int,int>ret;
	if(G[u].size()==0)
	{
		ret.first=ret.second=1;
		return ret;
	}
	else
	{
		ret.first=0;
		if(f[u])ret.second=1e9;
		else ret.second=0;
		for(int i=0;i<G[u].size();i++)
		{
			pair<int,int>p=dfs(G[u][i]);
			ret.first+=p.first;
			if(f[u])
			{
				ret.second=min(ret.second,p.second);
			}
			else
			{
				ret.second+=p.second;
			}
		}
	}
	return ret;
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&f[i+1]);
	for(int i=0;i<N-1;i++)
	{
		int a;scanf("%d",&a);
		G[a].push_back(i+2);
	}
	pair<int,int>p=dfs(1);
	cout<<p.first-p.second+1<<endl;
}