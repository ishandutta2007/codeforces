#include <iostream>
using namespace std;
#define mod 998244353
int n,arr[200005],cnt[200005],tree[200005];
long long fact[200005],dp[200005];
int f(long long x)
{
	return (x*(x-1)/2)%mod;
}
long long pow_log(long long x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
	return ret;
}
void update(int idx)
{
	while (idx<=n)
	{
		tree[idx]++;
		idx+=(idx&(-idx));
	}
}
int query(int idx)
{
	int ans=0;
	while (idx)
	{
		ans+=tree[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}
int main()
{
	int neg=0;
	scanf("%d",&n);
	fact[0]=1;
	for (int i=1;i<=n;i++)
	fact[i]=(fact[i-1]*i)%mod;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		if (arr[i]!=-1)
		cnt[arr[i]]--;
		else
		neg++;
		cnt[i]++;
		dp[i]=(dp[i-1]*i+fact[i-1]*f(i))%mod;
	}
	for (int i=1;i<=n;i++)
	cnt[i]+=cnt[i-1];
	long long ans=dp[neg],inv=0,cur=0;
	for (int i=n;i>0;i--)
	{
		if (arr[i]==-1)
		{
			cur++;
			continue;
		}
		ans=(ans+((cnt[arr[i]]*cur+(neg-cnt[arr[i]])*(neg-cur))%mod)*fact[neg-1])%mod;
		inv+=query(arr[i]);
		update(arr[i]);
	}
	printf("%I64d",(ans*pow_log(fact[neg],mod-2)+inv)%mod);
}