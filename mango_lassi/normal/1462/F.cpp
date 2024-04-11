#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// returns number of elements strictly smaller than v in vec
template<class T>
int bins(const vector<T>& vec, T v) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

void solve() {
	int n;
	cin >> n;

	vector<int> starts(n), ends(n);
	vector<pair<int, int>> itvs(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		starts[i] = a;
		ends[i] = b;
		itvs[i] = {a, b};
	}
	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());

	// Count = start before end - end before start
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int off = bins(starts, itvs[i].second + 1) - bins(ends, itvs[i].first);
		res = max(res, off);
	}
	cout << n - res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}