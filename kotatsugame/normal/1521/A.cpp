#include<cstdio>
using namespace std;
int T;
long long A,B;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld",&A,&B);
		if(B==1)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			printf("%lld %lld %lld\n",A*B,A,A*(B+1));
		}
	}
}