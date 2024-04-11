#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define mod 1000000007
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
vector<pair<int,int> > v;
long long fact[200005],inv[200005];
int main()
{
	fact[0]=1;
	for (int i=1;i<200005;i++)
	fact[i]=(fact[i-1]*i)%mod;
	inv[200004]=pow_log(fact[200004],mod-2);
	for (int i=200003;i>=0;i--)
	inv[i]=(inv[i+1]*(i+1))%mod;
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		v.push_back({l,1});
		v.push_back({r+1,-1});
	}
	sort(v.begin(),v.end());
	int cur=0;
	long long sum=0;
	for (int i=0;i<v.size()-1;i++)
	{
		cur+=v[i].second;
		if (cur>=k)
		{
			long long tmp=v[i+1].first-v[i].first;
			tmp=(tmp*fact[cur])%mod;
			tmp=(tmp*inv[k])%mod;
			tmp=(tmp*inv[cur-k])%mod;
			sum=(sum+tmp)%mod;
		}
	}
	printf("%I64d",sum);
}