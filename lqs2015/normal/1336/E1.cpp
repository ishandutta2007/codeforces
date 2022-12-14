#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long arr[55],x,base[55];
int cnt,res[55],n,m,l,mul,b[55][55],c[55][55],ans[55];
bool can[55];
void dfs(int i,long long x)
{
	if (i==cnt+1) 
	{
		res[__builtin_popcountll(x)]++;
		return;
	}
	dfs(i+1,x);
	dfs(i+1,x^arr[i]);
}
void add(long long x)
{
	for (int i=m-1;i>=0;i--)
	{
		if (x&(1ll<<i))
		{
			if (base[i]) x^=base[i];
			else 
			{
				base[i]=x;
				break;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		add(x);
	}
	for (int i=0;i<m;i++)
	{
		for (int j=i-1;j>=0;j--)
		{
			if ((base[i]^base[j])<base[i]) base[i]^=base[j];
		}
	}
	for (int i=0;i<m;i++)
	{
		if (base[i]) l++;
	}
	if (l<=26)
	{
		for (int i=0;i<m;i++)
		{
			if (base[i]) arr[++cnt]=base[i];
		}
		dfs(1,0);mul=1;
		for (int i=1;i<=n-l;i++) mul=(mul+mul)%mod;
		for (int i=0;i<=m;i++)
		{
			printf("%d ",1ll*mul*res[i]%mod);
		}
		printf("\n");
	}
	else
	{
		for (int i=0;i<m;i++)
		{
			if (base[i]) can[i]=1;
		}
		for (int i=0;i<m;i++)
		{
			if (can[i])
			{
				for (int j=0;j<m;j++)
				{
					if (!can[j])
					{
						if (base[i]&(1ll<<j)) base[j]|=(1ll<<i);
					}
				}
			}
		}
		for (int i=0;i<m;i++)
		{
			if (!can[i]) arr[++cnt]=(base[i]|(1ll<<i));
		}
		c[0][0]=1;
		for (int i=1;i<=m;i++)
		{
			c[i][0]=1;
			for (int j=1;j<=i;j++)
			{
				c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
			}
		}
		for (int i=0;i<=m;i++)
		{
			for (int j=0;j<=m;j++)
			{
				for (int k=0;k<=j;k++)
				{
					if (k&1) b[i][j]=(-1ll*c[j][k]*c[m-j][i-k]+b[i][j])%mod;
					else b[i][j]=(1ll*c[j][k]*c[m-j][i-k]+b[i][j])%mod;
				}
			}
		}
		dfs(1,0);
		for (int i=0;i<=m;i++)
		{
			for (int j=0;j<=m;j++)
			{
				ans[i]=(1ll*b[i][j]*res[j]+ans[i])%mod;
			}
		}
		mul=1;
		for (int i=1;i<=n;i++) mul=(mul+mul)%mod;
		for (int i=1;i<=m;i++) mul=1ll*mul*(mod+1)/2%mod;
		for (int i=0;i<=m;i++)
		{
			printf("%d ",(1ll*mul*ans[i]%mod+mod)%mod);
		}
		printf("\n");
	}
	return 0;
}