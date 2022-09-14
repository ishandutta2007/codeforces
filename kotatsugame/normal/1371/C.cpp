#include<cstdio>
using namespace std;
int T;
long long A,B,N,M;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld%lld%lld",&A,&B,&N,&M);
		long long L=A<B?A:B;
		puts(M<=L&&N+M<=A+B?"Yes":"No");
	}
}