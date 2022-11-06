#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		ll l, r;
		scanf("%lld%lld", &l, &r);
		ll y = (ll)sqrt(r) , res1 = (y - 1) * 3 ;
	    if (y * y <= r) ++ res1 ;
	    if (y * y + y <= r) ++ res1 ;
	    if (y * y + 2 * y <= r) ++ res1 ;
		ll x = (ll)sqrt(l - 1) , res2 = (x - 1) * 3 ;
	    if (x * x <= l - 1) ++ res2 ;
	    if (x * x + x <= l - 1) ++ res2 ;
	    if (x * x + 2 * x <= l - 1) ++ res2 ;
	    printf("%lld\n", res1 - res2);
	}

	return 0;
}