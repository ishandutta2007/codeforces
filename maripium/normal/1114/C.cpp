#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(ll n, ll p) {
	ll ans = 0;
	while (n) {
		n /= p;
		ans += n;
	}
	return ans;
}

int main() {
	ll n, b;
	cin >> n >> b;
	vector<pair<ll, int>> facs;
	for (ll i = 2; i * i <= b; ++i) {
		if (b % i == 0) {
			int cnt = 0;
			while (b % i == 0) {
				b /= i;
				++cnt;
			}
			facs.push_back(make_pair(i, cnt));
		}
	}
	if (b > 1) {
		facs.push_back(make_pair(b, 1));
	}
	ll ans = 1e18;
	for (auto p : facs) {
		ans = min(ans, calc(n, p.first) / p.second);
	}
	cout << ans << '\n';
}