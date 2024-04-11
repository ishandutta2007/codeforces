#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int m=26;
int a[27];
char s[5000];
int n;
int b;
int dp[5000][3];
int mod=1000000007;
int maximum(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int minimum(int x,int y)
{
	if(x<y) return x;
	else return y;
}
int main()
{
	scanf("%d",&n);
	dp[0][0]=1;
	dp[0][1]=0;
	dp[0][2]=0;
	scanf("%s",s);
	for(int i=0;i<m;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		dp[i+1][2]=1000000;
		b=1000000;
		for(int j=i;j>=0;j--)
		{
			if(a[s[j]-'a']<b) b=a[s[j]-'a'];
			if(i-j+1>b) break;
			dp[i+1][0]+=dp[j][0];
			if(dp[i+1][0]>=mod) dp[i+1][0]-=mod;
			dp[i+1][1]=maximum(dp[i+1][1],maximum(i-j+1,dp[j][1]));
			dp[i+1][2]=minimum(dp[i+1][2],1+dp[j][2]);
		}
	}
	printf("%d\n%d\n%d",dp[n][0],dp[n][1],dp[n][2]);
	return 0;
}