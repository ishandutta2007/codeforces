#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int H = 60;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		int n;
		ll t;
		cin >> t >> n;

		ll s = 0;
		vector<ll> cou(H);
		for (int i = 0; i < n; ++i) {
			ll v;
			cin >> v;
			s += v;

			int j = 0;
			while((1ll << j) < v) ++j;
			++cou[j];
		}

		if (s < t) {
			cout << -1 << '\n';
			continue;
		}

		ll sub = 0;
		int res = 0;
		for (int i = 0; (1ll << i) <= t; ++i) {
			ll bit = (1ll << i);
			sub += cou[i] * bit;
			if (t & bit) {
				if (sub >= bit) sub -= bit;
				else {
					for (int j = i+1; j < H; ++j) {
						if (cou[j] > 0) {
							res += j - i;
							--cou[j];
							sub += (1ll << j) - bit;
							break;
						}
					}
				}
			}
		}
		cout << res << '\n';
	}
}