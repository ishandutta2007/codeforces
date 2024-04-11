#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int V = (int)1e7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> vals(n);
	for (int& v : vals) cin >> v;

	int res = 0;
	vector<pair<int, int>> ord(n+1);
	vector<int> pref(n+1, 0);
	for (int b = 0; (1 << b) <= 2 * V; ++b) {
		int bit = (1 << b);
		int mask = bit - 1;

		ord[0] = {0, 0};
		for (int i = 0; i < n; ++i) ord[i+1] = {vals[i] & mask, (vals[i] & bit) > 0};
		sort(ord.begin(), ord.end());

		for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] ^ ord[i].second;

		int j = 0;
		for (int i = n; i > 0; --i) {
			while(j < i && ord[j].first + ord[i].first < bit) ++j;
			j = min(j, i);

			if (j > 0) {
				int len = j-1;
				int tog = (ord[i].second & len & 1);
				res ^= bit * (tog ^ pref[j-1]);
			}
			if (j < i) {
				int len = i - j;
				int tog = ((1 ^ ord[i].second) & len & 1);
				res ^= bit * (tog ^ (pref[i-1] ^ pref[j-1]));
			}
		}
	}
	cout << res << '\n';
}