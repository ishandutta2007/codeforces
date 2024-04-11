#include<cstdio>
using namespace std;
int T,N,M,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&M,&K);
		int x=N/K;
		int a1=x<M?x:M;
		M-=a1;
		K--;
		int a2=(M+K-1)/K;
		printf("%d\n",a1-a2);
	}
}