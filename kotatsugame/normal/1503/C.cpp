#include<cstdio>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;
int N;
pair<int,int>AC[1<<17];
long long dp[1<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&AC[i].first,&AC[i].second);
	}
	sort(AC,AC+N);
	priority_queue<pair<long long,int> >Z;
	priority_queue<long long>P;
	for(int i=0;i<N;i++)
	{
		while(!Z.empty())
		{
			int id=Z.top().second;
			int t=AC[id].first+AC[id].second;
			if(t<AC[i].first)
			{
				Z.pop();
				P.push(-(-t+dp[id]));
			}
			else break;
		}
		if(i==0)dp[i]=0;
		else
		{
			dp[i]=9e18;
			if(!Z.empty())dp[i]=min(dp[i],-Z.top().first);
			if(!P.empty())dp[i]=min(dp[i],AC[i].first-P.top());
		}
		Z.push(make_pair(-dp[i],i));
	}
	long long ans=dp[N-1];
	for(int i=0;i<N;i++)ans+=AC[i].second;
	printf("%lld\n",ans);
}