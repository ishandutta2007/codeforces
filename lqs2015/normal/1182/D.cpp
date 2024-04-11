#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,x,y,dp[111111],pa[111111],DP[111111],cur,fst[111111],lst[111111];
vector<int> g[111111],pre[111111],suf[111111];
void dfs(int i,int fa)
{
	pa[i]=fa;
	int cnt=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (fst[i]==-1) fst[i]=to;
		lst[i]=to;
		cnt++;
		dfs(to,i);
	}
	pre[i].resize(g[i].size()+1);suf[i].resize(g[i].size()+1);
	cur=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) 
		{
			pre[i][j]=cur;
			continue;
		}
		cur=1ll*cur*dp[to]%mod;
		if (dp[to]!=dp[fst[i]]) cur=0;
		pre[i][j]=cur;
	}
	cur=1;
	for (int j=(int)g[i].size()-1;j>=0;j--)
	{
		int to=g[i][j];
		if (to==fa) 
		{
			suf[i][j]=cur;
			continue;
		}
		cur=1ll*cur*dp[to]%mod;
		if (dp[to]!=dp[lst[i]]) cur=0;
		suf[i][j]=cur;
	}
	dp[i]=1ll*suf[i][0]*(cnt+1)%mod*(cnt+1)%mod;
}
void dft(int i,int fa)
{
	int cnt=(int)g[i].size()-1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		cur=1;
		if (j>0)
		{
			cur=1ll*cur*pre[i][j-1]%mod;
			if (j>1 || fst[i]==g[i][0])
			{
				if (fa && dp[fst[i]]!=DP[i]) cur=0;
				if (j<(int)g[i].size()-1 && (j<(int)g[i].size()-2 || lst[i]==g[i][(int)g[i].size()-1]) && dp[lst[i]]!=dp[fst[i]]) cur=0; 
			}
		}
		if (j<(int)g[i].size()-1)
		{
			cur=1ll*cur*suf[i][j+1]%mod;
			if (j<(int)g[i].size()-2 || lst[i]==g[i][(int)g[i].size()-1])
			{
				if (fa && dp[lst[i]]!=DP[i]) cur=0;
			}
		}
		if (fa) cur=1ll*cur*DP[i]%mod;
		cur=1ll*cur*(cnt+1)%mod*(cnt+1)%mod;
		DP[to]=cur;
		dft(to,i);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	memset(fst,-1,sizeof(fst));
	memset(lst,-1,sizeof(lst));
	dfs(1,0);
	dft(1,0);
	bool f=0;
	for (int i=0;i<g[1].size();i++)
	{
		if (dp[g[1][i]]!=dp[g[1][0]] || !dp[g[1][i]]) f=1;
	}
	if (!f)
	{
		printf("1\n");
		return 0;
	}
	for (int i=2;i<=n;i++)
	{
		f=0;
		if (!DP[i]) f=1;
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			if (to==pa[i]) continue;
			if (dp[to]!=DP[i] || !dp[to]) f=1;
		}
		if (!f)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}