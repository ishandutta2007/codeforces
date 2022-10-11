#include <iostream>
#include <string.h>
using namespace std;
#define mod 1000000007
int dp[5005][5005],sum[5005][5005];
char c[5005];
int n;
int go(int,int);
int go2(int idx,int pos)
{
	if (pos<0)
	return 0;
	if (sum[idx][pos]!=-1)
	return sum[idx][pos];
	sum[idx][pos]=(go(idx,pos)+go2(idx,pos-1))%mod;
	return sum[idx][pos];
}
int go(int idx,int pos)
{
	if (idx==n-1)
	return (c[idx]=='s');
	if (dp[idx][pos]!=-1)
	return dp[idx][pos];
	if (c[idx]=='f')
	{
		dp[idx][pos]=go(idx+1,pos+1);
		return dp[idx][pos];
	}
	dp[idx][pos]=go2(idx+1,pos);
	return dp[idx][pos];
}
int main()
{
	cin >> n;
	for (int i=0;i<n;i++)
	cin >> c[i];
	memset(dp,-1,sizeof(dp));
	memset(sum,-1,sizeof(sum));
	cout << go(0,0);
}