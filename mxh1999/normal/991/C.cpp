#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll _n;
bool check(ll t)
{
	cerr<<t<<endl;
	ll ans1=0,ans2=0;
	ll n=_n;
	while (n)
	{
		if (n<t)	ans1+=n,n=0;else ans1+=t,n-=t;
		ans2+=n/10;
		n-=n/10;
	}
	return ans1>=ans2;
}
int main()
{
	scanf("%lld",&_n);
	ll l=1,r=(_n+1)/2;
	while (l<r)
	{
		ll mid=(l+r)>>1;
		if (check(mid))	r=mid;else l=mid+1;
	}
	printf("%lld\n",r);
	return 0;
}