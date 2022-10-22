#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int dp[maxn+5][maxn+5][26];
int g[maxn+5][maxn+5];
char a[maxn+5];
int f[maxn+5];
int n;
int dfs(int l,int r,int op)
{
	if(op<0||op>25) return 0;
	if(dp[l][r][op]!=-1) return dp[l][r][op];
	if(l==r)
	{
		if(op==a[l]-'a') dp[l][r][op]=1;
		else dp[l][r][op]=0;
		return dp[l][r][op];
	}
	dp[l][r][op]=0;
	for(int i=l;i<=r-1;i++)
	{
		if(dfs(l,i,op+1)&&dfs(i+1,r,op)) dp[l][r][op]=1;
		if(dfs(l,i,op)&&dfs(i+1,r,op+1)) dp[l][r][op]=1;
	}
	return dp[l][r][op];
}
int main()
{
	scanf("%d",&n);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=0;k<=25;k++) dp[i][j][k]=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=0;k<=25;k++)
			{
				g[i][j]|=dfs(i,j,k);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=n+1;
		for(int j=i-1;j>=0;j--)
		{
			if(g[j+1][i]) f[i]=min(f[i],f[j]+1);
		}
	}
	printf("%d\n",n-f[n]);
	return 0;
}