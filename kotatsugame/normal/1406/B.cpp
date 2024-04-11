#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
long long A[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		bool zero=false;
		for(int i=0;i<N;i++)
		{
			scanf("%lld\n",&A[i]);
			if(A[i]==0)zero=true;
		}
		sort(A,A+N);
		long long ans=-9e18;
		if(zero)ans=0;
		for(int i=0;i<=5;i++)
		{
			long long now=1;
			for(int j=0;j<i;j++)now*=A[j];
			for(int j=i;j<5;j++)now*=A[N-(j-i)-1];
			if(ans<now)ans=now;
		}
		printf("%lld\n",ans);
	}
}