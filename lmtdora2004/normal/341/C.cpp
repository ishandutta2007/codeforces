#include <bits/stdc++.h>
#define int long long

using namespace std;

int mod=1000000007;
bool have[2005], del[2005];
int tot=0, thoixong=0;
int a[2005];
int dp[2005];
int C[2005][2005];
int gt[2005];

void solve()
{
	dp[0]=gt[tot];
	for(int i=1; i<=thoixong; i++)
	{
		dp[i]=gt[i+tot];
		for(int j=1; j<=i; j++)
		{
			// cout<<dp[i]<<endl;
			dp[i]-=dp[i-j]*C[j][i];
			dp[i]%=mod;
			dp[i]+=mod;
			dp[i]%=mod;
			// cout<<dp[i]<<endl;
		}
	}
}

signed main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<=n; i++)
	{
		if(a[i]==-1)
		{
			del[i]=true;
			tot++;
		}
		else
		{
			have[a[i]]=true;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(!have[i]&&del[i])
		{
			thoixong++;
		}
	}
	tot-=thoixong;
	for(int i=0; i<=n; i++)
	{
		C[0][i]=1;
	}
	gt[0]=1;
	for(int i=1; i<=n; i++)
	{
		gt[i]=gt[i-1]*i;
		gt[i]%=mod;
		for(int j=i; j<=n; j++)
		{
			C[i][j]=C[i][j-1]+C[i-1][j-1];
			C[i][j]%=mod;
		}
	}
	solve();
	// cout<<C[1][2]<<endl;
	cout<<dp[thoixong];
}