#include<iostream>
#include<algorithm>
using namespace std;
const int mod=998244353;
int T,N;
int cnt[5001];
int comb[5001][5001];
int dp[2][5050];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=0;i<=5000;i++)
	{
		comb[i][0]=comb[i][i]=1;
		for(int j=1;j<i;j++)comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
	}
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=N;i++)cnt[i]=0;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			cnt[a]++;
		}
		int mx=N;
		while(!cnt[mx])mx--;
		if(cnt[mx]>1)
		{
			cout<<"0\n";
			continue;
		}
		cnt[mx]--;
		int now=0;
		for(int i=0;i<=N;i++)dp[now][i]=0;
		dp[now][0]=1;
		int cumsum=1;
		for(int i=N;i>=1;i--)if(cnt[i]>0)
		{
			int nxt=1-now;
			for(int j=0;j<=N;j++)dp[nxt][j]=0;
			for(int j=cnt[i]-1;j<=N;j++)
			{
				if(cumsum==N-1-j)(dp[nxt][j+1-cnt[i]]+=(long long)dp[now][j]*comb[j+1][cnt[i]]%mod)%=mod;
				else if(j>=cnt[i])(dp[nxt][j-cnt[i]]+=(long long)dp[now][j]*comb[j][cnt[i]]%mod)%=mod;
			}
			for(int j=cnt[i]-1;j<=N;j++)(dp[nxt][j-cnt[i]+2]+=(long long)dp[now][j]*comb[j][cnt[i]-1]%mod)%=mod;
			now=nxt;
			cumsum+=cnt[i];
		}
		cout<<dp[now][0]<<"\n";
	}
}