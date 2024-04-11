#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,K;
vector<int>A;
long long dp[1001][1002];
long long mod=998244353;
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		int a;scanf("%d",&a);
		A.push_back(a);
	}
	sort(A.begin(),A.end());
	long long ans=0;
	if(K==2)
	{
		for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)(ans+=A[j]-A[i])%=mod;
		printf("%d\n",ans);
		return 0;
	}
	for(int x=1;x<=100000/(K-1);x++)
	{
		for(int i=0;i<=N;i++)for(int j=0;j<=K;j++)dp[i][j]=0;
		int id=0;
		dp[0][0]=1;
		for(int i=0;i<N;i++)
		{
			while(id<N&&A[i]+x>A[id])id++;
			for(int j=0;j<=K;j++)
			{
				(dp[i+1][j]+=dp[i][j])%=mod;
				(dp[id][j+1]+=dp[i][j])%=mod;
			}
		}
		(ans+=dp[N][K])%=mod;
	}
	printf("%lld\n",ans);
}