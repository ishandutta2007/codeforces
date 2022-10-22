#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=100000;
ll n,s;
ll a[N+5];
bool check(ll x)
{
	ll ans=0;
	for(int i=1;i<=n;i++) 
	{
		if(a[i]<x) return false;
		ans+=a[i]-x;
		if(ans>=s) return true;
	}
	return false;	
}
int main()
{
	scanf("%lld%lld",&n,&s);
	ll mina=1e12;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),mina=min(mina,a[i]);
	ll l=0,r=mina,best=-1;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid)) l=mid+1,best=mid;
		else r=mid-1;
	}
	if(best==-1) printf("-1\n");
	else printf("%lld\n",best);
	return 0;
}