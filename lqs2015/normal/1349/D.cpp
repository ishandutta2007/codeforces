#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int f[333333],n,a[111111],sum,ans,A[333333],B[333333],C[333333],isum,suf[333333];
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
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	isum=binpow(sum,mod-2);
	for (int i=0;i<sum;i++)
	{
		C[i]=1ll*i*isum%mod;
		A[i]=1ll*binpow(n-1,mod-2)*(sum-i)%mod*isum%mod;
		B[i]=(1-A[i]-C[i])%mod;
	}
	f[0]=binpow(A[0],mod-2);
	for (int i=1;i<sum;i++)
	{
		f[i]=(1ll*C[i]*f[i-1]+1)%mod*binpow(A[i],mod-2)%mod;
	}
	for (int i=sum;i>=0;i--)
	{
		suf[i]=(suf[i+1]+f[i])%mod;
	}
	for (int i=1;i<=n;i++)
	{
		ans=(ans+suf[a[i]])%mod;
	}
	ans=(-1ll*(n-1)*suf[0]+ans)%mod;
	ans=1ll*ans*binpow(n,mod-2)%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}