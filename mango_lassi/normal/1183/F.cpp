#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

bool bins(const vector<int>& vec, int v) {
	int low = 0;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return vec[low] == v;
}

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];

	// Greedy works in all cases but when a=2*3*x, b=3*5*x, c=5*2*x
	// First handle that case
	sort(as.begin(), as.end());
	as.erase(unique(as.begin(), as.end()), as.end());

	int res = 0;
	for (auto a : as) {
		if (a % 6 == 0) {
			int x = a / 6;
			if (bins(as, 10*x) && bins(as, 15*x)) {
				res = max(res, 31*x);
			}
		}
	}

	// Then get answer from greedy
	reverse(as.begin(), as.end());

	vector<int> vals;
	for (auto a : as) {
		bool works = true;
		for (auto v : vals) {
			if (v % a == 0) works = false;
		}
		if (works) vals.push_back(a);
		if (vals.size() >= 3) break;
	}
	int off = 0;
	for (auto v : vals) off += v;
	res = max(res, off);

	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}