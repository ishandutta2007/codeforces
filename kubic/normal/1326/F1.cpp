#include <bits/stdc++.h>
using namespace std;
#define N 25
#define M 1<<18
#define ll long long
#define pct __builtin_popcount
int n,tp,st[N];ll z2[M],dp[M][N],z[N][M],z1[N][M];char a[N][N];
void FWT_or(bool fl,int n,ll a[])
{
	for(int i=1;i<1<<n;i*=2) for(int j=0;j<1<<n;j+=i*2)
		for(int k=0;k<i;++k) a[i+j+k]+=fl?-a[j+k]:a[j+k];
}
void upd(bool fl,int x)
{
	if(fl) --st[0],--tp;
	else
	{
		st[++st[0]]=x;++tp;
		for(int i=0;i<1<<n;++i) z1[tp][i]=z1[tp-1][i]*z[x][i];
	}
}
void dfs(int u,int rm)
{
	if(!rm)
	{
		int t=0;ll w=0;
		for(int i=0;i<1<<n;++i) w+=n-pct(i)&1?-z1[tp][i]:z1[tp][i];
		while(1)
		{
			for(int i=1;i<=st[0];++i)
			{for(int j=1;j<st[i];++j) t*=2;if(i<st[0]) t=t*2+1;}
			z2[t]=w;t=0;if(!next_permutation(st+1,st+st[0]+1)) break;
		}return;
	}for(int i=u;i<=rm;++i) upd(0,i),dfs(i,rm-i),upd(1,i);
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for(int i=1;i<1<<n;++i) for(int j=1;j<=n;++j) if(i>>j-1&1)
	{
		if(i==(1<<j-1)) dp[i][j]=1;
		for(int k=1;k<=n;++k) if(j!=k && i>>k-1&1 && a[j][k]=='0')
			dp[i][j]+=dp[i^(1<<j-1)][k];z[pct(i)][i]+=dp[i][j];
	}for(int i=0;i<1<<n;++i) z1[0][i]=1;
	for(int i=1;i<=n;++i) FWT_or(0,n,z[i]);dfs(1,n);FWT_or(1,n-1,z2);
	for(int i=0;i<1<<n-1;++i) printf("%lld ",z2[i]);return 0;
}