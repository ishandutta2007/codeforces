#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
int cnt[512];
int pizza[1<<17];
long long cost[1<<17];
int ans[2];
long long anscost=9e18;
int anscnt=-1;
int mid[2];
int getid[512];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		int f;scanf("%d",&f);
		int now=0;
		for(;f--;)
		{
			int a;scanf("%d",&a);
			a--;
			now|=1<<a;
		}
		for(int j=now;j<1<<9;j=j+1|now)
		{
			cnt[j]++;
		}
	}
	for(int i=0;i<1<<9;i++)getid[i]=-1;
	mid[0]=mid[1]=-1;
	for(int i=0;i<M;i++)
	{
		int f;scanf("%lld%d",&cost[i],&f);
		for(;f--;)
		{
			int a;scanf("%d",&a);
			a--;
			pizza[i]|=1<<a;
		}
		for(int j=pizza[i];;j=j-1&pizza[i])
		{
			if(getid[j]<0)getid[j]=i;
			else if(cost[getid[j]]>cost[i])getid[j]=i;
			if(j==0)break;
		}
		if(mid[0]<0||cost[mid[0]]>cost[i])
		{
			mid[1]=mid[0];
			mid[0]=i;
		}
		else if(mid[1]<0||cost[mid[1]]>cost[i])
		{
			mid[1]=i;
		}
	}
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<1<<9;j++)
		{
			int id=getid[j&~pizza[i]];
			if(id<0)continue;
			if(id==i)
			{
				if(id==mid[0])id=mid[1];
				else id=mid[0];
			}
			long long nowcost=cost[i]+cost[id];
			int nowcnt=cnt[pizza[i]|pizza[id]];
			if(nowcnt>anscnt||nowcnt==anscnt&&nowcost<anscost)
			{
				anscost=nowcost;
				anscnt=nowcnt;
				ans[0]=i+1;
				ans[1]=id+1;
			}
		}
	}
	printf("%d %d\n",ans[0],ans[1]);
}