#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int dp[2][N+5];
int a[N+5],d[N+5],ans[N+5],cnt[N+5],dep[N+5];
int n;
vector<int> g[N+5];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	if(d[fa]==-1) d[u]=a[u];
	else d[u]=__gcd(a[u],d[fa]);
	ans[u]=max(ans[u],d[fa]);
	for(int i=1;i*i<=a[u];i++)
	{
		if(a[u]%i==0)
		{
			cnt[i]++;
			if(cnt[i]>=dep[u]-1) ans[u]=max(ans[u],i);
			if(i*i==a[u]) continue;
			cnt[a[u]/i]++;
			if(cnt[a[u]/i]>=dep[u]-1) ans[u]=max(ans[u],a[u]/i);
		}
	}
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
	for(int i=1;i*i<=a[u];i++)
	{
		if(a[u]%i==0)
		{
			cnt[i]--;
			if(i*i==a[u]) continue;
			cnt[a[u]/i]--;
		}
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int u,v;
	for(int i=1;i<=n-1;i++) scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	d[0]=-1;
	dep[0]=0;
	dfs(1,0);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}