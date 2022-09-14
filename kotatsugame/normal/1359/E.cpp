#include<iostream>
using namespace std;
const long long mod=998244353;
long long N,K;
long long fac[5<<17],inv[5<<17];
long long power(long long a,long long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
main()
{
	cin>>N>>K;
	fac[0]=1;
	for(int i=1;i<=N;i++)fac[i]=fac[i-1]*i%mod;
	inv[N]=power(fac[N],mod-2);
	for(int i=N;i--;)inv[i]=inv[i+1]*(i+1)%mod;
	long long ans=0;
	for(int i=1;i<=N;i++)
	{
		int c=N/i;
		if(c>=K)
		{
			(ans+=fac[c-1]*inv[K-1]%mod*inv[c-K])%=mod;
		}
	}
	cout<<ans<<endl;
}