#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
const long long mod=1e9+7;
long long n,a[1111111],val[1111111],x,dp[1111111],cur,ans[1111111],su[1111111];
long long sum;
vector<long long> g[1111111];
bool f[1111111];
map<long long,long long> mp;
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
void dfs(long long i,long long fa)
{
	dp[i]=val[i];
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		dfs(to,i);
		dp[i]+=dp[to];
	}
	x=sum/gcd(sum,dp[i]);
	for (long long j=x;j<=n;j+=x) su[j]++;
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&val[i]);
		sum+=val[i];
	}
	for (long long i=2;i<=n;i++)
	{
		scanf("%I64d",&x);
		g[x].push_back(i); 
	}
	f[1]=1;
	dfs(1,0);
	for (long long i=2;i<=n;i++)
	{
		if (su[i]>=i) f[i]=1;
	}
	for (long long i=n;i>=1;i--)
	{
		if (!f[i]) continue;
		ans[i]=1;
		for (long long j=i+i;j<=n;j+=i)
		{
			if (f[j]) ans[i]=(ans[i]+ans[j])%mod;
		}
	}
	printf("%I64d\n",ans[1]);
	return 0;
}