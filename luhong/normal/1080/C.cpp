#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <set> 
#define MN 501000

typedef long long ll;

ll S(ll x1, ll y1)
{
	ll s = x1 * y1 / 2;
	return s;
}

ll solve(ll x1, ll y1, ll x2, ll y2)
{
	return S(x2, y2) - S(x1 - 1, y2) - S(x2, y1 - 1) + S(x1 - 1, y1 - 1);
}

int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		ll n, m; scanf("%lld%lld", &n, &m);
		ll x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		x5 = std::max(x1, x3), y5 = std::max(y1, y3);
		x6 = std::min(x2, x4), y6 = std::min(y2, y4);
		ll SS = (x4 - x3 + 1) * (y4 - y3 + 1);
		if(x5 > x6 || y5 > y6)
		{
			ll sum = n * m;
			ll b = S(n, m) - solve(x1, y1, x2, y2) - solve(x3, y3, x4, y4) + SS;
			printf("%lld %lld\n", sum - b, b);
		}
		else
		{
			ll sum = n * m;
			ll b = S(n, m) - solve(x1, y1, x2, y2) - solve(x3, y3, x4, y4) + solve(x5, y5, x6, y6) + SS;
			printf("%lld %lld\n", sum - b, b);
		}
	}
	return 0;
}