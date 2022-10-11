#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
int a[1005],L[1005],R[1005];
bool match(int node)
{
	if (vis[node])
	return 0;
	vis[node]=1;
	for (int u:v[node])
	{
		if (L[u]==-1)
		{
			L[u]=node;
			R[node]=u;
			return 1;
		}
	}
	for (int u:v[node])
	{
		if (match(L[u]))
		{
			L[u]=node;
			R[node]=u;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for (int i=0;i<n;i++)
	{
		if (a[i]>m/3)
		{
			for (int j=0;j<n;j++)
			{
				if (2LL*a[i]+a[j]<=m && a[i]%a[j]==0)
				v[i].push_back(j);
			}
		}
	}
	memset(L,-1,sizeof(L));
	memset(R,-1,sizeof(R));
	int ok=1;
	while (ok--)
	{
		memset(vis,0,sizeof(vis));
		for (int i=0;i<n;i++)
		{
			if (a[i]>m/3 && R[i]==-1)
			ok|=match(i);
		}
	}
	vector<pair<int,int> > ans;
	for (int i=0;i<n;i++)
	{
		if (a[i]>m/3 && R[i]==-1)
		{
			printf("-1");
			return 0;
		}
		if (a[i]>m/3)
		ans.push_back({2*a[i]+a[R[i]],a[i]+a[R[i]]});
	}
	for (int i=0;i<n;i++)
	{
		if (a[i]<=m/3 && L[i]==-1)
		ans.push_back({3*a[i],2*a[i]});
	}
	printf("%d\n",ans.size());
	for (auto p:ans)
	printf("%d %d\n",p.first,p.second);
}