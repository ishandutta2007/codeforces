#include<cstdio>
using namespace std;
int T;
long long f(int N)
{
	long long ret=0;
	while(N>0)
	{
		ret+=N;
		N/=10;
	}
	return ret;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int L,R;
		scanf("%d%d",&L,&R);
		printf("%lld\n",f(R)-f(L));
	}
}