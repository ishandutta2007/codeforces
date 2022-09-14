#include<cstdio>
#include<vector>
using namespace std;
int N;
vector<int>G[1<<17];
vector<pair<int,int> >ans;
void dfs(int u,int t,int pr)
{
	ans.push_back(make_pair(u,t));
	int cc=0;
	for(int v:G[u])if(v!=pr)cc++;
	bool flag=false;
	int k=0;
	for(int v:G[u])if(v!=pr)
	{
		if(cc>=t)
		{
			k++;
			dfs(v,t+k,u);
		}
		else
		{
			if(!flag)
			{
				ans.push_back(make_pair(u,t-cc-1));
				flag=true;
			}
			dfs(v,t-cc,u);
		}
		cc--;
	}
	if(!flag)ans.push_back(make_pair(u,t-cc-1));
	ans.push_back(make_pair(pr,t));
}
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0,0);
	ans.pop_back();
	ans.pop_back();
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].first,ans[i].second);
}