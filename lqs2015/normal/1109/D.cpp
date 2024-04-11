#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e6,mod=1e9+7;
long long n,m,a,b,jc[2222222],injc[2222222],cur,ans;
long long binpow(long long a,long long t)
{
	if (t<0) return binpow(a,(-t)*(mod-2));
	long long res=1,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return res;
}
void Init()
{
	jc[0]=1;
	for (long long i=1;i<=maxn;i++)
	{
		jc[i]=jc[i-1]*i%mod;
	}
	injc[maxn]=binpow(jc[maxn],mod-2);
	for (long long i=maxn-1;i>=0;i--) injc[i]=injc[i+1]*(i+1)%mod;
}
long long C(long long n,long long k)
{
	if (n<k) return 0;
	return (jc[n]*injc[k]%mod)*injc[n-k]%mod;
}
int main()
{
	cin>>n>>m>>a>>b;
	Init();
	for (long long i=1;i<n && i<=m;i++)
	{
		cur=C(m-1,i-1)*binpow(m,n-i-1)%mod;
		cur=cur*binpow(n,n-i-2)%mod;cur=cur*(i+1)%mod;
		cur=cur*C(n-2,i-1)%mod*jc[i-1]%mod;
		ans=(ans+cur)%mod;
	}
	cout<<ans<<endl;
	return 0;
}