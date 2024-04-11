#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[2<<17];
long long S[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		long long sum=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			S[i+1]=S[i];
			if(i%2==0)S[i+1]-=A[i];
			else S[i+1]+=A[i];
			if(i%2==0)sum+=A[i];
		}
		long long ans=sum;
		long long INF=1e18;
		long long K[2]={INF,INF};
		for(int i=0;i<N;i++)
		{
			ans=max(ans,sum+S[i+1]-K[1-i%2]);
			K[i%2]=min(K[i%2],S[i]);
		}
		printf("%lld\n",ans);
	}
}