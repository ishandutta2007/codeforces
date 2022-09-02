#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int bins(const vector<int>& vec, int v) {
	int low = 0;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> ls(n);
	vector<int> rs(n);
	vector<int> sums(n);
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) cin >> ls[i];
	for (int i = 0; i < n; ++i) cin >> rs[i];
	for (int i = 0; i < n; ++i) sums[i] = -(ls[i] + rs[i]);
	sort(sums.begin(), sums.end());
	sums.erase(unique(sums.begin(), sums.end()), sums.end());
	for (int i = 0; i < n; ++i) ans[i] = bins(sums, -(ls[i] + rs[i])) + 1;

	bool fail = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (ans[j] > ans[i]) --ls[i];
		}
		for (int j = i+1; j < n; ++j) {
			if (ans[j] > ans[i]) --rs[i];
		}
		if (ls[i] != 0 || rs[i] != 0) fail = true;
	}
	if (fail) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (auto v : ans) cout << v << ' '; cout << '\n';
	}
}