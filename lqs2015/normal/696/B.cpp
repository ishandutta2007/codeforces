#include<bits/stdc++.h>
using namespace std;
int n,x,sub[111111];
vector<int> g[111111];
double dp[111111];
void dfs(int i)
{
	sub[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		dfs(to);
		sub[i]+=sub[to];
	}
}
void dft(int i)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		dp[to]=dp[i]+1.00+(double)(sub[i]-sub[to]-1)/2.00;
		dft(to); 
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		g[x].push_back(i); 
	}
	dfs(1);
	dp[1]=1.00;
	dft(1);
	for (int i=1;i<=n;i++)
	{
		printf("%.9lf ",dp[i]);
	}
	printf("\n");
	return 0;
}