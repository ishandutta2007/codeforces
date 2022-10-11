#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000007
long long fact[200005],dp[2005];
pair<int,int> arr[100005];
long long pow_log(long long n,long long exp)
{
    long long ret;
    if (exp==0)
    return 1;
    if (exp==1)
    return n;
    ret=pow_log(n,exp/2);
    if (exp%2==0)
    return (((ret%mod)*(ret%mod))%mod);
    else
    return ((((ret%mod)*(ret%mod))%mod)*n)%mod;
}
long long ncr(long long n,long long r)
{
	if (r<0)
	return 0;
	return (fact[n]*pow_log((fact[r]*fact[n-r])%mod,mod-2))%mod;
}
int main()
{
	int h,w,n;
	scanf("%d%d%d",&h,&w,&n);
	for (int i=0;i<n;i++)
	scanf("%d%d",&arr[i].first,&arr[i].second);
	arr[n]=make_pair(h,w);
	sort(arr,arr+n);
	fact[0]=1;
	for (int i=1;i<200005;i++)
	fact[i]=(i*fact[i-1])%mod;
	for (int i=0;i<=n;i++)
	{
		dp[i]=ncr(arr[i].first+arr[i].second-2,arr[i].first-1);
		for (int x=0;x<i;x++)
		dp[i]=(dp[i]-(ncr(arr[i].first+arr[i].second-arr[x].first-arr[x].second,arr[i].second-arr[x].second)*dp[x])%mod+mod)%mod;
	}
	printf("%I64d",dp[n]);
}