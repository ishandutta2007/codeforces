#include<cstdio>
using namespace std;
int T,N;
long long K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%lld",&N,&K);
		int i,j;
		for(i=N-1;;i--)
		{
			if(K>N-i)K-=N-i;
			else
			{
				j=N+1-K;
				break;
			}
		}
		for(int k=1;k<=N;k++)
		{
			printf("%c",i==k||j==k?'b':'a');
		}
		printf("\n");
	}
}