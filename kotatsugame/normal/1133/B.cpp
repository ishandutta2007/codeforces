#include<cstdio>
#include<algorithm>
using namespace std;
int N,K;
int cnt[100];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		int a;scanf("%d",&a);
		cnt[a%K]++;
	}
	int ans=cnt[0]/2;
	for(int i=1;i<(K+1)/2;i++)ans+=min(cnt[i],cnt[K-i]);
	if(K%2==0)ans+=cnt[K/2]/2;
	printf("%d\n",ans*2);
}