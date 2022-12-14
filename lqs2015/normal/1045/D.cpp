#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,x,y,q,pa[111111];
double p[111111],dp[111111],cur,ans,sum[111111];
vector<int> g[111111];
void dfs(int i,int fa)
{
	pa[i]=fa;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		dp[i]+=dp[to];
		sum[i]+=(1.00-p[to]);
	}
	dp[i]-=(1.00-p[i])*(sum[i]-1.00);
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lf",&p[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	dfs(0,-1);
	scanf("%d",&q);
	ans=dp[0];
	while(q--)
	{
		scanf("%d%lf",&x,&cur);
		if (x==0)
		{
			ans-=(p[0]-cur)*(sum[0]-1);
		}
		else
		{
			ans-=(p[x]-cur)*(sum[x]-1);
			sum[pa[x]]-=(cur-p[x]);
			ans+=(1.00-p[pa[x]])*(cur-p[x]);
		}
		p[x]=cur;
		printf("%.5lf\n",ans);
	}
	return 0;
}