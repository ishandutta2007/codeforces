#include<bits/stdc++.h>
using namespace std;
long long n,m,x,id[222222],cnt,a[222222],dp[222222],pre[222222];
vector<long long> num[222222],ans;
bool f[222222];
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
pair<long long,long long> extgcd(long long a,long long b)
{
	if (!b) return make_pair(1,0);
	pair<long long,long long> cur=extgcd(b,a%b);
	return make_pair(cur.second,cur.first-(a/b)*cur.second);
}
long long solve(long long a,long long b)
{
	long long d=gcd(a,m),g,x;
	a/=d;b/=d;g=m/d;
	x=extgcd(a,g).first;
	return (x*b%g+g)%g;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		f[x]=1;
	}
	for (long long i=1;i<=m;i++)
	{
		if (m%i==0)
		{
			a[++cnt]=i;
			id[i]=cnt;
		}
	}
	for (long long i=0;i<m;i++)
	{
		if (!f[i]) num[id[gcd(i,m)]].push_back(i); 
	}
	dp[1]=num[1].size();
	for (long long i=2;i<=cnt;i++)
	{
		dp[i]=-1e9;
		for (long long j=1;j<i;j++)
		{
			if (a[i]%a[j]) continue;
			if (dp[j]>dp[i])
			{
				dp[i]=dp[j];
				pre[i]=j;
			}
		}
		dp[i]+=num[i].size();
	}
	for (long long cur=cnt;cur;cur=pre[cur])
	{
		for (long long j=0;j<num[cur].size();j++) ans.push_back(num[cur][j]); 
	}
	reverse(ans.begin(),ans.end());
	printf("%lld\n%lld ",(long long)ans.size(),(long long)ans[0]);
	for (long long i=0;i<(long long)ans.size()-1;i++)
	{
		printf("%lld ",solve(ans[i],ans[i+1]));
	}
	return 0;
}