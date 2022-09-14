#include<cstdio>
using namespace std;
int T;
long long N,R;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld",&N,&R);
		if(N-1<R)
		{
			printf("%lld\n",N*(N-1)/2+1);
		}
		else
		{
			printf("%lld\n",R*(R+1)/2);
		}
	}
}