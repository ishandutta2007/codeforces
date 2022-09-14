#include<cstdio>
using namespace std;
int T,N,K;
int P[101];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)scanf("%d",&P[i]);
		long long now=P[0];
		long long add=0;
		for(int i=1;i<N;i++)
		{
			long long T=(100LL*P[i]+K-1)/K;
			if(T>now)add+=T-now,now=T;
			now+=P[i];
		}
		printf("%lld\n",add);
	}
}