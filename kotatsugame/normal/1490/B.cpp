#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int cnt[3]={};
		for(int i=0;i<N;i++)
		{
			int a;scanf("%d",&a);cnt[a%3]++;
		}
		int ans=0;
		for(int i=0;i<6;i++)
		{
			if(cnt[i%3]>N/3)
			{
				ans+=cnt[i%3]-N/3;
				cnt[(i+1)%3]+=cnt[i%3]-N/3;
				cnt[i%3]=N/3;
			}
		}
		printf("%d\n",ans);
	}
}