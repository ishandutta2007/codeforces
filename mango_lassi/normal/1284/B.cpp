#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = (int)1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	ll asc = 0;

	vector<int> mins, maxs;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;

		bool is_asc = false;
		int minv = INF;
		int maxv = -INF;
		for (int j = 0; j < k; ++j) {
			int v;
			cin >> v;
			if (minv < v) is_asc = true;
			minv = min(minv, v);
			maxv = max(maxv, v);
		}
		if (is_asc) ++asc;
		else {
			mins.push_back(minv);
			maxs.push_back(maxv);
		}
	}
	sort(mins.begin(), mins.end());
	sort(maxs.begin(), maxs.end());

	ll m = n - asc;
	ll res = asc * n + m * asc;

	ll b = 0;
	for (int a = 0; a < mins.size(); ++a) {
		while(b < maxs.size() && maxs[b] <= mins[a]) ++b;
		res += m - b;
	}
	cout << res << '\n';
}