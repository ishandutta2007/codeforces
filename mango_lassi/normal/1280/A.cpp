#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;

void solve() {
	int x;
	cin >> x;
	string str;
	cin >> str;

	ll n = str.size();
	for (int i = 1; i <= x; ++i) {
		int k = (str[i-1] - '0');
		if (str.size() >= x) {
			n = (n + (n - i) * (k - 1)) % MOD;
			if (n < 0) n += MOD;
		} else {
			for (int j = 0; j < k-1; ++j) {
				for (int t = i; t < n; ++t) {
					str.push_back(str[t]);
				}
			}
			n = str.size() % MOD;
		}
	}
	cout << n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}