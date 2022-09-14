#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int cnt[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=1;i<=N;i++)cnt[i]=0;
		int ans=0,uniq=0;
		for(int i=0;i<N;i++)
		{
			int a;scanf("%d",&a);
			cnt[a]++;
			if(cnt[a]==1)uniq++;
		}
		for(int i=1;i<=N;i++)
		{
			ans=max(ans,min(cnt[i],uniq-1));
			if(cnt[i]>0)ans=max(ans,min(cnt[i]-1,uniq));
		}
		printf("%d\n",ans);
	}
}