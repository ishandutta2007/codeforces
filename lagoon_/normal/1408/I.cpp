#include<bits/stdc++.h>
#define re register
const unsigned int mod=998244353;
int ff[17][(1<<16)+1],fc[(1<<16)+1],pp[100100],k,fac[110],ifac[110];
inline bool cmp(re int a,re int b)
{
	return ((a-k)^a)<((b-k)^b);
}
int ex(re int a,re int b)
{
	re int ans=1;
	for(;b;b>>=1,a=1llu*a*a%mod)if(b&1)ans=1llu*ans*a%mod;
	return ans;
}
int main()
{
	re int n,c,nw=0,cc=1;
	scanf("%d%d%d",&n,&k,&c);
	for(re int i=1;i<=n;i++)scanf("%d",&pp[i]);
	std::sort(pp+1,pp+n+1,cmp);
	ff[0][0]=1;fac[0]=ifac[0]=1;
	for(re int i=1;i<=k;i++)fac[i]=1llu*fac[i-1]*i%mod;ifac[k]=ex(fac[k],mod-2);
	for(re int i=k;i;i--)ifac[i-1]=1llu*ifac[i]*i%mod;
	for(re int i=1;i<=n;i++)
	{
		for(;cc<=((pp[i]-k)^pp[i]);cc*=2);
		re int nc=nw^(nw&(cc-1));
		for(re int i1=k;i1>=0;i1--)
		{
			for(re int j=0;j<cc;j++)
			{
				re int jj=nc+j;
				fc[jj]=ff[i1][jj];
				ff[i1][jj]=0;
			}
			for(re int j=0;j<cc;j++)if(fc[nc+j])
			{
				re int jj=nc+j;
				for(re int j1=0;i1+j1<=k;j1++)
				{
					ff[i1+j1][jj^(pp[i]-j1)]=(ff[i1+j1][jj^(pp[i]-j1)]+1llu*fc[jj]*ifac[j1])%mod;
				}
			}
		}
		nw^=pp[i];
	}
	re int iv=ex(n,mod-1-k);
	for(re int i=0;i<(1<<c);i++)printf("%llu ",1llu*ff[k][i]*fac[k]%mod*iv%mod);
}