#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void buildShort(vector<pair<char, int>> act, int n) {
	vector<int> res;
	int low = 0;
	while(! act.empty()) {
		auto pr = act.back();
		act.pop_back();
		if (pr.first == '<') {
			for (int j = pr.second + 1; j > 0; --j) res.push_back(low + j);
			low += pr.second + 1;
		} else {
			if (res.empty()) {
				res.push_back(1);
				++low;
			}
			for (int j = 1; j < pr.second; ++j) res.push_back(low + j);
			low += pr.second - 1;
		}
	}
	if (res.size() < n) res.push_back(n);
	for (int i = n-1; i >= 0; --i) cout << res[i] << ' '; cout << '\n';
}

void buildLong(vector<pair<char, int>> act, int n) {
	vector<int> res;
	int high = n+1;
	while(! act.empty()) {
		auto pr = act.back();
		act.pop_back();
		if (pr.first == '>') {
			for (int j = pr.second + 1; j > 0; --j) res.push_back(high - j);
			high -= pr.second + 1;
		} else {
			if (res.empty()) {
				res.push_back(n);
				--high;
			}
			for (int j = 1; j < pr.second; ++j) res.push_back(high - j);
			high -= pr.second - 1;
		}
	}
	if (res.size() < n) res.push_back(1);
	for (int i = n-1; i >= 0; --i) cout << res[i] << ' '; cout << '\n';
}

void solve() {
	int n;
	cin >> n;
	string cmp;
	cin >> cmp;

	vector<pair<char, int>> act = {{cmp[0], 1}};
	for (int i = 1; i < n-1; ++i) {
		if (cmp[i] == act.back().first) ++act.back().second;
		else act.push_back({cmp[i], 1});
	}

	buildShort(act, n);
	buildLong(act, n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}