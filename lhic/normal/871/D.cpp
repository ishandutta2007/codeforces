#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const int MX = (int)1e7 + 100;

int n;
int bb[MX];
int phi[MX];
int cnt[MX];
vector<int> primes;
int cp[MX];

int main() {
#ifdef BZ
	freopen("in", "r", stdin);
#endif
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	phi[1] = 1;
	for (int i = 1; i <= n; ++i)
		bb[i] = i;
	ll ans = 0;
	for (int i = 2; i <= n; ++i) {
		int now = i / bb[i];
		phi[i] = bb[i] - 1;
		while (now % bb[i] == 0)
			now /= bb[i], phi[i] *= bb[i];
		phi[i] *= phi[now];
		cnt[i] = 1 + cnt[now];
		cp[i] = cp[i - 1];
		if (i == bb[i])
			primes.push_back(i), ++cp[i];
		for (int x: primes) {
			if (x > bb[i] || x * i > n)
				break;
			bb[i * x] = x;
		}
		ans += i - 1 - phi[i];
		int lf = phi[i] - 1;
		if (i != bb[i]) {
			ans += 2 * (lf - primes.size() + cnt[i]);
		}
	}
	while (!primes.empty() && primes.back() * 2 > n)
		primes.pop_back();
	for (int i = 2; i <= n; ++i) {
		if (i != bb[i]) {
			int x = cp[n / bb[i]] - cnt[i];
			ans += 2 * x;
			int y = primes.size() - x - cnt[i];
			ans += 3 * y;
		}
	}
	for (int i = 0; i < primes.size(); ++i) {
		int x = cp[min(primes[i] - 1, n / primes[i])];
		ans += 2 * x;
		ans += 3 * (i - x);
	}
	cout << ans << "\n";
	return 0;
}