#include<cstdio>
#include<set>
using namespace std;
int T,N;
int S[5050];
long long A[5050],cumsum[5050];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&S[i]);
			A[i]=0;
			cumsum[i]=0;
		}
		cumsum[N]=0;
		long long ans=0;
		for(int i=0;i<N;i++)
		{
			A[i]+=cumsum[i+1]+=cumsum[i];
			int now=S[i]-1;
			if(A[i]<now)
			{
				ans+=now-A[i];
				A[i]=now;
			}
			A[i]-=now;
			cumsum[i+2]+=A[i];
			cumsum[i+3]-=A[i];
			cumsum[i+3]+=1;
			if(i+2+S[i]<=N)cumsum[i+2+S[i]]-=1;
		}
		printf("%lld\n",ans);
	}
}