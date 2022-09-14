#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		long long ans=0;
		for(int i=0;i<N;)
		{
			int j=i;
			if(A[i]>0)
			{
				int M=A[i];
				while(j<N&&A[j]>0)
				{
					if(M<A[j])M=A[j];
					j++;
				}
				ans+=M;
			}
			else
			{
				int M=A[i];
				while(j<N&&A[j]<0)
				{
					if(M<A[j])M=A[j];
					j++;
				}
				ans+=M;
			}
			i=j;
		}
		printf("%lld\n",ans);
	}
}