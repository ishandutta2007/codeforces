#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int Q;
main()
{
	scanf("%d",&Q);
	for(;Q--;)
	{
		int N;scanf("%d",&N);
		vector<int>cnt(N,0);
		for(int i=0;i<N;i++)
		{
			int a;scanf("%d",&a);
			cnt[a-1]++;
		}
		sort(cnt.begin(),cnt.end());
		int ans=0,pre=N*2;
		for(int i=N;i--;)
		{
			int t=max(0,min(pre-1,cnt[i]));
			ans+=t;
			pre=t;
			if(pre==0)break;
		}
		printf("%d\n",ans);
	}
}