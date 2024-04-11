#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 998244353;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ull kthPow(ull v, ll k) {
	ull res = 1;
	for (int i = 0; i < k; ++i) res *= v;
	return res;
}

// Works for k = 2, 3
ll kthRoot(ll v, ll k) {
	ull low = 1;
	ull high = (ull)1 << (63 / k);
	while(low != high) {
		ull mid = (low + high) >> 1;
		if (kthPow(mid, k) < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

int main() {
	unordered_map<ll, int> counts;
	unordered_map<ll, int> oths;
	
	int n;
	cin >> n;

	vector<ll> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];

	for (int i = 0; i < n; ++i) {
		ll v = vals[i];
		ll rt2 = kthRoot(v, 2);
		ll rt3 = kthRoot(v, 3);
		ll rt4 = kthRoot(rt2, 2);
		if (kthPow(rt4, 4) == v) counts[rt4] += 4;
		else if (kthPow(rt3, 3) == v) counts[rt3] += 3;
		else if (kthPow(rt2, 2) == v) counts[rt2] += 2;
		else {
			ll div = 1;
			for (auto r : vals) {
				ll gd = gcd(r, v);
				if (gd != 1 && gd != v) div = gd;
			}
			if (div == 1) ++oths[v];
			else {
				++counts[v / div];
				++counts[div];
			}
		}
	}

	ll res = 1;
	for (auto pr : counts) res = (res * (pr.second + 1)) % MOD;
	for (auto pr : oths) res = (res * (pr.second + 1)) % MOD;
	for (auto pr : oths) res = (res * (pr.second + 1)) % MOD;
	cout << res << '\n';
}