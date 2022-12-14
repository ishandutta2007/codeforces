#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,a[333333],dp[333333],sum[333333],l,r,mid;
bool check(int mid)
{
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	dp[0]=1;sum[0]=1;
	int lb,rb;
	for (int i=1;i<=n;i++)
	{
		rb=i-k;
		lb=lower_bound(a+1,a+n+1,a[i]-mid)-a-1;
		if (rb<0 || lb>rb) dp[i]=0;
		else if (sum[rb]-(lb-1>=0 ? sum[lb-1] : 0)>0) dp[i]=1;
		else dp[i]=0;
		sum[i]=sum[i-1]+dp[i];
	}
	return dp[n];
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	l=0;r=1e9+1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}