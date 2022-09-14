#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N;
pair<int,int>P[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		{
			vector<int>R(N),C(N);
			for(int i=0;i<N;i++)scanf("%d",&R[i]);
			for(int i=0;i<N;i++)scanf("%d",&C[i]);
			for(int i=0;i<N;i++)P[i]=make_pair(R[i],C[i]);
		}
		sort(P,P+N);
		int r=1,c=1;
		int ans=0;
		for(int i=0;i<N;i++)
		{
			int dx=P[i].first-r;
			int dy=P[i].second-c;
			if(dx==dy)
			{
				if((r+c)%2==0)ans+=dy;
			}
			else
			{
				int d=dx-dy;
				if((r+c)%2==0)ans+=d/2;
				else ans+=(d+1)/2;
			}
			r=P[i].first;
			c=P[i].second;
		}
		printf("%d\n",ans);
	}
}