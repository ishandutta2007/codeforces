#include<cstdio>
using namespace std;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int T,N;
long long K,X,Y;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%lld",&N,&K);
		long long g=0;
		scanf("%lld",&X);
		for(int i=1;i<N;i++)
		{
			scanf("%lld",&Y);
			g=gcd(g,Y-X);
		}
		puts((K-X)%g==0?"YES":"NO");
	}
}