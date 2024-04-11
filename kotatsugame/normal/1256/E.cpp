#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int dp[2<<17],pr[2<<17];
int ans[2<<17];
main()
{
	scanf("%d",&N);
	vector<pair<int,int> >A(N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i].first);
		A[i].second=i;
	}
	sort(A.begin(),A.end());
	for(int i=0;i<=N-1;i++)dp[i]=-1e9;
	dp[2]=0;
	pr[2]=-1;
	for(int i=2;i<N-1;i++)
	{
		if(i+3<=N-1)
		{
			if(dp[i+3]<dp[i]+A[i+1].first-A[i].first)
			{
				pr[i+3]=i;
				dp[i+3]=dp[i]+A[i+1].first-A[i].first;
			}
		}
		if(dp[i+1]<dp[i])
		{
			pr[i+1]=i;
			dp[i+1]=dp[i];
		}
	}
	int id=N-1;
	int k=1;
	while(id>=0)
	{
		if(pr[id]==id-1)
		{
			ans[A[id].second]=k;
			id--;
		}
		else
		{
			ans[A[id].second]=k;
			ans[A[id-1].second]=k;
			ans[A[id-2].second]=k;
			id-=3;
			k++;
		}
	}
	printf("%d %d\n",A[N-1].first-A[0].first-dp[N-1],k-1);
	for(int i=0;i<N;i++)printf("%d%c",ans[i],i+1==N?10:32);
}