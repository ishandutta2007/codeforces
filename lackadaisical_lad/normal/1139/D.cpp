// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

ll binpow(ll a, int p) {
	ll r = 1;
	while (p) {
		if (p & 1) {
			(r *= a) %= mod;
		}
		p >>= 1;
		(a *= a) %= mod;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> m;
	vector<ll> dp(m + 1);
	ll ans = 0;
	ll q = binpow(m, mod - 2);
	for (int i = 2; i <= m; i++) {
		// dp[i] = 1 + sum(dp[gcd] * cnt[gcd]) / m
		ll a = m / i;
		ll b = 0;
		
		vector<int> divs;
		for (int d = 1; d * d <= i; d++) {
			if (i % d) continue;
			divs.push_back(d);
			if (d * d != i) {
				divs.push_back(i / d);
			}
		}
		sort(divs.begin(), divs.end());
		for (int j = (int)divs.size() - 2; j >= 0; j--) {
			ll cnt = m / divs[j];
			vector<ll> coef(divs.size(), 1);
			for (int k = j + 1; k < divs.size(); k++) {
				if (divs[k] % divs[j]) continue;
				cnt -= m / divs[k] * coef[k];
				for (int l = k + 1; l < divs.size(); l++) {
					if (divs[l] % divs[k]) continue;
					coef[l] -= coef[k];
				}
			}
			(b += dp[divs[j]] * cnt) %= mod;
		}

		a = a * q % mod;
		b = (b * q + 1) % mod;
		dp[i] = b * binpow(1 - a + mod, mod - 2) % mod;
		(ans += dp[i]) %= mod;
	}
	ans = ans * q % mod;
	cout << (1 + ans) % mod << endl;
	return 0;
}