#include<cstdio>
#include<algorithm>
using namespace std;
int N,T,K;
int A[2<<17];
int sum[4<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		int LIM=2*K+15;
		for(int i=0;i<LIM;i++)sum[i]=0;
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<N/2;i++)
		{
			int a=A[i],b=A[N-i-1];
			sum[min(a,b)+1]++;
			sum[max(a,b)+K+1]--;
		}
		for(int i=1;i<LIM;i++)sum[i]+=sum[i-1];
		for(int i=0;i<N/2;i++)
		{
			sum[A[i]+A[N-i-1]]++;
		}
		int ans=0;
		for(int i=0;i<LIM;i++)ans=max(ans,sum[i]);
		printf("%d\n",N-ans);
	}
}