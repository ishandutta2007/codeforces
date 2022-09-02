#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int ask(const vector<int>& vec) {
	cout << "? " << vec.size();
	for (auto v : vec) cout << " " << v;
	cout << endl;

	int res;
	cin >> res;
	return res;
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> groups(k);
	for (int i = 0; i < k; ++i) {
		int m;
		cin >> m;
		groups[i].resize(m);
		for (int j = 0; j < m; ++j) cin >> groups[i][j];
	}

	// Get maximum (1 move)
	vector<int> query(n);
	for (int i = 0; i < n; ++i) query[i] = i+1;
	int mx = ask(query);

	// Find group containing maximum (log n <= 10 moves)
	int a = 0;
	int b = k-1;
	while(a != b) {
		int mid = (a + b) >> 1;
		
		query.clear();
		for (int gi = a; gi <= mid; ++gi) {
			for (auto i : groups[gi]) query.push_back(i);
		}
		if (ask(query) >= mx) b = mid;
		else a = mid + 1;
	}

	// Find maximum not in that group
	vector<bool> act(n, 1);
	for (auto i : groups[a]) act[i-1] = 0;

	query.clear();
	for (int i = 0; i < n; ++i) {
		if (act[i]) query.push_back(i+1);
	}
	int oth_mx = ask(query);

	// Answer
	cout << "!";
	for (int i = 0; i < k; ++i) {
		if (i == a) cout << ' ' << oth_mx;
		else cout << ' ' << mx;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();

		string ans;
		cin >> ans;
	}
}