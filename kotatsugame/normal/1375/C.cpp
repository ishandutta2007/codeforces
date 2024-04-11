#include<cstdio>
using namespace std;
int T,N;
int A[3<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		puts(A[0]<A[N-1]?"YES":"NO");
	}
}