#include <iostream>
#include <vector>
using namespace std;
#define MX 100000
#define mod 1000000007
int u[MX+5];
vector<int> d[MX+5];
long long fact[MX+5],inv[MX+5];
long long pow_log(long long x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
	return ret;
}
int ncr(int n,int r)
{
	if (r>n)
	return 0;
	return (((fact[n]*inv[r])%mod)*inv[n-r])%mod;
}
int main()
{
	fact[0]=1;
	for (int i=1;i<=MX;i++)
	fact[i]=(fact[i-1]*i)%mod;
	inv[MX]=pow_log(fact[MX],mod-2);
	for (int i=MX-1;i>=0;i--)
	inv[i]=(inv[i+1]*(i+1))%mod;
	for (int i=1;i<=MX;i++)
	{
		for (int j=i;j<=MX;j+=i)
		d[j].push_back(i);
		if (i==1)
		u[i]=1;
		else if ((i/d[i][1])%d[i][1]==0)
		u[i]=0;
		else
		u[i]=-u[i/d[i][1]];
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int n,f;
		scanf("%d%d",&n,&f);
		long long ans=0;
		for (int i:d[n])
		ans=(ans+ncr(n/i-1,f-1)*u[i]+mod)%mod;
		printf("%I64d\n",ans);
	}
}