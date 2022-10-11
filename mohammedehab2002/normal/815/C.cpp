#include <bits/stdc++.h>
using namespace std;
vector<int> dp[2][5005],v[5005];
vector<int> mul(vector<int> a,vector<int> b)
{
	vector<int> c(a.size()+b.size()-1,1e9+1);
	for (int i=0;i<a.size();i++)
	{
		for (int j=0;j<b.size();j++)
		c[i+j]=min(c[i+j],a[i]+b[j]);
	}
	return c;
}
void dfs(int node)
{
	for (int u:v[node])
	{
		dfs(u);
		dp[0][node]=mul(dp[0][node],dp[0][u]);
		dp[1][node]=mul(dp[1][node],dp[1][u]);
	}
	for (int i=0;i<dp[0][node].size();i++)
	dp[1][node][i]=min(dp[1][node][i],dp[0][node][i]);
}
int main()
{
	int n,b;
	scanf("%d%d",&n,&b);
	for (int i=1;i<=n;i++)
	{
		int c,d,p;
		scanf("%d%d",&c,&d);
		dp[0][i].push_back(0);
		dp[0][i].push_back(c);
		dp[1][i].push_back(1e9+1);
		dp[1][i].push_back(c-d);
		if (i>1)
		{
			scanf("%d",&p);
			v[p].push_back(i);
		}
	}
	dfs(1);
	for (int i=1;i<=n;i++)
	{
		if (dp[1][1][i]>b)
		{
			printf("%d",i-1);
			return 0;
		}
	}
	printf("%d",n);
}