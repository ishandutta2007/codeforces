#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

void update(int i, int v, vector<int>& vals, vector<int>& cou, set<int>& zeroes) {
	--cou[vals[i]];
	if (cou[vals[i]] == 0) zeroes.insert(vals[i]);

	vals[i] = v;

	++cou[v];
	if (cou[v] == 1) zeroes.erase(v);
}

void solve() {
	int n;
	cin >> n;
	vector<int> vals(n);
	for (int& v : vals) cin >> v;

	// While MEX != n, apply operation to vals[MEX]
	// If MEX = n, apply operation to vals[n-1] and forget about it
	// Clearly we make at most two operations per position
	
	vector<int> cou(n+1, 0);
	for (auto v : vals) ++cou[v];
	
	set<int> zeroes;
	for (int i = 0; i <= n; ++i) {
		if (cou[i] == 0) zeroes.insert(i);
	}

	vector<int> ops;
	while(n > 0) {
		int v = *zeroes.begin();
		int i = min(v, n-1);
		ops.push_back(i);
		update(i, v, vals, cou, zeroes);
		if (v == n) --n;
	}
	cout << ops.size() << '\n';
	for (auto i : ops) cout << i+1 << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}