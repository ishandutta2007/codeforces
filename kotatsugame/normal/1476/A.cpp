#include<cstdio>
using namespace std;
int T,N,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		int X=(N+K-1)/K*K;
		printf("%d\n",(X-1)/N+1);
	}
}