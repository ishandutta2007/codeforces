#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = (ll)1e9 + 7;

const int N = 1e5;
int cou[N+1];

ll modPow(ll a, ll b) {
	if (b == 0) return 1;
	if (b & 1) return (a * modPow(a, b-1)) % MOD;
	ll sub = modPow(a, b / 2);
	return (sub * sub) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	string str;
	cin >> str;

	cou[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cou[i] = cou[i-1];
		if (str[i-1] == '1') ++cou[i];
	}

	for (int j = 0; j < q; ++j) {
		int l, r;
		cin >> l >> r;
		--l;

		ll ones = cou[r] - cou[l];
		ll nils = r-l - ones;
	
		// Always eat ones first
		ll mult = modPow(2, ones) - 1;
		if (mult < 0) mult += MOD;
		ll res = (modPow(2, nils) * mult) % MOD;

		cout << res << '\n';
	}
}