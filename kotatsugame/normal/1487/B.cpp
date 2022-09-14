#include<cstdio>
using namespace std;
int T,N,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		K--;
		if(N%2==1)
		{
			int u=K/(N/2);
			K+=u;
		}
		K%=N;
		printf("%d\n",K+1);
	}
}