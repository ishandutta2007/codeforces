#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,cnt[101];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		int t;scanf("%d",&t);
		int now=M-t;
		int ans=i;
		for(int j=1;j<=100;j++)
		{
			int get=min(now/j,cnt[j]);
			now-=get*j;
			ans-=get;
		}
		cnt[t]++;
		printf("%d%c",ans,i==N-1?10:32);
	}
}