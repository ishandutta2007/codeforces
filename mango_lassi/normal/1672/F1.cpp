#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	// Answer is "n - max_v #occurrences of v"?
	// Lower bound: make cycle of one occurence of every value that occurs the most times
	// Upper bound: proof by AC?

	vector<pair<int, vector<int>>> apps(n + 1);
	for (int i = 0; i < n; ++i) {
		++apps[as[i]].first;
		apps[as[i]].second.push_back(i);
	}
	sort(apps.rbegin(), apps.rend());

	vector<int> res(n, -1);
	while(apps[0].first > 0) {
		int v = apps[0].first;
		vector<int> inds;
		for (int j = 0; apps[j].first == v; ++j) {
			--apps[j].first;
			inds.push_back(apps[j].second.back());
			apps[j].second.pop_back();
		}
		for (int i = 0; i < inds.size(); ++i) {
			int j = inds[(i + 1) % inds.size()];
			res[inds[i]] = as[j];
		}
	}

	for (int v : res) cout << v << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}