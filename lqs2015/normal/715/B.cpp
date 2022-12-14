#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
long long n,m,l,s,t,x[11111],y[11111],z[11111],L,R,mid,xp,dist[11111];
vector<pair<long long,long long> > g[1111];
bool can[11111];
long long dijk()
{
	priority_queue<pair<long long,long long> > pq;
	pq.push(make_pair(0,s));
	for (long long i=0;i<n;i++) dist[i]=1e18;
	dist[s]=0;
	while(!pq.empty())
	{
		long long x=pq.top().second;pq.pop();
		for (int i=0;i<g[x].size();i++)
		{
			long long to=g[x][i].first,val=g[x][i].second;
			if (dist[to]>dist[x]+val)
			{
				dist[to]=dist[x]+val;
				pq.push(make_pair(-dist[to],to)); 
			}
		}
	}
	return dist[t];
}
int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&l,&s,&t);
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&x[i],&y[i],&z[i]);
		if (z[i]) 
		{
			g[x[i]].push_back(make_pair(y[i],z[i]));
			g[y[i]].push_back(make_pair(x[i],z[i])); 
		}
	}
	if (dijk()<l)
	{
		printf("NO\n");
		return 0;
	}
	L=1;R=1E18;
	while(L<=R)
	{
		mid=(L+R)/2;
		for (long long i=0;i<n;i++) g[i].clear();
		for (long long i=1;i<=m;i++)
		{
			if (!z[i]) 
			{
				g[x[i]].push_back(make_pair(y[i],mid));
				g[y[i]].push_back(make_pair(x[i],mid));  
			}
			else
			{
				g[x[i]].push_back(make_pair(y[i],z[i]));
				g[y[i]].push_back(make_pair(x[i],z[i]));  
			}
		}
		xp=dijk();
		if (xp==l)
		{
			printf("YES\n");
			for (long long i=1;i<=m;i++)
			{
				if (!z[i]) printf("%I64d %I64d %I64d\n",x[i],y[i],mid);
				else printf("%I64d %I64d %I64d\n",x[i],y[i],z[i]);
			}
			return 0;
		}
		if (xp>l) R=mid-1;
		else L=mid+1;
	}
	if (R<=0)
	{
		printf("NO\n");
		return 0;
	}
	for (long long i=1;i<=m;i++)
	{
		if (!z[i]) 
		{
			can[i]=1;
			z[i]=R;
		}
	}
	for (long long i=1;i<=m;i++)
	{
		if (can[i])
		{
			z[i]=L;
			for (long long j=0;j<n;j++) g[j].clear();
			for (long long j=1;j<=m;j++)
			{
				g[x[j]].push_back(make_pair(y[j],z[j]));
				g[y[j]].push_back(make_pair(x[j],z[j]));  
			}
			if (dijk()==l)
			{
				printf("YES\n");
				for (long long j=1;j<=m;j++)
				{
					printf("%I64d %I64d %I64d\n",x[j],y[j],z[j]);
				}
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}