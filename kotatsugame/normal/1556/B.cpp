#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
int A[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<int>ev;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			A[i]%=2;
			if(A[i]==0)ev.push_back(i);
		}
		long long ans=1e18;
		for(int i=0;i<2;i++)
		{
			int cnt=(N+1-i)/2;
			if(cnt!=ev.size())continue;
			long long now=0;
			for(int j=0;j<cnt;j++)
			{
				now+=abs(ev[j]-(i+j*2));
			}
			if(ans>now)ans=now;
		}
		if(ans==(long long)1e18)ans=-1;
		printf("%lld\n",ans);
	}
}