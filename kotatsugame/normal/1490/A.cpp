#include<cstdio>
using namespace std;
int T,N;
int A[50];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		int prv=A[0];
		int ans=0;
		for(int i=1;i<N;i++)
		{
			if(prv<=A[i])
			{
				while(prv*2<A[i])prv*=2,ans++;
				prv=A[i];
			}
			else
			{
				while(A[i]<(prv+1)/2)prv=(prv+1)/2,ans++;
				prv=A[i];
			}
		}
		printf("%d\n",ans);
	}
}