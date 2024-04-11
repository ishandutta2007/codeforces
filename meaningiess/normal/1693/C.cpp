#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
int n,dis[N],vis[N],cnt[N],c[N];
vector<int> e1[N],e2[N];
priority_queue<pair<int,int> >pq;
void dij()
{
	pq.push({0,n});int i;
	for (i=1;i<=n;i++) dis[i]=1e8;
	dis[n]=0;
	while (!pq.empty())
	{
		pair<int,int> x=pq.top();pq.pop();
		//cout<<x.second<<' '<<-x.first<<' '<<c[x.second]<<endl;
		if (vis[x.second]) continue;vis[x.second]=1;
		for (auto p:e2[x.second]) 
		{
			cnt[p]++;
			if (dis[p]>dis[x.second]+c[p]+1-cnt[p])
			{
				dis[p]=dis[x.second]+c[p]+1-cnt[p];
				pq.push({-dis[p],p});
			}
		}
	}
}
int u[N],v[N];
int main()
{
	int m,i,ans=0;cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i];c[u[i]]++;
		e1[u[i]].push_back(v[i]);
		e2[v[i]].push_back(u[i]);
	}
	dij();cout<<dis[1];
}