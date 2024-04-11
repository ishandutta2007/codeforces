#include<bits/stdc++.h>
#define ll long long
const int const1 = 998244353;
int qw(ll x, ll y)
{
	printf("%lld %lld\n", x, y);
	fflush(stdout);
	int a;
	scanf("%ld", &a);
	if(a == 0)
	{
		exit(0);
	}
	return a;
}
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	ll n;
	scanf("%lld", &n);
	ll xl, xm, xr, yl, ym, yr;
	xl = 1, xm = n + 1, xr = n + 1, yl = 1, ym = n + 1, yr = n + 1;
	while(xm - xl > 1 || xr - xm > 0 || ym - yl > 1 || yr - ym > 0)
	{
		long double f1 = (long double) (xm - xl) * (ym - yl);
		long double f3 = (long double) (xr - xm) * (ym - yl);
		long double f2 = (long double) (xm - xl) * (yr - ym);
		if(f2 > f1 + f3)
		{
			int e = qw((xl + xm) / 2, ym);
			if(e == 2)
			{
				yl = ym + 1;
				xr = xm;
				ym = yr;
			}
			else if(e == 1)
			{
				xl = (xl + xm) / 2 + 1;
			}
			else
			{
				xm = (xl + xm) / 2;
			}
		}
		else if(f3 > f1 + f2)
		{
			int e = qw(xm, (yl + ym) / 2);
			if(e == 1)
			{
				xl = xm + 1;
				yr = ym;
				xm = xr;
			}
			else if(e == 2)
			{
				yl = (yl + ym) / 2 + 1;
			}
			else
			{
				ym = (yl + ym) / 2;
			}
		}
		else
		{
			int e = qw((xl + xm) / 2, (yl + ym) / 2);
			if(e == 1)
			{
				xl = (xl + xm) / 2 + 1;
			}
			else if(e == 2)
			{
				yl = (yl + ym) / 2 + 1;
			}
			else
			{
				xm = (xl + xm) / 2;
				ym = (yl + ym) / 2;
			}
		}
	}
	qw(xl, yl);
	return 0;
}