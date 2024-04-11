#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
long long dp[360360];
int k,l=1;
long long go(int a,int b)
{
	if (a==b)
	return 0;
	if (a<b)
	return (1LL<<60);
	if (dp[a]!=-1)
	return dp[a];
	long long ans=go(a-1,b);
	for (int i=2;i<=k;i++)
	{
		if (a%i)
		ans=min(ans,go(a-a%i,b));
	}
	return dp[a]=ans+1;
}
long long solve(long long a,long long b)
{
	memset(dp,-1,sizeof(dp));
	a%=l;
	b%=l;
	return go(a,b);
}
int main()
{
	long long a,b;
	cin >> a >> b >> k;
	for (int i=2;i<=k;i++)
	l=(l*i)/__gcd(l,i);
	if (a/l==b/l)
	cout << solve(a,b);
	else
	cout << solve(a,0)+((a-a%l-b+b%l-1)/l)*(1+solve(l-1,0))+1+solve(l-1,b);
}