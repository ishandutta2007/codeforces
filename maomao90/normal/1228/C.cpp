#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

ll x, n, ans = 1;
bool prime[MAXN];

ll fastExp(ll b, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = res * b % MOD;
		b = b * b % MOD;
		p >>= 1;
	}
	return res;
}

int main() {
	scanf("%lld%lld", &x, &n);
	for (ll i = 2; i * i <= x; i++) {
		prime[i] = 1;
	}
	for (ll i = 2; i * i <= x; i++) {
		if (!prime[i]) continue;
		for (ll j = i * i; j * j <= x; j += i) {
			prime[j] = 0;
		}
	}
	ll cur = x;
	for (ll i = 2; i * i <= x; i++) {
		if (!prime[i]) continue;
		if (x % i != 0) continue;
		ll pw = i;
		while (pw <= n) {
			ll times = n / pw;
			ans = ans * fastExp(i, times) % MOD;
			if (pw > (n / i) + 1) break;
			pw *= i;
		}
		while (cur % i == 0) cur /= i;
	}
	if (cur != 1) {
		ll pw = cur;
		while (pw <= n) {
			ll times = n / pw;
			ans = ans * fastExp(cur, times) % MOD;
			if (pw > (n / cur) + 1) break;
			pw *= cur;
		}
	}
	printf("%lld\n", ans);
	return 0;
}