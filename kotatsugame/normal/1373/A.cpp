#include<cstdio>
using namespace std;
int T;
long long A,B,C;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld%lld",&A,&B,&C);
		if(A>=C)
		{
			printf("-1 %lld\n",B);
		}
		else
		{
			printf("1 %lld\n",A*B>C?B:-1LL);
		}
	}
}