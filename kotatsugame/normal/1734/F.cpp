#include<iostream>
#include<map>
using namespace std;
map<pair<long long,long long>,long long>mp[64];
long long f(int k,long long n,long long m)
{
	//n+m<=1LL<<k
	if(m==0||n==0)return 0LL;
	if(mp[k].find(make_pair(n,m))!=mp[k].end())return mp[k][make_pair(n,m)];
	long long ret;
	const long long mid=1LL<<k-1;
	if(mid<=n)ret=m-f(k-1,n-mid,m);
	else if(n+m<=mid)ret=f(k-1,n,m);
	else if(m<=mid)
	{
		ret=f(k-1,n,mid-n);
		ret+=(m-(mid-n))-f(k-1,mid-n,m-(mid-n));
	}
	else
	{
		ret=f(k-1,n,mid-n);
		ret+=n-f(k-1,mid-n,n);
		ret+=f(k-1,n,m-mid);
	}
	return mp[k][make_pair(n,m)]=ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		long long N,M;
		cin>>N>>M;
		cout<<f(61,N,M)<<"\n";
	}
}