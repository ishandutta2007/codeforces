#include<cstdio>
using namespace std;
int T,N,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		long long L=0,R=3e9;
		while(R-L>1)
		{
			long long mid=(L+R)/2;
			long long cnt=mid%N+mid/N*(N-1);
			if(cnt>=K)R=mid;
			else L=mid;
		}
		printf("%lld\n",R);
	}
}