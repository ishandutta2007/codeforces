#include<bits/stdc++.h>
#define re register
char ss[1001000];
int nm[1001000][2],ta,f[1001000],g[1001000],s[1001000],q[1001000];
const int mod=1e9+7;
int main()
{
	re int n;
	re char la='1';ta=1;nm[1][0]=1<<30;
	scanf("%s",ss+1);
	n=strlen(ss+1);
	for(re int i=1;i<=n;i++)
	{
		if(la>ss[i])ta++;la=ss[i];
		nm[ta][la-'0']++;
	}
	n=ta;
	q[ta=1]=1;
	s[1]=g[1]=nm[1][1];
	if(!nm[1][1])g[1]++;
	re int nn=1;
	for(re int i=2;i<=n;i++)
	{
		f[i]=1ll*nm[i][0]*g[i-1]%mod;
		while(nm[i][0]>nm[q[ta]][0])
		{
			f[i]=(f[i]+1ll*(nm[i][0]-nm[q[ta]][0])*(s[q[ta]-1]-s[q[ta-1]-1]+mod))%mod;ta--;
		}
		q[++ta]=i;
		nn=(nn+f[i])%mod;
		g[i]=1ll*nn*nm[i][1]%mod;
		s[i]=(s[i-1]+g[i])%mod;
	}
	re int ans=0;
	for(re int i=1+(!nm[1][1]);i<=n;i++)ans=(ans+g[i])%mod;
	if(nm[n][1]==0)
	{
		for(re int i=1+((!nm[1][1])&&nm[n][0]!=strlen(ss+1));i<n;i++)ans=(ans+1ll*g[i]*nm[n][0])%mod;
	}
	printf("%d\n",ans);
}