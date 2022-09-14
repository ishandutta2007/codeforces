#include<cstdio>
using namespace std;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int T;
long long N;
const long long mod=1e9+7;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld",&N);
		long long ans=N%mod;
		long long P=N,L=1;
		int i=2;
		while(P)
		{
			L=L/gcd(L,i)*i;
			ans=(ans+P)%mod;
			P=N/L;
			i++;
		}
		printf("%lld\n",ans);
	}
}