#include<cstdio>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		long long N;
		int M;
		scanf("%lld%d",&N,&M);
		int cnt[99]={};
		for(int i=0;i<M;i++)
		{
			int A;scanf("%d",&A);
			int now=0;
			while(A>1)A>>=1,now++;
			cnt[now]++;
		}
		int ans=0;
		for(int i=0;i<62;i++)
		{
			if(N>>i&1)
			{
				if(cnt[i]==0)
				{
					int j=i+1;
					while(j<62&&cnt[j]==0)j++;
					if(cnt[j]!=0)
					{
						ans+=j-i;
						cnt[j]--;
						for(int k=j-1;k>i;k--)cnt[k]++;
						cnt[i]+=2;
						cnt[i]--;
						N^=1LL<<i;
					}
				}
				else
				{
					cnt[i]--;
					N^=1LL<<i;
				}
			}
			cnt[i+1]+=cnt[i]/2;
		}
		if(N!=0)puts("-1");
		else printf("%d\n",ans);
	}
}