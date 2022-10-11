#include <bits/stdc++.h>
using namespace std;
int a[505],cnt[2000],prod[505][505],dp[505][505];
int solve(int l,int r)
{
	if (dp[l][r]!=-1)
	return dp[l][r];
	int ret=r-l+1;
	for (int m=l;m<r;m++)
	{
		int f=solve(l,m),s=solve(m+1,r);
		ret=min(ret,f+s);
		if (f==1 && s==1 && prod[l][m] && prod[l][m]==prod[m+1][r])
		ret=1;
	}
	return dp[l][r]=ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		int mn=1e9;
		memset(cnt,0,sizeof(cnt));
		for (int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			mn=min(mn,a[j]);
			int k,mov=0,tot=0;
			for (k=mn;;k++)
			{
				if ((cnt[k]+mov)%2)
				break;
				mov=(cnt[k]+mov)/2;
				tot+=mov;
			}
			if (tot==j-i)
			prod[i][j]=k;
		}
	}
	memset(dp,-1,sizeof(dp));
	printf("%d",solve(1,n));
}