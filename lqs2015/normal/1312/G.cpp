#include<bits/stdc++.h>
using namespace std;
int son[1111111][26],n,pa[1111111],beg[1111111],cnt,dp[1111111],mn[1111111],k,x[1111111];
bool f[1111111];
char c;
void dfs(int i)
{
	if (f[i]) beg[i]=++cnt;
	else beg[i]=cnt;
	for (int j=0;j<26;j++)
	{
		if (son[i][j]) dfs(son[i][j]);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %c",&pa[i],&c);
		son[pa[i]][c-'a']=i;
	}
	scanf("%d",&k);
	for (int i=1;i<=k;i++) 
	{
		scanf("%d",&x[i]);
		f[x[i]]=1;
	}
	dfs(0);
	dp[0]=0;mn[0]=0;
	for (int i=1;i<=n;i++)
	{
		dp[i]=dp[pa[i]]+1;
		if (f[i])
		{
			dp[i]=min(dp[i],mn[pa[i]]+beg[i]);
			mn[i]=min(mn[pa[i]],dp[i]-beg[i]+1);
		}
		else mn[i]=min(mn[pa[i]],dp[i]-beg[i]);
	}
	for (int i=1;i<=k;i++) printf("%d ",dp[x[i]]);
	printf("\n");
	return 0;
}