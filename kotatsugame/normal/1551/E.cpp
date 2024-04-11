#include<iostream>
#include<algorithm>
using namespace std;
int T,N,K;
int A[2000];
int dp[2000];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<N;i++)cin>>A[i];
		int ans=1e9;
		for(int i=0;i<N;i++)
		{
			int now=0;
			if(A[i]<=i+1)
			{
				for(int j=0;j<i;j++)if(A[j]<A[i]&&A[j]+i-j>=A[i])
				{
					if(now<dp[j])now=dp[j];
				}
				now++;
			}
			dp[i]=now;
			if(dp[i]>=K)
			{
				ans=min(ans,i+1-A[i]);
			}
		}
		if(ans>N)ans=-1;
		cout<<ans<<endl;
	}
}