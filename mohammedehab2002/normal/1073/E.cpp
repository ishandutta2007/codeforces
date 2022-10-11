#include <iostream>
#include <string.h>
using namespace std;
#define mod 998244353
long long pw[19];
pair<int,int> dp[19][1024][2][2];
bool vis[19][1024][2][2];
int k;
string s;
pair<int,int> go(int idx,int m,bool f,int st)
{
	if (idx==s.size())
	{
		if (__builtin_popcount(m)<=k)
		return {0,1};
		return {0,0};
	}
	if (vis[idx][m][f][st])
	return dp[idx][m][f][st];
	vis[idx][m][f][st]=1;
	pair<int,int> ans(0,0);
	for (int i=st;i<10;i++)
	{
		if (!f || i<=s[idx]-'0')
		{
			pair<int,int> tmp=go(idx+1,(m|(1<<i)),(f && i==s[idx]-'0'),0);
			ans.first=(ans.first+tmp.first)%mod;
			ans.first=(ans.first+(long long)i*((pw[s.size()-idx-1]*tmp.second)%mod))%mod;
			ans.second=(ans.second+tmp.second)%mod;
		}
	}
	return dp[idx][m][f][st]=ans;
}
int solve(long long x)
{
	s=to_string(x);
	int ret=0;
	for (int i=0;i<s.size();i++)
	{
		memset(vis,0,sizeof(vis));
		ret=(ret+go(i,0,!i,1).first)%mod;
	}
	return ret;
}
int main()
{
	pw[0]=1;
	for (int i=1;i<19;i++)
	pw[i]=(10*pw[i-1])%mod;
	long long l,r;
	cin >> l >> r >> k;
	cout << (solve(r)-solve(l-1)+mod)%mod;
}