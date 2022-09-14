#include<cstdio>
using namespace std;
const long long mod=998244353;
long long power(long long a,long long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
main()
{
	long long N,M,L,R;
	scanf("%lld%lld%lld%lld",&N,&M,&L,&R);
	long long ans;
	if(N*M%2==1)ans=power(R-L+1,N*M);
	else if((R-L+1)%2==0)ans=power(R-L+1,N*M)*power(2,mod-2)%mod;
	else
	{
		ans=(power(R-L+1,N*M)+1)%mod;
		ans=ans*power(2,mod-2)%mod;
	}
	printf("%lld\n",ans);
}