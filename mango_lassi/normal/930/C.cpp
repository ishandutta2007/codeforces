#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int M = 10 + (1e5);
const int inf = 1e9;
int cou[M];
int incr[M];
int decr[M];

int bin(vector<int>& vec, int val) {
	int low = 0;
	int high = vec.size() - 1;
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] <= val) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> evs;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		evs.push_back({a, 1});
		evs.push_back({b+1, -1});
	}
	sort(evs.begin(), evs.end());
	int val = 0;
	int px = 0;
	for (int i = 0; i < evs.size(); ++i) {
		int x = evs[i].first;
		for (int j = px; j < x; ++j) {
			cou[j] = val;
		}
		val += evs[i].second;
		px = x;
	}
	for (int j = px; j < m; ++j) {
		cou[j] = val;
	}
	// for (int i = 0; i < m; ++i) cout << cou[i] << ' '; cout << '\n';

	vector<int> help (m+1);
	for (int j = 1; j <= m; ++j) help[j] = inf;
	val = 0;
	for (int i = 0; i < m; ++i) {
		help[bin(help, cou[i])] = cou[i];
		if (help[val + 1] < inf) ++val;
		incr[i] = val;
	}
	for (int j = 1; j <= m; ++j) help[j] = inf;
	val = 0;
	for (int i = m-1; i >= 0; --i) {
		help[bin(help, cou[i])] = cou[i];
		if (help[val + 1] < inf) ++val;
		decr[i] = val;
	}
	int res = 0;
	for (int i = 0; i < m; ++i) {
		res = max(res, incr[i] + decr[i+1]);
	}
	cout << res << '\n';
}