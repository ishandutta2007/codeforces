#include<cstdio>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int N,A,X=-1;
		scanf("%d",&N);
		for(;N--;)
		{
			scanf("%d",&A);
			if(X==-1)X=A;
			X&=A;
		}
		printf("%d\n",X);
	}
}