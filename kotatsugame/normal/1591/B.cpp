#include<cstdio>
using namespace std;
int T,N,A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		int cnt=0,mx=A[N-1];
		for(int i=N;i--;)
		{
			if(mx<A[i])
			{
				mx=A[i];
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
}