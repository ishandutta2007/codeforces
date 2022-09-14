#include<cstdio>
using namespace std;
int T;
long long S,N,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld%lld",&S,&N,&K);
		if(S==K)
		{
			puts("YES");
			continue;
		}
		long long T=S/(2*K);
		long long cnt=T*K;
		long long rS=S%(2*K);
		if(rS<K)
		{
			cnt+=rS+1;
			puts(cnt>=N+1?"NO":"YES");
		}
		else
		{
			cnt+=K;
			puts(cnt>=N+1?"NO":"YES");
		}
	}
}