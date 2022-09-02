#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	// A number is K-amazing if all of its occurences have distance at most k to the next occurrence
	// + distances to start and end of the array are small enough

	int n;
	cin >> n;
	vector<vector<int>> apps(n);
	for (int i = 0; i < n; ++i) apps[i].push_back(-1);
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		apps[v-1].push_back(i);
	}
	for (int i = 0; i < n; ++i) apps[i].push_back(n);
	
	vector<pair<int, int>> stack;
	for (int i = 0; i < n; ++i) {
		int k = 0;
		for (int j = 0; j+1 < apps[i].size(); ++j) {
			k = max(k, apps[i][j+1] - apps[i][j]);
		}
		if (stack.empty() || k < stack.back().first) stack.push_back({k, i+1});
	}
	stack.push_back({-1, -1});

	int j = (int)stack.size() - 1;
	for (int k = 1; k <= n; ++k) {
		while(j > 0 && stack[j-1].first <= k) --j;
		cout << stack[j].second << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();


	
}