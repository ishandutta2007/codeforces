#include<cstdio>
#include<vector>
#include<deque>
using namespace std;
int N,K,X;
int A[5050];
deque<pair<long long,int> >P[5050];
main()
{
	scanf("%d%d%d",&N,&K,&X);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<=X;i++)P[i].push_back(make_pair(0,0));
	for(int i=0;i<N;i++)
	{
		for(int j=X;j--;)if(!P[j].empty())
		{
			long long now=P[j].front().first+A[i];
			while(!P[j+1].empty()&&P[j+1].back().first<=now)P[j+1].pop_back();
			P[j+1].push_back(make_pair(now,i+1));
		}
		for(int j=0;j<=X;j++)
		{
			if(!P[j].empty()&&P[j].front().second+K<=i+1)P[j].pop_front();
		}
	}
	long long ans=-1e18;
	for(int j=0;j<=X;j++)if(!P[j].empty())ans=max(ans,P[j].front().first);
	if(ans<0)ans=-1;
	printf("%lld\n",ans);
}