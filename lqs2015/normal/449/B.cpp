#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,z,dist[111111],ans,mn[111111],distt[111111],tot[111111];
vector<pair<long long,long long> > g[111111];
priority_queue<pair<long long,long long> > pq;
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for (long long i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));  
	}
	for (long long i=1;i<=n;i++) dist[i]=1e18;
	dist[1]=0;
	pq.push(make_pair(0,1));
	while(!pq.empty()) 
	{
		long long x=pq.top().second,y=-pq.top().first;pq.pop();
		if (dist[x]!=y) continue;
		for (long long i=0;i<g[x].size();i++)
		{
			long long to=g[x][i].first,val=g[x][i].second;
			if (dist[to]>dist[x]+val)
			{
				dist[to]=dist[x]+val;
				pq.push(make_pair(-dist[to],to)); 
			}
		}
	}
	ans=k;
	for (long long i=1;i<=n;i++) mn[i]=1e18;
	for (long long i=1;i<=k;i++)
	{
		scanf("%lld%lld",&x,&y);
		mn[x]=min(mn[x],y);
	}
	for (long long i=1;i<=n;i++)
	{
		if (mn[i]==1e18) continue;
		g[1].push_back(make_pair(i,mn[i])); 
	}
	for (long long i=1;i<=n;i++) distt[i]=1e18;
	distt[1]=0;
	pq.push(make_pair(0,1));
	while(!pq.empty()) 
	{
		long long x=pq.top().second,y=-pq.top().first;pq.pop();
		if (distt[x]!=y) continue;
		for (long long i=0;i<g[x].size();i++)
		{
			long long to=g[x][i].first,val=g[x][i].second;
			if (distt[to]>distt[x]+val)
			{
				distt[to]=distt[x]+val;
				pq.push(make_pair(-distt[to],to)); 
			}
		}
	}
	for (long long i=1;i<=n;i++)
	{
		for (long long j=0;j<g[i].size();j++)
		{
			long long to=g[i][j].first,val=g[i][j].second;
			if (distt[to]==distt[i]+val) tot[to]++;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (mn[i]==1e18) continue;
		if (mn[i]<dist[i] && mn[i]==distt[i] && tot[i]==1) ans--;
	}
	printf("%lld\n",ans);
	return 0;
}