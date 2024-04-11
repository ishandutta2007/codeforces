#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// DP: for each index calculate maximum beauty if we end the tour there
	// 	From i to j if j-i = b_j - b_i
	// 	-> b_j - j = b_i - i

	vector<pair<ll, ll>> groups(n);
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		groups[i] = {b-i, b};
	}
	sort(groups.begin(), groups.end());

	ll res = 0;
	for (int i = 0; i < n;) {
		int j = i;
		ll off = 0;
		while(j < n && groups[j].first == groups[i].first) {
			off += groups[j].second;
			++j;
		}
		res = max(res, off);
		i = j;
	}
	cout << res << '\n';
}