#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		long long A=(1LL<<N)+(1LL<<N/2)-2;
		long long B=(1LL<<N+1)-2;
		printf("%lld\n",abs(B-A-A));
	}
}