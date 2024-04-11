#include<cstdio>
using namespace std;
int T;
long long N,M;
int lp[10]={1,10,5,10,5,2,5,10,5,10};
int sm[10]={0,45,20,45,20,5,20,45,20,45};
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld",&N,&M);
		long long T=N/M;
		long long ans=T/lp[M%10]*sm[M%10];
		T%=lp[M%10];
		int now=0;
		while(T--)
		{
			now+=M%10;
			ans+=now%10;
		}
		printf("%lld\n",ans);
	}
}