#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b-1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

vector<int> factor(int v) {
	vector<int> res;
	for (int i = 2; i*i <= v; ++i) {
		if (v % i == 0) {
			res.push_back(i);
			while(v % i == 0) v /= i;
		}
	}
	if (v > 1) res.push_back(v);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x;
	ll n;
	cin >> x >> n;

	vector<int> divs = factor(x);
	ll res = 1;
	for (auto p : divs) {
		ll pw = 0;
		for (ll tmp = n / p; tmp > 0; tmp /= p) pw += tmp;
		res = res * modPow(p, pw) % MOD;
	}
	cout << res << '\n';
}