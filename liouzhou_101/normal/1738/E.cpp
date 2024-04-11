#include <bits/stdc++.h>

using namespace std;

constexpr long long MOD = 998244353;

long long power(long long a, long long b)
{
	if (b == 0) return 1;
	long long t = power(a, b / 2);
	t = t * t % MOD;
	if (b % 2 == 1) t = t * a % MOD;
	return t;
}

void solve()
{
	int n;
	scanf("%d", &n);
	vector<long long> a(n + 1);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);

	vector<long long> factorial(n + 1, 1), inv_factorial(n + 1, 1);
	for (int i = 1; i <= n; ++i)
	{
		factorial[i] = factorial[i - 1] * i % MOD;
		inv_factorial[i] = inv_factorial[i - 1] * power(i, MOD - 2) % MOD;
	}
	auto choose = [&](int n, int m)
	{
		return factorial[n] * inv_factorial[m] % MOD * inv_factorial[n - m] % MOD;
	};

	function<long long(int, int)> f = [&](int i, int j) -> long long
	{
		int l = i, r = j;
		while (l <= j && a[l] == 0) l += 1;
		while (r >= i && a[r] == 0) r -= 1;
		if (l == j + 1) // all zero
			return power(2, j - i);
		if (i != l && j != r) // both ends have zeros
		{
			int x = l - i, y = j - r;
			long long coef = 0;
			for (int k = 0; k <= min(x, y); ++k)
				coef = (coef + choose(x, k) * choose(y, k)) % MOD;
			return f(l, r) * coef % MOD;
		}
		// at most one end has zeros
		i = l, j = r;
		long long ls = a[i], rs = a[j];
		while (ls != rs)
		{
			if (ls < rs) ls += a[++i]; else rs += a[--j];
		}
		if (i >= j) return 1;
		l = i + 1, r = j - 1;
		while (l <= j && a[l] == 0) l += 1;
		while (r >= i && a[r] == 0) r -= 1;
		if (l == j) // x, zeros, x
			return power(2, j - i);
		// x, zeros, something, zeros, x
		int x = l - i - 1, y = j - r - 1;
		long long coef = 0;
		for (int k = 0; k <= min(x, y) + 1; ++k)
			coef = (coef + choose(x + 1, k) * choose(y + 1, k)) % MOD;
		return f(l, r) * coef % MOD;
	};

	long long res = f(1, n);
	printf("%lld\n", res);
}

int main()
{
	int tests;
	cin >> tests;
	while (tests--) solve();
	return 0;
}