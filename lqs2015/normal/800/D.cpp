#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6,mod=1e9+7;
int g[1222222],n,num[1222222],x,pw[1222222],X[11],k,cnt,ccnt[1222222],csum[1222222],cssum[1222222],pw10[11],msk;
int f[1222222];
long long ans,ff[1222222];
void add(int &x,int y)
{
	x+=y;
	if (x<0) x+=mod;
	if (x>=mod) x-=mod;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		num[x]++;
	}
	pw[0]=1;
	for (int i=1;i<=maxn;i++) pw[i]=pw[i-1]*2%mod; 
	pw10[0]=1;
	for (int i=1;i<=10;i++) pw10[i]=pw10[i-1]*10;
	for (int i=maxn-1;i>=0;i--)
	{
		int k=i;
		for (int j=0;j<6;j++)
		{
			X[j]=k%10;
			k/=10;
		}
		for (int j=1;j<64;j++)
		{
			cnt=0;msk=i;
			bool p=0;
			for (int k=0;k<6;k++)
			{
				if (j&(1<<k)) 
				{
					if (X[k]==9) 
					{
						p=1;
						break;
					}
					msk+=pw10[k];
					cnt++;
				}
			}
			if (p) continue;
			if (cnt&1)
			{
				ccnt[i]+=ccnt[msk];
				add(csum[i],csum[msk]);
				add(cssum[i],cssum[msk]);
			}
			else
			{
				ccnt[i]-=ccnt[msk];
				add(csum[i],-csum[msk]);
				add(cssum[i],-cssum[msk]);
			}
		}
		ccnt[i]+=num[i];
		csum[i]=(1ll*i*num[i]+csum[i])%mod;
		cssum[i]=(1ll*num[i]*(1ll*i*i%mod)+cssum[i])%mod;
	}
	for (int i=maxn-1;i>=0;i--)
	{
		if (!ccnt[i]) continue;
		if (ccnt[i]==1)
		{
			g[i]=cssum[i];
		}
		else
		{
			g[i]=(1ll*pw[ccnt[i]-2]*(1ll*csum[i]*csum[i]%mod)+g[i])%mod;
			g[i]=(1ll*pw[ccnt[i]-2]*cssum[i]+g[i])%mod;
		}
	}
	for (int i=maxn-1;i>=0;i--)
	{
		int k=i;
		for (int j=0;j<6;j++)
		{
			X[j]=k%10;
			k/=10;
		}
		f[i]=g[i];
		for (int j=1;j<64;j++)
		{
			cnt=0;msk=i;
			bool p=0;
			for (int k=0;k<6;k++)
			{
				if (j&(1<<k)) 
				{
					if (X[k]==9) 
					{
						p=1;
						break;
					}
					msk+=pw10[k];
					cnt++;
				}
			}
			if (p) continue;
			if (cnt&1) 
			{
				add(f[i],-g[msk]);
			}
			else
			{
				add(f[i],g[msk]);
			}
		}
	}
	for (int i=0;i<maxn;i++) f[i]=(f[i]+mod)%mod;
	for (int i=0;i<maxn;i++) ff[i]=1ll*f[i]*i;
	for (int i=0;i<maxn;i++) ans^=ff[i];
	printf("%lld\n",ans);
	return 0;
}