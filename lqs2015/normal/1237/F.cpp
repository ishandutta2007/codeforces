#include<bits/stdc++.h>
using namespace std;
const int maxn=4000,mod=998244353;
int h,w,n,dp[4444][2222],sum[4444][2222],jc[4444],injc[4444],hh[4444],vv[4444],ch,cv,r1,r2,c1,c2,pos,pre,allh,allv;
int dp1[4444][2222],dp2[4444][2222],ans;
bool ho[4444],ve[4444];
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
int C(int n,int m)
{
	if (n<m || n<0 || m<0) return 0;
	return (1ll*jc[n]*injc[m]%mod)*injc[n-m]%mod;
}
void Init()
{
	dp[0][0]=1;
	for (int i=1;i<=maxn;i++) dp[i][0]=1;
	for (int i=0;i<=maxn;i++) sum[i][0]=i+1;
	for (int i=1;i<=maxn/2;i++)
	{
		for (int j=2;j<=maxn;j++)
		{
			dp[j][i]=sum[j-2][i-1];
		}
		for (int j=1;j<=maxn;j++) sum[j][i]=(sum[j-1][i]+dp[j][i])%mod;
	}
	jc[0]=injc[0]=1;
	for (int i=1;i<=maxn;i++)
	{
		jc[i]=1ll*jc[i-1]*i%mod;
		injc[i]=1ll*injc[i-1]*binpow(i,mod-2)%mod;
	}
}
int main()
{
	Init();
	scanf("%d%d%d",&h,&w,&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		if (r1==r2) 
		{
			ho[r1]=1;ve[c1]=ve[c2]=1;
		}
		else
		{
			ho[r1]=ho[r2]=1;ve[c1]=1;
		}
	}
	pos=1;
	while(pos<=h)
	{
		pre=pos;
		while(pos<=h && !ho[pos]) pos++;
		if (pre==pos) pos++;
		else 
		{
			++ch;hh[ch]=pos-pre;
		}
	}
	pos=1;
	while(pos<=w)
	{
		pre=pos;
		while(pos<=w && !ve[pos]) pos++;
		if (pre==pos) pos++;
		else 
		{
			++cv;vv[cv]=pos-pre;
		}
	}
	for (int i=1;i<=ch;i++) allh+=hh[i];
	for (int i=1;i<=cv;i++) allv+=vv[i];
	dp1[0][0]=1;
	for (int i=1;i<=ch;i++)
	{
		for (int j=0;j<=allh/2;j++)
		{
			for (int k=0;k<=min(hh[i]/2,j);k++)
			{
				dp1[i][j]=(1ll*dp1[i-1][j-k]*dp[hh[i]][k]+dp1[i][j])%mod;
			}
		}
	}
	dp2[0][0]=1;
	for (int i=1;i<=cv;i++)
	{
		for (int j=0;j<=allv/2;j++)
		{
			for (int k=0;k<=min(vv[i]/2,j);k++)
			{
				dp2[i][j]=(1ll*dp2[i-1][j-k]*dp[vv[i]][k]+dp2[i][j])%mod;
			}
		}
	}
	for (int i=0;i<=h;i++)
	{
		for (int j=0;j<=w;j++)
		{
			if (i+2*j>allh || 2*i+j>allv) continue;
			ans=(1ll*dp1[ch][j]*C(allh-2*j,i)%mod*dp2[cv][i]%mod*C(allv-2*i,j)%mod*jc[i]%mod*jc[j]+ans)%mod;
		}
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}