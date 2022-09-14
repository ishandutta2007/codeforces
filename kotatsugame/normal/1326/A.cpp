#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		if(N==1)puts("-1");
		else
		{
			for(int i=0;i<N-1;i++)printf("3");
			puts("4");
		}
	}
}