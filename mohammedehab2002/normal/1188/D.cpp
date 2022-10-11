#include <bits/stdc++.h>
using namespace std;
int n,br[65],dp[65][100005];
long long a[100005],s[65][100005];
int solve(int b,int c)
{
	if (b==60)
	return c;
	if (dp[b][c]!=-1)
	return dp[b][c];
	int cnt1=lower_bound(s[b],s[b]+br[b],s[b-1][n-c])-s[b],cnt2=lower_bound(s[b]+br[b],s[b]+n,(s[b-1][n-c]^(1LL<<b)))-s[b]-br[b];
	return dp[b][c]=min(solve(b+1,n-br[b]-cnt2)+br[b]-cnt1+cnt2,solve(b+1,n-cnt1)+n-(br[b]-cnt1+cnt2));
}
int main()
{
	scanf("%d",&n);
	long long mx=0;
	for (int i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		mx=max(mx,a[i]);
	}
	for (int i=0;i<n;i++)
	a[i]=2*(mx-a[i]);
	for (int i=0;i<60;i++)
	{
		long long pw=(1LL<<(i+1))-1;
		for (int j=0;j<n;j++)
		s[i][j]=(a[j]&pw);
		sort(s[i],s[i]+n);
		br[i]=n;
		while (br[i] && s[i][br[i]-1]&(1LL<<i))
		br[i]--;
		s[i][n]=(1LL<<60);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d",solve(1,0));
}