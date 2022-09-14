#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T;
int N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		long long mx=0;
		long long sum=0;
		for(int i=0;i<N;i++)
		{
			int A;scanf("%d",&A);
			sum+=A;
			if(mx<A)mx=A;
		}
		long long T=(sum+N-1-1)/(N-1)*(N-1);
		long long U=mx*(N-1);
		if(T<U)T=U;
		printf("%lld\n",T-sum);
	}
}