#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll modInv(ll a, ll b = MOD-2) {
	if (b & 1) return a*modInv(a, b-1) % MOD;
	else if (b == 0) return 1;
	else return modInv(a*a % MOD, b/2);
}
pair<ll, ll> intersect(pair<ll, ll> a, pair<ll, ll> b) {
	return {max(a.first, b.first), min(a.second, b.second)};
}
ll intLen(pair<ll, ll> it) {
	return max(it.second - it.first + 1, 0ll);
}

const int N = 2 * (int)1e5;
pair<ll, ll> its[N];

ll sameProb(int a, int b) {
	ll div = 1;
	pair<ll, ll> cans = {1, INF};
	for (int i = a; i <= b; ++i) {
		div = div * intLen(its[i]) % MOD;
		cans = intersect(cans, its[i]);
	}
	ll res = intLen(cans) * modInv(div) % MOD;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> its[i].first;
	for (int i = 0; i < n; ++i) cin >> its[i].second;

	ll sum = 1;
	vector<ll> exps(n, 0);
	for (int i = 0; i+1 < n; ++i) {
		exps[i] = (1 - sameProb(i, i+1)) % MOD;
		sum = (sum + exps[i]) % MOD;
	}
	
	ll res = sum * sum % MOD;

	// Subtract wrong terms
	for (int i = 0; i < n; ++i) {
		res = (res - exps[i]*exps[i]) % MOD;
		if (i+2 < n) {
			res = (res - 2 * exps[i] * exps[i+1]) % MOD;
		}
	}

	// Add correct replacements
	for (int i = 0; i < n; ++i) {
		res = (res + exps[i]) % MOD;
		if (i+2 < n) {
			ll term = (1 - sameProb(i, i+1) - sameProb(i+1, i+2) + sameProb(i, i+2)) % MOD;
			res = (res + 2 * term) % MOD; // Fix back-to-back terms
		}
	}
	if (res < 0) res += MOD;
	cout << res << '\n';
}