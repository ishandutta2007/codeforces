#include<cstdio>
int T,N,M;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		printf("%d\n",N==1?0:N==2?M:2*M);
	}
}