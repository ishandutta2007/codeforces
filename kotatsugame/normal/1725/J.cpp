#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
vector<pair<int,int> >G[1<<17];
long long dp[1<<17][5][2];
void dfs(int u,int p)
{
	long long tmp[5][2];
	for(int i=0;i<5;i++)for(int j=0;j<2;j++)dp[u][i][j]=0;
	for(pair<int,int>e:G[u])if(e.first!=p)
	{
		int v=e.first;
		int w=e.second;
		dfs(v,u);
		for(int i=0;i<5;i++)for(int j=0;j<2;j++)tmp[i][j]=1e18;
		for(int i=0;i<5;i++)for(int j=0;i+j<=4;j++)
		{
			int ni=i+j;
			for(int k=0;k<2;k++)for(int l=0;k+l<=1;l++)
			{
				long long now=dp[u][i][k]+dp[v][j][l]+(j%2==0?w+w:w);
				tmp[ni][k|l]=min(tmp[ni][k|l],now);
				if((k|l)==0&&j==2)
				{
					tmp[ni][1]=min(tmp[ni][1],now-w-w);
				}
			}
		}
		for(int i=0;i<5;i++)for(int j=0;j<2;j++)dp[u][i][j]=tmp[i][j];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=1;i<N;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		u--,v--;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	dfs(0,-1);
	cout<<dp[0][4][1]<<endl;
}