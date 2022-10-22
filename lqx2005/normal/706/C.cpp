#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100000;
const int inf=1e16;
int n;
int dp[maxn+5][2];
int c[maxn+5];
string s[maxn+5],t[maxn+5];
void ckm(int &x,int y)
{
	if(x>y) x=y;
	return;
}
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		t[i]=s[i];
		reverse(t[i].begin(),t[i].end());
	}
	for(int i=0;i<=n;i++) dp[i][0]=dp[i][1]=inf;
	dp[1][0]=0;
	dp[1][1]=c[1];
	for(int i=2;i<=n;i++)
	{
		if(s[i-1]<=s[i]) ckm(dp[i][0],dp[i-1][0]);
		if(t[i-1]<=s[i]) ckm(dp[i][0],dp[i-1][1]);
		if(s[i-1]<=t[i]) ckm(dp[i][1],dp[i-1][0]+c[i]);
		if(t[i-1]<=t[i]) ckm(dp[i][1],dp[i-1][1]+c[i]);
	}
	printf("%lld\n",min(dp[n][0],dp[n][1])>=inf?-1:min(dp[n][0],dp[n][1]));
	return 0;
}