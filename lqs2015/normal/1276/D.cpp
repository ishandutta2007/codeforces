#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,x,y,dp[222222][3],p[222222],s[222222];
vector<pair<int,int> > g[222222];
pair<int,int> a[222222];
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
void dfs(int i,int fa,int vl)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		dfs(to,i,val);
	}
	int cnt=0,d;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		a[++cnt]=make_pair(val,to);
	}
	sort(a+1,a+cnt+1);
	d=0;
	for (int j=1;j<=cnt;j++)
	{
		if (a[j].first>vl) break;
		d=j;
	}
	p[0]=1;
	for (int j=1;j<=cnt;j++) p[j]=1ll*p[j-1]*dp[a[j].second][1]%mod;
	s[cnt+1]=1;
	for (int j=cnt;j>=1;j--) s[j]=1ll*s[j+1]*(dp[a[j].second][0]+dp[a[j].second][2])%mod;
	for (int j=1;j<=d;j++)
	{
		add(dp[i][0],1ll*p[j-1]*dp[a[j].second][2]%mod*s[j+1]%mod);
	}
	dp[i][1]=dp[i][0];add(dp[i][1],1ll*p[d]*s[d+1]%mod);
	for (int j=d+1;j<=cnt;j++)
	{
		add(dp[i][2],1ll*p[j-1]*dp[a[j].second][2]%mod*s[j+1]%mod);
	}
	add(dp[i][2],p[cnt]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(make_pair(y,i));
		g[y].push_back(make_pair(x,i));
	}
	dfs(1,0,0);
	printf("%d\n",(dp[1][0]+dp[1][2])%mod);
	return 0;
}