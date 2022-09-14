#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[3030];
int dp[3030];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<N;i++)dp[i]=0;
		int ans=N;
		for(int i=N;i--;)
		{
			if(dp[i]==0)dp[i]=1;
			int mxid=-1;
			for(int j=0;j<N;j++)if(A[j]<A[i])
			{
				if(mxid==-1||A[mxid]<A[j])mxid=j;
			}
			if(mxid!=-1&&mxid<i)dp[mxid]=dp[i]+1;
			ans=min(ans,N-dp[i]);
		}
		printf("%d\n",ans);
	}
}