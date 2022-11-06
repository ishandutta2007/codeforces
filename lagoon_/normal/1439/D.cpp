#include<bits/stdc++.h>
#define re register
int mod,f[510],g[510],inv[510],ff[510][510],gg[510][510];
int main()
{
	re int n,m;
	scanf("%d%d%d",&n,&m,&mod);
	f[0]=1;inv[1]=1;
	for(re int i=2;i<=m;i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(re int i=1;i<=m;i++)
	{
		for(re int j=0;j<i;j++)
		{
			f[i]=(f[i]+1ll*f[j]*f[i-j-1]%mod*(i+1))%mod;
			g[i]=(g[i]+1ll*g[j]*f[i-j-1]%mod*(i+1)+1ll*g[i-j-1]*f[j]%mod*(i+1)+1ll*f[j]*f[i-j-1]%mod*(j*(j+1)/2)+1ll*f[j]*f[i-j-1]%mod*((i-j-1)*(i-j)/2))%mod;
		}
			f[i]=1ll*f[i]*inv[i]%mod;
			g[i]=1ll*g[i]*inv[i]%mod;
	}
	ff[0][0]=1;
	for(re int i=0;i<n;i++)
	{
		for(re int j=0;j<=m;j++)
		{
			ff[i+1][j]=(ff[i+1][j]+ff[i][j])%mod;
			gg[i+1][j]=(gg[i+1][j]+gg[i][j])%mod;
			for(re int j1=1;i+j1<=n&&j+j1<=m;j1++)
			{
				if(i+j1==n)
				{
					ff[i+j1][j+j1]=(ff[i+j1][j+j1]+1ll*ff[i][j]*f[j1])%mod;
					gg[i+j1][j+j1]=(gg[i+j1][j+j1]+1ll*gg[i][j]*f[j1]+1ll*ff[i][j]*g[j1])%mod;
				}
				else
				{
					ff[i+j1+1][j+j1]=(ff[i+j1+1][j+j1]+1ll*ff[i][j]*f[j1])%mod;
					gg[i+j1+1][j+j1]=(gg[i+j1+1][j+j1]+1ll*gg[i][j]*f[j1]+1ll*ff[i][j]*g[j1])%mod;
				}
			}
		}
	}
	for(re int i=1;i<=m;i++)gg[n][m]=1ll*gg[n][m]*i%mod;
	printf("%d\n",gg[n][m]);
}