#include <bits/stdc++.h>
using namespace std;
long long x, y, l, r, a[10000], o;
int n;
inline long long mul(long long x, long long y)
{
	return x <= r / y ? x * y : r + 1;
}
int main()
{
	scanf("%lld%lld%lld%lld", &x, &y, &l, &r);
	for (long long i = 1; i <= r; i = mul(i, x))
		for (long long j = 1; i + j <= r; j = mul(j, y))
			if (i + j >= l)
				a[++ n] = i + j;
	sort(a + 1, a + n + 1);
	n = unique(a + 1, a + n + 1) - a - 1;
	a[0] = l - 1, a[n + 1] = r + 1;
	for (int i = 0; i <= n; i++)
		o = max(o, a[i + 1] - a[i] - 1);
	cout << o;
	return 0;
}