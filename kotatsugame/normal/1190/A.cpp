#include<cstdio>
using namespace std;
long long N,K;
int M;
long long P[1<<17];
main()
{
	scanf("%lld%d%lld",&N,&M,&K);
	for(int i=0;i<M;i++)
	{
		scanf("%lld",&P[i]);
		P[i]--;
	}
	int ans=0;
	for(int i=0;i<M;)
	{
		long long idx=(P[i]-i)/K;
		int j=i;
		while(j<M&&P[j]-i<idx*K+K)j++;
		ans++;
		i=j;
	}
	printf("%d\n",ans);
}