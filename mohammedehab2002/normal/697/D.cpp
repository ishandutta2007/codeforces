#include <iostream>
#include <vector>
using namespace std;
int sz[100005];
double dp[100005];
vector<int> v[100005];
void pre(int node)
{
	sz[node]=1;
	for (int u:v[node])
	{
		pre(u);
		sz[node]+=sz[u];
	}
}
void dfs(int node)
{
	double s=0;
	for (int u:v[node])
	s+=sz[u];
	for (int u:v[node])
	{
		dp[u]=dp[node]+(s-sz[u])/2+1;
		dfs(u);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		v[a].push_back(i);
	}
	pre(1);
	dp[1]=1;
	dfs(1);
	for (int i=1;i<=n;i++)
	printf("%.6lf ",dp[i]);
}