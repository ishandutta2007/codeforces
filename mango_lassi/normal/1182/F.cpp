#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

pair<ll, pair<ll, ll>> extEuc(ll a, ll b) {
	if (b == 0) return {a, {1, 0}};
	ll k = a/b;
	auto sub = extEuc(b, a-b*k);
	return {sub.first, {sub.second.second, sub.second.first - k * sub.second.second}};
}

// Find out if you can have px = t (mod q), with a <= x <= b,
// and the minimum such x. If none exists, returns -1.
ll minx(ll a, ll b, ll t, ll p, ll gd, ll ip, ll v, ll q) {
	ll mult1 = t / gd;
	if (mult1 * gd != t) return -1;
	ll x = (ll)ip * mult1 % q;

	ll mult2 = ((x-a) - (x < a ? v-1 : 0)) / v;
	x -= mult2 * v;

	if (a <= x && x <= b) return x;
	else return -1;
}

const int N = 1e6;
// Finds a <= x <= b minimizing abs(q - 2(px mod q))
int solve(int a, int b, int p, int q) {
	// Case 1: b-a <= sqrt(q) or gcd(p, q) >= sqrt(q): brute
	// Case 2: they are very much not evenly distributed: (b-a)*p <= q or (b-a)*(q-p) <= q
	// Case 3: loop indexes near q/2, see if they are reachable. One within at most q/N is
	// -> O(sqrt(q)) algo
	auto ee = extEuc(p, q);
	ll gd = ee.first;
	ll ip = ee.second.first % q;
	ll v = q / gd;
	if (ip < 0) ip += q;

	ll len1 = (ll)(b-a) * p;
	ll len2 = (ll)(b-a) * (q-p);

	if (b-a <= N || v <= N) {
		int res = a;
		int res_dist = q;
		for (int i = 0; i <= min(b-a, (int)v); ++i) {
			ll x = a + i;
			ll xp = x*p % q;

			int off_dist = abs(q - 2*xp);
			if (off_dist < res_dist) {
				res = x;
				res_dist = off_dist;
			}
		}
		return res;
	} else if (len1 <= q || len2 <= q) {
		// Either a or b is the answer
		ll xp1 = (ll)a*p % q;
		ll xp2 = (ll)b*p % q;
		if (abs(q - 2*xp1) <= abs(q - 2*xp2)) {
			return a;
		} else {
			return b;
		}
	} else {
		for (int j = 0;; ++j) {
			if ((j+q) & 1) continue;
			ll t1 = (q-j) >> 1;
			ll t2 = (q+j) >> 1;
			ll x1 = minx(a, b, t1, p, gd, ip, v, q);
			ll x2 = minx(a, b, t2, p, gd, ip, v, q);

			if (x1 == -1 && x2 == -1) continue;
			if (x1 == -1) return x2;
			if (x2 == -1) return x1;
			return min(x1, x2);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		p %= q;
		cout << solve(a, b, p, q) << '\n';
	}

}