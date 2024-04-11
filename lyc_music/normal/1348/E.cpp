#include<bits/stdc++.h>
#define N 600
#define int long long
using namespace std;
int n,K,a[N],b[N],sum1,sum2;
bool dp[2][N];
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>K;
	for (int i=1;i<=n;i++) cin>>a[i]>>b[i],sum1+=a[i],sum2+=b[i];
	if (sum1/K+sum2/K==(sum1+sum2)/K) {cout<<sum1/K+sum2/K<<endl;return 0;}
	dp[1][0]=1;
	for (int i=1;i<=n;i++)
	{
		memcpy(dp[0],dp[1],sizeof(dp[0]));
		for (int j=0;j<K;j++)
			if (dp[0][j])
			{
				for (int k=1;k<K;k++)
					if (k<=a[i]&&(K-k)<=b[i])
						dp[1][(j+k)%K]=1;
			}
		for (int j=K-(sum2%K);j<=sum1%K;j++)
			if (dp[1][j])
			{
				cout<<(sum1+sum2)/K<<endl;
				return 0;
			}
		
	}
	cout<<(sum1+sum2)/K-1<<endl;
}