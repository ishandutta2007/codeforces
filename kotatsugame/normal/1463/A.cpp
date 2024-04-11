#include<cstdio>
using namespace std;
int T;
long long A,B,C,S;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld%lld",&A,&B,&C);
		S=A+B+C;
		long long L=0,R=1e9;
		while(R-L>1)
		{
			long long mid=(L+R)/2;
			if(mid*7+mid*2<S)L=mid;
			else R=mid;
		}
		if(R*9!=S)puts("NO");
		else
		{
			puts(A<R||B<R||C<R?"NO":"YES");
		}
	}
}