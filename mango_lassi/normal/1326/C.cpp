#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	ll res = 1;
	ll cur = 0;
	ll sum = 0;
	bool act = 0;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		if (p > n - k) {
			if (act) res = (res * (cur + 1)) % MOD;
			act = 1;
			cur = 0;
			sum += p;
		} else {
			++cur;
		}
	}
	cout << sum << ' ' << res << '\n';
}