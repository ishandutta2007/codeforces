#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int C[1<<17],A[1<<17],B[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&C[i]);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<N;i++)scanf("%d",&B[i]);
		long long ans=0,now=0;
		for(int i=0;i<N;i++)
		{
			if(A[i]==B[i])
			{
				if(i>0)now=C[i]+1;
				else
				{
					now=abs(A[1]-B[1])*2;
				}
			}
			else
			{
				now+=C[i]-abs(A[i]-B[i])+1;
				now=max(now,(long long)C[i]+1LL+(long long)abs(A[i]-B[i]));
			}
			if(i>0)ans=max(ans,now);
		}
		printf("%lld\n",ans);
	}
}