#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int>G[2<<17];
vector<int>dp[2<<17];
bool dfs(int u,int p)
{
	vector<int>now;
	for(int v:G[u])if(v!=p)
	{
		if(dfs(v,u))return true;
		for(int x:dp[v])now.push_back(x);
	}
	sort(now.begin(),now.end());
	int id=0;
	int cur=0;
	while(id<now.size())
	{
		if(cur==0)
		{
			if(now[id]==0)
			{
				cur=1;
				id++;
			}
			else if(now[id]==1)
			{
				cur=2;
				id++;
			}
			else break;
		}
		else
		{
			if(now[id]==cur+1)
			{
				cur+=2;
				id++;
			}
			else if(now[id]==cur-1)
			{
				cur++;
				id++;
			}
			else break;
		}
	}
	if(id<now.size())
	{
		if(cur>now[id])return true;
		if(cur==now[id]&&id+1<now.size()&&cur==now[id+1])return true;
	}
	dp[u].push_back(cur);
	for(int j=id;j<now.size();j++)dp[u].push_back(now[j]);
	return false;
}
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(dfs(0,-1))
	{
		puts("NO");
		return 0;
	}
	puts(dp[0].size()==1?"YES":"NO");
}