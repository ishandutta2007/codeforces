#include<cstdio>
#include<vector>
using namespace std;
int T,K,N,M;
int A[100],B[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&K,&N,&M);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<M;i++)scanf("%d",&B[i]);
		int ai=0,bi=0;
		vector<int>ans;ans.reserve(N+M);
		while(ai<N||bi<M)
		{
			if(ai<N&&A[ai]<=K)
			{
				ans.push_back(A[ai]);
				if(A[ai]==0)K++;
				ai++;
			}
			else if(bi<M&&B[bi]<=K)
			{
				ans.push_back(B[bi]);
				if(B[bi]==0)K++;
				bi++;
			}
			else
			{
				break;
			}
		}
		if(ans.size()<N+M)puts("-1");
		else for(int i=0;i<N+M;i++)printf("%d%c",ans[i],i+1==N+M?10:32);
	}
}