#include <bits/stdc++.h>
using namespace std;
#define MX 10000000
#define mod 1000000007
int tot[MX+5],lp[MX+5],u[MX+5],cop[MX+5],sub[MX+5],pw[MX+5];
int main()
{
	u[1]=1;
	pw[0]=1;
	pw[1]=2;
	for (int i=2;i<=MX;i++)
	{
	    pw[i]=(2*pw[i-1])%mod;
		if (!lp[i])
		{
			for (int j=i;j<=MX;j+=i)
			{
				if (!lp[j])
				lp[j]=i;
			}
		}
		if ((i/lp[i])%lp[i])
		u[i]=-u[i/lp[i]];
		else
		u[i]=0;
	}
	int n,ans=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		tot[a]++;
	}
	for (int i=MX;i;i--)
	{
		for (int j=2*i;j<=MX;j+=i)
		tot[i]-=tot[j]*u[j/i];
	}
	for (int i=1;i<=MX;i++)
	{
	    if (u[i])
	    {
	        for (int j=i;j<=MX;j+=i)
	        cop[j]+=u[i]*tot[i];
	    }
	}
	for (int i=MX;i>1;i--)
	{
		sub[i]=pw[tot[i]]-1;
		for (int j=2*i;j<=MX;j+=i)
		sub[i]=(sub[i]-sub[j]+mod)%mod;
		ans=(ans+1LL*cop[i]*sub[i])%mod;
	}
	printf("%d",ans);
}