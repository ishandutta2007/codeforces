#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
long long ans;
int N;
vector<int>G[2][2<<17];
int color[2][2<<17];
void dfs(int u,int c,int id)
{
	color[c][u]=id;
	for(int i=0;i<G[c][u].size();i++)
	{
		int v=G[c][u][i];
		if(color[c][v]==0)
		{
			dfs(v,c,id);
		}
	}
}
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		a--,b--;
		G[c][a].push_back(b);
		G[c][b].push_back(a);
	}
	int id1=1,id2=1;
	for(int i=0;i<N;i++)
	{
		if(!color[0][i]&&!G[0][i].empty())
		{
			dfs(i,0,id1++);
		}
		if(!color[1][i]&&!G[1][i].empty())
		{
			dfs(i,1,id2++);
		}
	}
	vector<vector<long long> >cnt(2,vector<long long>(max(id1,id2)));
	for(int i=0;i<N;i++)
	{
		cnt[0][color[0][i]]++;
		cnt[1][color[1][i]]++;
	}
	for(int i=0;i<N;i++)
	{
		if(color[0][i]&&color[1][i])
		{
			ans+=(cnt[0][color[0][i]]-1)*(cnt[1][color[1][i]]-1);
		}
	}
	for(int i=1;i<id1;i++)ans+=cnt[0][i]*(cnt[0][i]-1);
	for(int i=1;i<id2;i++)ans+=cnt[1][i]*(cnt[1][i]-1);
	cout<<ans<<endl;
}