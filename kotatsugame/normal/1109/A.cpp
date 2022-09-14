#include<cstdio>
using namespace std;
int N;
int A[3<<17];
int cnt[2][1<<20];
main()
{
	scanf("%d",&N);
	int now=0;
	cnt[0][now]++;
	long long ans=0;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
		now^=A[i];
		ans+=cnt[i%2][now]++;
	}
	printf("%lld\n",ans);
}