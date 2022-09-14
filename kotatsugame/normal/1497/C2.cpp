#include<cstdio>
using namespace std;
int T,N,K;
int A[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<K-3;i++)printf("1 "),N--;
		if(N%2==1)printf("%d %d %d\n",N/2,N/2,1);
		else if(N%4==0)printf("%d %d %d\n",N/2,N/4,N/4);
		else printf("%d %d %d\n",N/2-1,N/2-1,2);
	}
}