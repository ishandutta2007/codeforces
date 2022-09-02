#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = (int)1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		cin >> n;

		vector<int> cs(n);
		for (int i = 0; i < n; ++i) cin >> cs[i];
		sort(cs.begin(), cs.end());

		vector<int> counts = {1};
		for (int i = 1; i < n; ++i) {
			if (cs[i] != cs[i-1]) counts.push_back(1);
			else ++counts.back();
		}
		sort(counts.begin(), counts.end());

		// Each count allows at most its value plus one in screens
		int m = counts[0] + 1;
		vector<int> res(m+1, 0);
		for (auto v : counts) {
			// Possible with screens of size x iff
			// v = ax + b(x-1) -> v = ax - b, b <= a
			for (int i = 1; i <= m; ++i) {
				int cou = (v + i-1) / i;
				if (cou * (i-1) > v) res[i] = INF;
				else res[i] += cou;
			}
		}
		int ans = INF;
		for (int i = 1; i <= m; ++i) ans = min(ans, res[i]);
		cout << ans << '\n';
	}
}