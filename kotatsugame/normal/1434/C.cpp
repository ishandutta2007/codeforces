#include<cstdio>
using namespace std;
int T;
long long A,B,C,D;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
		if(C*B<A)puts("-1");
		else
		{
			long long R1=(C-1)/D,R2=(A-1)/D/B;
			long long R=R1<R2?R1:R2;
			printf("%lld\n",(R+1)*A-R*(R+1)/2*D*B);
		}
	}
}