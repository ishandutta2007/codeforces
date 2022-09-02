#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const ll H = 1e16;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		ll k;
		cin >> n >> k;

		vector<ll> pows = {1};
		while(true) {
			pows.push_back(pows.back() * k);
			if (pows.back() > H) break;
		}
		int m = pows.size();
		vector<int> used(m, 0);

		for (int i = 0; i < n; ++i) {
			ll v;
			cin >> v;
			for (int j = 0; pows[j] <= v && j+1 < pows.size(); ++j) {
				if (v % pows[j+1] != 0) {
					++used[j];
					v -= pows[j];
				}
			}
			if (v != 0) used[0] += 2;
		}
		
		bool fail = false;
		for (auto v : used) {
			if (v > 1) fail = true;
		}
		cout << (fail ? "NO" : "YES") << '\n';
	}
}