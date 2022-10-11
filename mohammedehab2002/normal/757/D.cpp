#include <iostream>
#include <string.h>
using namespace std;
#define mod 1000000007
int n,nex[80],dp[80][(1<<20)];
string s;
int solve(int i,int mask)
{
	if (dp[i][mask]!=-1)
	return dp[i][mask];
	int ret=0,cur=0;
	if (mask && !(mask&(mask+1)))
	ret=1;
	for (int j=nex[i]+1;j<=n;j++)
	{
		cur=2*cur+s[j-1]-'0';
		if (cur>20)
		break;
		ret=(ret+solve(j,mask|(1<<(cur-1))))%mod;
	}
	return dp[i][mask]=ret;
}
int main()
{
	cin >> n >> s;
	nex[n]=n;
	for (int i=n-1;i>=0;i--)
	{
		nex[i]=nex[i+1];
		if (s[i]=='1')
		nex[i]=i;
	}
	int ans=0;
	memset(dp,-1,sizeof(dp));
	for (int i=0;i<s.size();i++)
	ans=(ans+solve(i,0))%mod;
	cout << ans;
}