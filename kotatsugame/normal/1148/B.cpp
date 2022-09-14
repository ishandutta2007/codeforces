#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int N,M,K;
long long TA,TB,A[2<<17],B[2<<17];
main()
{
	scanf("%d%d%lld%lld%d",&N,&M,&TA,&TB,&K);
	for(int i=0;i<N;i++)scanf("%lld",A+i);
	for(int i=0;i<M;i++)scanf("%lld",B+i);
	long long ans=0;
	int id=0;
	for(int i=0;i<=N;i++)
	{
		if(i>K)break;
		if(i==N)
		{
			puts("-1");
			return 0;
		}
		while(id<M&&B[id]<A[i]+TA)id++;
		if(id+K-i>=M)
		{
			puts("-1");
			return 0;
		}
		ans=max(ans,B[id+K-i]+TB);
	}
	printf("%lld\n",ans);
}