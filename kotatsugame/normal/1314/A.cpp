#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	long long ans=0;
	vector<pair<int,int> >A(N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i].first);
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i].second);
	}
	sort(A.begin(),A.end());
	int pre=0;
	priority_queue<int>P;
	long long sum=0;
	for(pair<int,int>p:A)
	{
		int diff=p.first-pre;
		pre=p.first;
		while(!P.empty()&&diff>0)
		{
			sum-=P.top();
			P.pop();
			diff--;
			ans+=sum;
		}
		ans+=sum*(long long)diff;
		sum+=p.second;
		P.push(p.second);
	}
	while(!P.empty())
	{
		sum-=P.top();
		P.pop();
		ans+=sum;
	}
	printf("%lld\n",ans);
}