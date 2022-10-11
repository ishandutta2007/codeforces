#include <bits/stdc++.h>
using namespace std;
int n,k,a[505],b[505];
bool dp[505][505][505],vis[505][505][505];
bool solve(int idx,int sa,int sb)
{
	if (idx==n)
	return (sa+sb<k);
	if (vis[idx][sa][sb])
	return dp[idx][sa][sb];
	vis[idx][sa][sb]=1;
	bool ret=solve(idx+1,(sa+a[idx])%k,(sb+b[idx])%k);
	for (int i=1;i<k;i++)
	{
		if (i<=a[idx] && k-i<=b[idx])
		ret|=solve(idx+1,(sa+a[idx]-i)%k,(sb+b[idx]-(k-i))%k);
	}
	return dp[idx][sa][sb]=ret;
}
int main()
{
	scanf("%d%d",&n,&k);
	bool gr=0;
	long long sa=0,sb=0;
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		sa+=a[i];
		sb+=b[i];
		gr|=(a[i]>=k && b[i]>=k);
	}
	if (sa%k+sb%k<k)
	{
		printf("%I64d",sa/k+sb/k);
		return 0;
	}
	if (gr)
	{
		printf("%I64d",sa/k+sb/k+1);
		return 0;
	}
	printf("%I64d",sa/k+sb/k+solve(0,0,0));
}