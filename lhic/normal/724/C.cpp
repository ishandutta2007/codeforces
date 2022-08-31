#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

ll n, m;
ll gc;
ll gcd(ll a, ll b) {
	while (b) {
		ll q = a % b;
		a = b;
		b = q;
	}
	return a;
}
ll INF;
ll nm1;
ll mm1;

ll get(ll x, ll y) {
	if (x % gc != y % gc)
		return INF;
	x %= n;
	y %= m;
	ll mod = n * m;
	ll ans = (x * mm1 * m + y * nm1 * n) % mod;
	return ans;
}

int k;

const int MAXN = 120000;
ll x[MAXN];
ll y[MAXN];

int main() {
	scanf("%lld%lld%d", &n, &m, &k);
	ll n2 = 2 * n;
	ll m2 = 2 * m;
	gc = gcd(n2, m2);
	n *= 2;
	m *= 2;
	for (int i = 2; i <= n; ++i) {
		if (n % i == 0 && m % i == 0) {
			int c0 = 0;
			ll tmp = n;
			while (tmp % i == 0)
				tmp /= i, ++c0;
			int c1 = 0;
			tmp = m;
			while (tmp % i == 0)
				tmp /= i, ++c1;
			if (c0 > c1) {
				while (m % i == 0)
					m /= i;
			}
			else {
				while (n % i == 0)
					n /= i;
			}
		}
	}
	for (int i = 1; i < m; ++i)
		if ((n * i) % m == 1) {
			nm1 = i;
		}
	for (int i = 1; i < n; ++i)
		if ((m * i) % n == 1) {
			mm1 = i;
		}

	for (int i = 0; i < k; ++i)
		scanf("%lld%lld", x + i, y + i);
	INF = 4 * n * m;
	for (int i = 0; i < k; ++i) {
		ll mn = INF;
		mn = min(mn, get(x[i], y[i]));
		mn = min(mn, get(n2 - x[i], y[i]));
		mn = min(mn, get(x[i], m2 - y[i]));
		mn = min(mn, get(n2 - x[i], m2 - y[i]));
		if (mn < INF)
			printf("%lld\n", mn);
		else
			printf("-1\n");
	}
	return 0;
}