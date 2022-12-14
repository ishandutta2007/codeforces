#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,maxn=60;
int n,m,k,inv[222],cnt[22],dp[22][111][22],nmsk,ddp[22][22][111],shold[22][111],ans;
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
int C(int n,int k)
{
	if (n<k || n<0 || k<0) return 0;
	int res=1;
	for (int i=1;i<=k;i++)
	{
		res=1ll*res*(n-i+1)%mod*inv[i]%mod;
	}
	return res;
}
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
int main()
{
	for (int i=1;i<=200;i++) inv[i]=binpow(i,mod-2);
	scanf("%d%d%d",&n,&k,&m);
	for (int i=0;i<(1<<m);i++)
	{
		for (int j=0;j<m;j++)
		{
			if (i&(1<<j)) cnt[i]++;
		}
	}
	dp[0][0][0]=1;
	for (int i=0;i<k;i++)
	{
		for (int j=0;j<maxn;j++)
		{
			for (int msk=0;msk<(1<<m);msk++)
			{
				if (!dp[i][j][msk]) continue;
				for (int d=1;d<=m;d++)
				{
					if (!i && d>1) continue;
					nmsk=(msk<<(d-1))&((1<<m)-1);
					if (j+d<=maxn) add(dp[i+1][j+d][((nmsk<<1)&((1<<m)-1))|1],1ll*dp[i][j][msk]*(cnt[nmsk]+1)%mod);
				}
			}
		}
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=maxn;j++)
		{
			for (int msk=0;msk<(1<<m);msk++)
			{
				add(shold[i][j],dp[i][j][msk]);
			}
		}
	}
	ddp[0][0][0]=1;
	for (int i=0;i<k;i++)
	{
		for (int j=0;j<k;j++)
		{
			for (int h=0;h<maxn;h++)
			{
				if (!ddp[i][j][h]) continue;
				for (int a=1;a<=k;a++)
				{
					for (int b=1;b<=maxn;b++)
					{
						if (j+a>k || h+b>maxn || !shold[a][b]) continue; 
						if (!i) 
						{
							add(ddp[i+1][j+a][h+b],1ll*ddp[i][j][h]*shold[a][b]%mod);
						}
						else
						{
							if (h+b+m<=maxn) add(ddp[i+1][j+a][h+b+m],1ll*ddp[i][j][h]*shold[a][b]%mod);
						}
					}
				}
			}
		}
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=0;j<=maxn;j++)
		{
			add(ans,1ll*ddp[i][k][j]*C(n-j+i,i)%mod);
		}
	}
	printf("%d\n",ans);
	return 0;
}