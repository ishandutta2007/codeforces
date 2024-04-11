#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,k,m,cnt[500005],o[500005],dp[500005],cum[500005];
vector<pair<pair<int,int>,int> > a;
vector<pair<int,int> > v[2];
long long solve()
{
	memset(cnt,0,sizeof(cnt));
	memset(o,0,sizeof(o));
	for (auto p:v[1])
	{
		cnt[p.first]++;
		cnt[p.second+1]--;
	}
	for (int i=1;i<=n;i++)
	cnt[i]+=cnt[i-1];
	vector<pair<int,int> > tmp;
	for (auto p:v[0])
	{
		while (!tmp.empty() && p.second<=tmp.back().second)
		tmp.pop_back();
		tmp.push_back(p);
	}
	for (auto p:tmp)
	o[p.second]=p.first;
	dp[0]=1;
	cum[0]=1;
	for (int i=1;i<=n;i++)
	{
		cum[i]=cum[i-1];
		if (!cnt[i])
		cum[i]=(cum[i]+dp[i-1])%mod;
		if (o[i])
		dp[i]=(cum[i]-cum[o[i]-1]+mod)%mod;
		else
		dp[i]=((1+!cnt[i])*dp[i-1])%mod;
	}
	return dp[n];
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	while (m--)
	{
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		a.push_back({{l,-r},c});
	}
	sort(a.begin(),a.end());
	for (auto &p:a)
	p.first.second*=-1;
	int ans=1;
	for (int i=0;i<k;i++)
	{
		v[0].clear();
		v[1].clear();
		for (auto p:a)
		v[((p.second>>i)&1)].push_back(p.first);
		ans=(ans*solve())%mod;
	}
	printf("%d",ans);
}