#include<bits/stdc++.h>
using namespace std;
int n,a[222222],sz,son[6666666][2],cur,sub[6666666],fa[6666666],dp[6666666];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sz=1;
	for (int i=1;i<=n;i++)
	{
		cur=1;
		for (int j=29;j>=0;j--)
		{
			if (a[i]&(1<<j)) 
			{
				if (son[cur][1]) cur=son[cur][1];
				else cur=son[cur][1]=++sz;
			}
			else
			{
				if (son[cur][0]) cur=son[cur][0];
				else cur=son[cur][0]=++sz;
			}
		}
		sub[cur]++;
	}
	for (int i=1;i<=sz;i++)
	{
		if (son[i][0]) fa[son[i][0]]=i;
		if (son[i][1]) fa[son[i][1]]=i;
	}
	for (int i=sz;i>=1;i--)
	{
		sub[fa[i]]+=sub[i];
		if (!son[i][0] && !son[i][1]) dp[i]=0;
		else if (!son[i][0]) dp[i]=dp[son[i][1]];
		else if (!son[i][1]) dp[i]=dp[son[i][0]];
		else dp[i]=min(dp[son[i][0]]+sub[son[i][1]]-1,dp[son[i][1]]+sub[son[i][0]]-1);
	}
	printf("%d\n",dp[1]);
	return 0;
}