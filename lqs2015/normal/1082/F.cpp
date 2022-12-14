#include<bits/stdc++.h>
using namespace std;
int n,k,sz,son[1111][11],val[1111],cur,len,dep[1111],x,ans;
int dp[555][555][22],beg[555],en[555],cnt,f[555][22],g[555][22];
char opt[555];
void prec(int i)
{
	beg[i]=++cnt;
	for (int j=0;j<10;j++)
	{
		if (son[i][j]) prec(son[i][j]);
	}
	en[i]=cnt;
}
void dfs(int i)
{
	for (int j=0;j<10;j++)
	{
		if (son[i][j]) dfs(son[i][j]);
	}
	for (int j=1;j<=sz;j++)
	{
		if (beg[j]<=beg[i] && en[j]>=en[i]) 
		{
			for (int h=1;h<=k;h++) f[j][h]=1e9;
			f[j][0]=0;
		}
		else
		{
			for (int h=0;h<=k;h++) f[j][h]=1e9;
		}
	}
	for (int j=0;j<10;j++)
	{
		if (!son[i][j]) continue;
		int to=son[i][j];
		for (int h=1;h<=sz;h++)
		{
			for (int s=0;s<=k;s++)
			g[h][s]=1e9;
		}
		for (int h=1;h<=sz;h++)
		{
			for (int s=0;s<=k;s++)
			{
				for (int t=0;t<=k-s;t++)
				{
					g[h][s+t]=min(g[h][s+t],f[h][s]+min(dp[to][h][t],dp[to][to][t]));
				}
			}
		}
		for (int h=1;h<=sz;h++)
		{
			for (int s=0;s<=k;s++)
			f[h][s]=g[h][s];
		}
	}
	for (int h=1;h<=sz;h++)
	{
		if (beg[h]<=beg[i] && en[h]>=en[i])
		{
			for (int s=0;s<=k;s++)
			{
				f[h][s]+=((dep[i]-dep[h])*val[i]);
			}
		}
		if (i==h)
		{
			if (i==1)
			{
				for (int s=0;s<=k;s++) dp[i][h][s]=f[h][s];
			}
			else
			{
				dp[i][h][0]=1e9;
				for (int s=1;s<=k;s++) dp[i][h][s]=f[h][s-1];
			}
		}
		else
		{
			for (int s=0;s<=k;s++) dp[i][h][s]=f[h][s];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	sz=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",opt);
		len=strlen(opt);
		cur=1;
		for (int j=0;j<len;j++)
		{
			if (son[cur][opt[j]-'0']) cur=son[cur][opt[j]-'0'];
			else
			{
				++sz;dep[sz]=dep[cur]+1;
				cur=son[cur][opt[j]-'0']=sz;
			}
		}
		scanf("%d",&x);
		val[cur]+=x;
	}
	prec(1);
	dfs(1);
	ans=1e9;
	for (int i=0;i<=k;i++) ans=min(ans,dp[1][1][i]);
	printf("%d\n",ans);
	return 0;
}