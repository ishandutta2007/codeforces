#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,K;
int A[2<<17];
const int LIM=1e7;
int SQ[LIM+1];
int inv[2<<17];
pair<int,int>dp[21][2<<17];
main()
{
	scanf("%d",&T);
	for(int i=1;i*i<=LIM;i++)
	{
		for(int j=i*i;j<=LIM;j+=i*i)SQ[j]=i*i;
	}
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		vector<pair<int,int> >val(N);
		for(int i=0;i<N;i++)
		{
			int X;scanf("%d",&X);
			A[i]=X/SQ[X];
			val[i]=make_pair(A[i],i);
		}
		sort(val.begin(),val.end());
		for(int i=0;i<N;i++)inv[val[i].second]=i;
		for(int i=0;i<=K;i++)for(int j=0;j<=N;j++)dp[i][j]=make_pair(1e9,0);
		dp[0][0]=make_pair(1,0);
		for(int i=0;i<N;i++)for(int j=0;j<=K;j++)
		{
			int c=dp[j][i].first,l=-dp[j][i].second;
			int id=inv[i];
			if(id==0||val[id-1].first!=A[i]||val[id-1].second<l)
			{
				dp[j][i+1]=min(dp[j][i+1],make_pair(c,-l));
			}
			else
			{
				if(j<K)dp[j+1][i+1]=min(dp[j+1][i+1],make_pair(c,-l));
				dp[j][i+1]=min(dp[j][i+1],make_pair(c+1,-i));
			}
		}
		int ans=1e9;
		for(int j=0;j<=K;j++)ans=min(ans,dp[j][N].first);
		printf("%d\n",ans);
	}
}