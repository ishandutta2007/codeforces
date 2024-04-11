#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long n,m,c[111111],x,y,mn,ans;
vector<long long> g[111111],v;
bool used[111111];
void dfs(long long i)
{
	v.push_back(i); 
	used[i]=1;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (!used[to]) dfs(to);
	}
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&c[i]);
	}
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x); 
	}
	for (long long i=1;i<=n;i++)
	{
		if (!used[i])
		{
			mn=1e18;
			v.clear();
			dfs(i);
			for (long long j=0;j<v.size();j++)
			{
				if (mn>c[v[j]]) mn=c[v[j]];
			}
			ans+=mn;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}