#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = (int)1e9 + 7;

bool check(vector<int> vals, int n, int m, int k) {
	// Persuade at most k people
	// It doesn't matter which k before your pick you persuade
	// You might have to pick between
	//	V[a+c] and V[n-1-b]
	//	V[0 + (a+c)] and V[(n-1) - (a)]
	//	...
	//	V[a] and V[(n-1-b) - c]
	int cur = 0;
	vector<int> act(m);
	for (int i = 0; i < m; ++i) {
		int v = vals[i] | vals[n-m+i];
		if (v == 1) ++cur;
		else cur = 0;
		if (cur >= m-k) return true;
	}
	return false;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	k = min(k, m-1);

	vector<int> els(n);
	for (int& v : els) cin >> v;

	int low = 0;
	int high = INF;
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		vector<int> tmp(n);
		for (int i = 0; i < n; ++i) tmp[i] = (els[i] >= mid);
		if (check(tmp, n, m, k)) low = mid;
		else high = mid - 1;
	}
	cout << low << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		solve();
	}
}