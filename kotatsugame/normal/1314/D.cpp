#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
vector<pair<int,int> >dist[80][80];
int d[80][80];
int A[6];
int ans=2e9;
void dfs(int id)
{
	if(id==K/2)
	{
		int now=0;
		for(int i=0;i<K/2;i++)
		{
			bool ok=false;
			for(pair<int,int>p:dist[A[i]][A[i+1]])
			{
				int v=p.second;
				bool flag=true;
				for(int j=0;j<K/2;j++)
				{
					if(v==A[j])
					{
						flag=false;
						break;
					}
				}
				if(flag)
				{
					now+=p.first;
					ok=true;
					break;
				}
			}
			if(!ok)return;
		}
		ans=min(ans,now);
		return;
	}
	for(int i=0;i<N;i++)
	{
		A[id]=i;
		dfs(id+1);
	}
}
main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>d[i][j];
	for(int u=0;u<N;u++)for(int v=0;v<N;v++)
	{
		for(int k=0;k<N;k++)
		{
			if(u==k||v==k)continue;
			dist[u][v].push_back(make_pair(d[u][k]+d[k][v],k));
		}
		sort(dist[u][v].begin(),dist[u][v].end());
	}
	dfs(1);
	cout<<ans<<endl;
}