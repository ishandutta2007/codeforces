#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int X,M,A;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&X);
		M=0;
		bool flag=false;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A);
			if(X==A)flag=true;
			M=max(M,A);
		}
		if(flag)printf("1\n");
		else if(X<M)printf("2\n");
		else printf("%d\n",(X+M-1)/M);
	}
}