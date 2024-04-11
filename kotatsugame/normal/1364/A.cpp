#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,X;
int A[1<<17];
int beg[10101];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&X);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<=10000;i++)beg[i]=N+1;
		int S=0;
		beg[0]=0;
		vector<pair<int,int> >now;
		now.push_back(make_pair(0,0));
		for(int i=0;i<N;i++)
		{
			S+=A[i];
			S%=X;
			if(beg[S]==N+1)
			{
				beg[S]=i+1;
				now.push_back(make_pair(i+1,S));
			}
		}
		S=0;
		int ans=-1;
		for(int i=0;i<N;i++)
		{
			S+=A[i];
			S%=X;
			if((S-now[0].second)%X!=0)ans=max(ans,i+1-now[0].first);
			else if(now.size()>1)ans=max(ans,i+1-now[1].first);
		}
		printf("%d\n",ans);
	}
}