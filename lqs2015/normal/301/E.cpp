#include<bits/stdc++.h>
using namespace std;
const int maxn=100,inf=200,mod=1e9+7;
int n,m,K,ans,dp[2][111][111][111],coef[111][111],cr[111][111],la,nw;
int arr[111][111],cnt[111];
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	coef[0][0]=1;
	for (int i=1;i<=maxn;i++)
	{
		for (int j=0;j<=maxn;j++)
		{
			for (int k=0;k<=j;k++)
			{
				coef[i][j]+=coef[i-1][k];
				if (coef[i][j]>inf) coef[i][j]=inf;
			}
		}
	}
	for (int i=1;i<=maxn;i++)
	{
		for (int j=0;j<=maxn;j++)
		{
			if (coef[i][j] && coef[i][j]<=K) 
			{
				arr[j][++cnt[j]]=i;
			}
		}
	}
	for (int j=0;j<=maxn;j++) sort(arr[j]+1,arr[j]+cnt[j]+1);
	nw=1;
	dp[0][0][0][1]=1;
	for (int i=1;i<=m;i++)
	{
		memset(dp[nw],0,sizeof(dp[nw]));
		memset(cr,0,sizeof(cr));
		for (int j=0;j<n;j++)
		{
			for (int k=0;k<=j;k++)
			{
				for (int h=1;h<=K;h++)
				{
					if (!dp[la][j][k][h]) continue;
					for (int p=1;p<=cnt[k] && j+arr[k][p]+k<=n;p++)
					{
						if (h*coef[arr[k][p]][k]<=K)
						{
							add(dp[nw][j+arr[k][p]+k][arr[k][p]][h*coef[arr[k][p]][k]],dp[la][j][k][h]);
						}
					}
					if (j+k<=n) add(cr[j+k][h],dp[la][j][k][h]);
				}
			}
		}
		for (int j=1;j<=n;j++)
		{
			for (int h=1;h<=K;h++)
			{
				add(ans,1ll*cr[j][h]*(m-i+1)%mod);
			}
		}
		la^=1;nw^=1;
	}
	printf("%d\n",ans);
	return 0;
}