#include <iostream>
using namespace std;


long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long n, m, x, y, a, b;
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &n, &m, &x, &y, &a, &b);
	
	long long g = gcd(a, b);
	a /= g;
	b /= g;


	long long k1 = n / a;
	long long k2 = m / b;
	long long k = min(k1, k2);
	long long xc, yc;

	a *= k;
	b *= k;
	
	x *= 2;
	y *= 2;
	n *= 2;
	m *= 2;
	
	xc = x;
	yc = y;
	if (x < a)
	{
		xc = a;
	}
	if (yc < b)
	{
		yc = b;
	}
	if (x + a > n)
	{
		xc = n - a;
	}
	if (y + b > m)
	{
		yc = m - b;
	}

	long long x1 = (xc - a) / 2, y1 = (yc - b) / 2;
	long long x2 = x1 + a, y2 = y1 + b;

	printf("%I64d %I64d %I64d %I64d", x1, y1, x2, y2);
	return 0;
}