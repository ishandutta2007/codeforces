#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,z,dist[333333],cnt;
vector<pair<long long,pair<long long,long long> > > g[333333];
vector<pair<long long,long long> > gg[333333];
vector<long long> ans;
priority_queue<pair<long long,long long> > pq;
bool f[333333];
void dfs(long long i,long long fa)
{
	if (ans.size()==k) return;
	for (long long j=0;j<gg[i].size();j++)
	{
		long long to=gg[i][j].first,id=gg[i][j].second;
		if (to==fa) continue;
		if (ans.size()==k) return;
		ans.push_back(id);
		dfs(to,i); 
	}
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		g[x].push_back(make_pair(y,make_pair(z,i)));
		g[y].push_back(make_pair(x,make_pair(z,i)));  
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
			long long to=g[x][i].first,val=g[x][i].second.first;
			if (dist[to]>dist[x]+val)
			{
				dist[to]=dist[x]+val;
				pq.push(make_pair(-dist[to],to)); 
			}
		}
	} 
	for (long long i=2;i<=n;i++)
	{
		for (long long j=0;j<g[i].size();j++)
		{
			long long to=g[i][j].first,val=g[i][j].second.first,id=g[i][j].second.second;
			if (dist[i]==dist[to]+val)
			{
				gg[i].push_back(make_pair(to,id));
				gg[to].push_back(make_pair(i,id));  
				break;
			}
		}
	}
	dfs(1,0);
	printf("%I64d\n",(long long)ans.size());
	for (long long i=0;i<ans.size();i++) printf("%I64d ",ans[i]);
	return 0;
}