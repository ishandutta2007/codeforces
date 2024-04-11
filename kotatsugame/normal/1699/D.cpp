#include<iostream>
#include<vector>
using namespace std;
int T,N,A[5000];
int cnt[5000][5001];
vector<int>G[5000];
int c[5000];
int dp[5001][5000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i],A[i]--;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)c[j]=0;
			int mx=0;
			cnt[i][i]=0;
			G[i].clear();
			for(int j=i;j<N;j++)
			{
				if(++c[A[j]]>mx)mx=c[A[j]];
				cnt[i][j+1]=mx;
				if((j+1-i)%2==0&&mx*2<=j+1-i)G[i].push_back(j+1);
			}
		}
		for(int i=1;i<=N;i++)for(int j=0;j<N;j++)dp[i][j]=-1e9;
		for(int i:G[0])for(int j=0;j<N;j++)dp[i][j]=0;
		for(int i=0;i<N;i++)
		{
			dp[i+1][A[i]]=max(dp[i+1][A[i]],dp[i][A[i]]+1);
			if(i>0)
			{
				for(int v:G[i])dp[v][A[i-1]]=max(dp[v][A[i-1]],dp[i][A[i-1]]);
			}
		}
		int ans=0;
		for(int j=0;j<N;j++)ans=max(ans,dp[N][j]);
		cout<<ans<<"\n";
	}
}