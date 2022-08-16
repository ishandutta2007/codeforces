#include <bits/stdc++.h>

using namespace std;

int64_t power(int64_t a, int64_t b, int64_t p)
{
	if (!b) return 1;
	int64_t t = power(a, b>>1, p);
	t = t * t % p;
	if (b & 1) t = t * a % p;
	return t;
}

int main()
{
	
	int n, mod;
	cin >> n >> mod;
	vector<int64_t> fact(n+1), rfact(n+1);
	fact[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		fact[i] = fact[i - 1] * i % mod;
	}

	for (int i = 0; i <= n; ++i) rfact[i] = power(fact[i], mod-2, mod);

	auto binom = [&](int n, int m)
	{
		return fact[n] * rfact[m] % mod * rfact[n - m] % mod;
	};


	int64_t ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += int64_t(n - i + 1) * (n-i+1) % mod * fact[i] % mod * fact[n-i] % mod;
		ans %= mod;
		//cout << ans << endl;
	}
	cout << ans << endl;

	return 0;
}