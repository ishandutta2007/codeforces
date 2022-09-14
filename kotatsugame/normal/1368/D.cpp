#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int cnt[20];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int A;
		scanf("%d",&A);
		for(int j=0;j<20;j++)if(A>>j&1)cnt[j]++;
	}
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		long long T=0;
		for(int j=0;j<20;j++)if(cnt[j]>0)
		{
			cnt[j]--;
			T|=1<<j;
		}
		ans+=T*T;
	}
	printf("%lld\n",ans);
}