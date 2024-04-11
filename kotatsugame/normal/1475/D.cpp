#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,M;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		vector<vector<int> >As(2);
		for(int i=0;i<N;i++)
		{
			int b;scanf("%d",&b);As[b-1].push_back(A[i]);
		}
		for(int i=0;i<2;i++)sort(As[i].rbegin(),As[i].rend());
		int ans=1e9;
		long long sum=0;
		int cost=0;
		for(int a:As[0])sum+=a,cost+=1;
		int i0=As[0].size();
		while(i0>0&&sum-As[0][i0-1]>=M)
		{
			sum-=As[0][--i0];
			cost--;
		}
		if(sum>=M)ans=min(ans,cost);
		for(int i=0;i<As[1].size();i++)
		{
			sum+=As[1][i];
			cost+=2;
			while(i0>0&&sum-As[0][i0-1]>=M)
			{
				sum-=As[0][--i0];
				cost--;
			}
			if(sum>=M)ans=min(ans,cost);
		}
		printf("%d\n",ans<(int)1e9?ans:-1);
	}
}