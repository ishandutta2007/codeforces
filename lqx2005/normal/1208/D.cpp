#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=200000;
ll n;
ll s[N+5],p[N+5];
ll t[N+5];
ll lowbit(ll x)
{
	return x&(-x);
}
void Add(ll x,ll v)
{
	for(ll i=x;i<=n;i+=lowbit(i)) t[i]+=v;
	return ;
}
ll Sum(ll x)
{
	ll sum=0;
	for(ll i=x;i>=1;i-=lowbit(i)) sum+=t[i];
	return sum;
}
ll find(ll x)
{
	ll l=1,r=n,best=0;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(Sum(mid)<=x) best=mid,l=mid+1;
		else r=mid-1;
	}
	return best;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&s[i]);
	for(ll i=1;i<=n;i++) Add(i,i);
	for(ll i=n;i>=1;i--)
	{
		ll now=find(s[i])+1;
		p[i]=now;
		Add(now,-now);
	}
	for(ll i=1;i<=n;i++) printf("%lld ",p[i]);
	printf("\n");
	return 0;
}