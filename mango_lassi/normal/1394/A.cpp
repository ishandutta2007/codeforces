#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, d, m;
	cin >> n >> d >> m;

	vector<ll> fine = {0}, ban = {0};
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		if (a > m) ban.push_back(a);
		else fine.push_back(a);
	}
	sort(fine.begin(), fine.end());
	sort(ban.begin(), ban.end());

	int fs = (int)fine.size() - 1;
	int bs = (int)ban.size() - 1;
	for (int i = 1; i <= fs; ++i) fine[i] += fine[i-1];
	for (int i = 1; i <= bs; ++i) ban[i] += ban[i-1];

	// Iterate over how many times you get muted

	ll res = 0;
	for (int k = 0; k <= bs; ++k) {
		int rem = bs - k;
		int waste = max(0, max(0, k - 1) * d - rem); // This many that have a <= m are wasted on the days we are muted
		if (waste > fs) break;

		ll off = 0;
		off += fine[fs] - fine[waste];
		off += ban[bs] - ban[bs - k];
		res = max(res, off);
	}
	cout << res << '\n';
}