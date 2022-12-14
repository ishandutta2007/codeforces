#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,k,w[222222],jc[222222],injc[222222],ans,sum,x;
int binpow(int a,int t)
{
	if (t<0) return 0;
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
void Init()
{
	jc[0]=1;
	for (int i=1;i<=n;i++) jc[i]=1ll*jc[i-1]*i%mod;
	injc[n]=binpow(jc[n],mod-2);
	for (int i=n-1;i>=0;i--) injc[i]=1ll*injc[i+1]*(i+1)%mod;
}
int main()
{
	scanf("%d%d",&n,&k);
	Init();
	for (int j=0;j<k;j++)
	{
		if (j&1) ans=(-1ll*injc[j]*injc[k-1-j]%mod*((1ll*binpow(k-j,n-2)*(n-1)+binpow(k-j,n-1))%mod)+ans)%mod;
		else ans=(1ll*injc[j]*injc[k-1-j]%mod*((1ll*binpow(k-j,n-2)*(n-1)+binpow(k-j,n-1))%mod)+ans)%mod;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		sum=(sum+x)%mod;
	}
	ans=1ll*ans*sum%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}