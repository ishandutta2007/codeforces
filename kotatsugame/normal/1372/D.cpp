#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int A[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	long long ans=0,sum=0,now=0;
	for(int i=0;i<N;i++)
	{
		sum+=A[i];
		if(i%2==0)now+=A[i];
	}
	ans=now;
	for(int i=1;i<N;i++)
	{
		now=sum-now+A[i-1];
		if(ans<now)ans=now;
	}
	printf("%lld\n",ans);
}