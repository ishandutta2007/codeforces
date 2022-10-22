#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,l,r;
int main()
{
	scanf("%lld%lld%lld",&n,&l,&r);
	ll msum=0,nsum=0;
	ll step=1;
	for(ll i=1;i<=r;i++)
	{
		msum+=step;
		step*=2;
	}
	step/=2;
	msum+=(n-r)*step;
	step=1;
	for(ll i=1;i<=l;i++)
	{
		nsum+=step;
		step*=2;
	}
	nsum+=(n-l);
	printf("%lld %lld\n",nsum,msum);
	return 0;
}