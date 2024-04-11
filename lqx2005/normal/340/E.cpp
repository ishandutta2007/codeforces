#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2200; 
const int mod=1e9+7;
int n;
int a[maxn],v[maxn],t[maxn];
int dp[maxn][maxn];
int ca=0,cb=0;
signed main()
{
	scanf("%lld",&n);
	int fag=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==i) fag=1;
		if(a[i]!=-1) t[a[i]]=1;
		else v[i]=1;
	}
	if(fag) return printf("0\n"),0;
	for(int i=1;i<=n;i++)
	{
		if(t[i]) continue;
		if(v[i]) ca++;
		else cb++;
	}
	for(int i=0;i<=ca+cb;i++) dp[0][i]=1;
	for(int i=1;i<=ca;i++)
	{
		for(int j=1;j<=ca+cb;j++)
		{
			if(i>j) continue;
			dp[i][j]=dp[i-1][j-1]*(j-i)%mod;
			int t=i>=2?dp[i-2][j-1]*(i-1)%mod*(j-i+1)%mod:0;
			dp[i][j]=(dp[i][j]+t)%mod;
		}
	}
	int ans=dp[ca][ca+cb];
	for(int i=cb;i>=1;i--) ans=ans*i%mod;
	printf("%lld\n",ans);
	return 0;
}