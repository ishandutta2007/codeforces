#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,M;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		vector<vector<int> >ds(N);
		vector<int>cnt(M);
		for(int i=0;i<M;i++)
		{
			int K;scanf("%d",&K);
			cnt[i]=K;
			for(;K--;)
			{
				int id;scanf("%d",&id);
				id--;
				ds[id].push_back(i);
			}
		}
		vector<int>ord(N);
		for(int i=0;i<N;i++)ord[i]=i;
		sort(ord.begin(),ord.end(),[&ds](int i,int j)
		{
			return ds[i].size()<ds[j].size();
		});
		vector<int>ans(M,0);
		int lst=ord.back();
		if(ds[lst].size()<=(M+1)/2)
		{
			for(int d:ds[lst])ans[d]=lst+1;
		}
		else
		{
			vector<int>day=ds[lst];
			sort(day.begin(),day.end(),[&cnt](int di,int dj)
			{
				return cnt[di]<cnt[dj];
			});
			for(int i=0;i<(M+1)/2;i++)ans[day[i]]=lst+1;
		}
		for(int id:ord)
		{
			if(id==lst)break;
			int cnt=0;
			for(int d:ds[id])
			{
				if((M+1)/2<cnt+1)break;
				if(ans[d]==0)
				{
					ans[d]=id+1;
					cnt++;
				}
			}
		}
		bool fn=false;
		for(int i=0;i<M;i++)if(ans[i]==0)fn=true;
		if(fn)puts("NO");
		else
		{
			puts("YES");
			for(int i=0;i<M;i++)printf("%d%c",ans[i],i+1==M?10:32);
		}
	}
}