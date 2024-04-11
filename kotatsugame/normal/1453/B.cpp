#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[2<<17];
long long B[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		long long ans;
		{
			long long T=0,X=A[1];
			ans=0;
			for(int i=2;i<N;i++)
			{
				long long d=X-(A[i]+T);
				ans+=abs(d);
				T+=d;
			}
		}
		{
			long long T=0,X=A[0];
			for(int i=1;i<N;i++)
			{
				long long d=X-(A[i]+T);
				B[i]=abs(d);
				T+=d;
			}
			B[N]=0;
			for(int i=N;--i;)B[i]+=B[i+1];
		}
		ans=min(ans,B[1]);
		for(int i=1;i+1<N;i++)
		{
			long long T=A[0]-A[i-1];
			long long d=A[0]-(A[i+1]+T);
			ans=min(ans,B[1]-B[i]+B[i+2]+abs(d));
		}
		ans=min(ans,B[1]-B[N-1]);
		printf("%lld\n",ans);
	}
}