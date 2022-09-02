#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 2000;
vector<int> conns[N];
int tar[N];
int val[N];

void build(int i, int d, vector<pair<pair<int, int>, int>>& offs) {
	offs.push_back({{val[i], d}, i});
	for (auto t : conns[i]) build(t, d+1, offs);
}

bool solve(int i) {
	for (auto t : conns[i]) {
		bool sub = solve(t);
		if (! sub) return false;
	}

	vector<pair<pair<int, int>, int>> offs;
	for (auto t : conns[i]) build(t, 0, offs);
	sort(offs.begin(), offs.end());
	
	if (offs.size() < tar[i]) return false;
	if (tar[i] < offs.size()) {
		for (int j = tar[i]; j < offs.size(); ++j) {
			val[offs[j].second] += 1;
		}
		val[i] = offs[tar[i]].first.first + 1;
	} else {
		val[i] = offs.size() + 1;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int r = -1;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p >> tar[i];
		if (p == 0) r = i;
		else conns[p-1].push_back(i);
	}

	bool res = solve(r);
	if (res) {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) cout << val[i] << ' '; cout << '\n';
	} else {
		cout << "NO\n";
	}
}