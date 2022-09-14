#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
using dat=pair<int,pair<int,int> >;
int T,N;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		int ans=0;
		priority_queue<dat,vector<dat>,greater<dat> >P;
		int prv=-1,nowc=0;
		for(int i=0;i<N;i++)
		{
			while(!P.empty()&&P.top().first<=A[i])
			{
				dat now=P.top();P.pop();
				ans=max(ans,++now.second.second);
				now.first=2*A[i]-now.second.first;
				P.push(now);
			}
			if(A[i]==prv)
			{
				ans=max(ans,++nowc);
			}
			else
			{
				if(prv!=-1)
				{
					ans=max(ans,nowc+1);
					P.push(make_pair(2*A[i]-prv,make_pair(prv,nowc+1)));
				}
				prv=A[i];
				nowc=1;
			}
		}
		printf("%d\n",N-ans);
	}
}