#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
const long long mod=1e9+7;
long long n,m,k,a[555555],x,y,pa[555555],all,pw[555555],ans,cnt;
map<long long,vector<pair<long long,long long> > > mp;
vector<pair<long long,long long> > s;
vector<long long> v;
long long root(long long x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(long long x,long long y)
{
	long long rx=root(x),ry=root(y);
	if (rx==ry) return;
	v.push_back(x);v.push_back(y);
	all--;
	pa[ry]=rx;  
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		mp[a[x]^a[y]].push_back(make_pair(x,y));
	}
	for (long long i=1;i<=n;i++) pa[i]=i;
	pw[0]=1;
	for (long long i=1;i<=500000;i++) pw[i]=pw[i-1]*2%mod;
	for (map<long long,vector<pair<long long,long long> > >::iterator it=mp.begin();it!=mp.end();it++)
	{
		cnt++;
		s=it->second;
		for (long long i=0;i<v.size();i++) pa[v[i]]=v[i];
		v.clear();all=n;
		for (long long i=0;i<s.size();i++)
		{
			Union(s[i].first,s[i].second);
		}
		ans=(ans+pw[all])%mod;
	}
	ans=(ans+(pw[k]-cnt)*pw[n])%mod;
	if (ans<0) ans+=mod;
	printf("%I64d\n",ans);
	return 0;
}