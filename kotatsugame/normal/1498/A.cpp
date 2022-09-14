#include<cstdio>
using namespace std;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
main()
{
	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		long long N;
		scanf("%lld",&N);
		while(true)
		{
			long long A=N,B=0,T=N;
			while(T)B+=T%10,T/=10;
			A=gcd(A,B);
			if(A>1)break;
			N++;
		}
		printf("%lld\n",N);
	}
}