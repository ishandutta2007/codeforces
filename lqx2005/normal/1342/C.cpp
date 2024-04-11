#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,a,b,q,g,t;
ll solve(ll x)
{
	if(x==0) return x;
	ll k=x/b;
	if(k==0) return 0;
	ll sum=(k-1)/(a/g)+1;
	sum*=b;
	sum--;
	if(k%(a/g)==0) sum+=x-k*b+1;
	return x-sum;
}
int main()
{
	scanf("%lld",&t);
	for(int am=1;am<=t;am++)
	{
		scanf("%lld%lld%lld",&a,&b,&q);
		if(a>b) swap(a,b);
		g=__gcd(a,b);
		for(int am=1;am<=q;am++)
		{
			scanf("%lld%lld",&l,&r);
			printf("%lld ",solve(r)-solve(l-1));
		}		
		printf("\n");
	}
	return 0;
}