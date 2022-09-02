#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

vector<bool> ask(const vector<pair<int, int>>& query) {
	if (query.empty()) return {};

	int qs = query.size();
	cout << "Q " << qs;
	for (auto p : query) {
		cout << ' ' << p.first+1 << ' ' << p.second+1;
	}
	cout << endl;

	vector<bool> ans(qs);
	for (int i = 0; i < qs; ++i) {
		char bit;
		cin >> bit;
		ans[i] = (bit == '1');
	}
	return ans;
}
void answer(const vector<int>& ans) {
	int n = ans.size();
	vector<vector<int>> res(3);
	for (int i = 0; i < n; ++i) res[ans[i]].push_back(i);
	
	cout << "A " << res[0].size() << ' ' << res[1].size() << ' ' << res[2].size() << endl;
	for (int j = 0; j < 3; ++j) {
		for (auto i : res[j]) cout << i+1 << ' '; cout << endl;
	}
}

bool solve() {
	int n;
	cin >> n;
	if (n == -1) return false;

	vector<bool> flip(n, false);

	// First Query
	vector<pair<int, int>> q1;
	for (int i = 0; i+1 < n; i += 2) {
		q1.push_back({i, i+1});
	}
	vector<bool> ans1 = ask(q1);
	for (int j = 0; j < q1.size(); ++j) flip[2*j] = ans1[j];

	// Second Query
	vector<pair<int, int>> q2;
	for (int i = 1; i+1 < n; i += 2) {
		q2.push_back({i, i+1});
	}
	vector<bool> ans2 = ask(q2);
	for (int j = 0; j < q2.size(); ++j) flip[2*j+1] = ans2[j];

	/*
	cerr << "flips:" << endl;
	for (int i = 0; i < n; ++i) cerr << flip[i]; cerr << endl;
	*/

	// Find components
	vector<int> inds = {0};
	for (int i = 0; i < n; ++i) {
		if (! flip[i]) inds.push_back(i+1);
	}
	int m = (int)inds.size() - 1;
	vector<bool> jump(m, false);

	/*
	cerr << "inds: ";
	for (auto i : inds) cerr << i << ' '; cerr << endl;
	*/

	// Third Query
	vector<pair<int, int>> q3;
	for (int j = 0; j+2 < m; ++j) {
		if (j % 4 >= 2) continue;
		q3.push_back({inds[j], inds[j+2]});
	}
	vector<bool> ans3 = ask(q3);
	for (int j = 0; j < q3.size(); ++j) jump[(j+1)/2 + 3*(j/2)] = ans3[j];

	// Fourth Query
	vector<pair<int, int>> q4;
	for (int j = 0; j+2 < m; ++j) {
		if (j % 4 < 2) continue;
		q4.push_back({inds[j], inds[j+2]});
	}
	vector<bool> ans4 = ask(q4);
	for (int j = 0; j < q4.size(); ++j) jump[2 + (j+1)/2 + 3*(j/2)] = ans4[j];
	
	/*
	cerr << "jumps: " << endl;
	for (int i = 0; i < m; ++i) cerr << jump[i]; cerr << endl;
	*/

	// Build Answer
	vector<int> ans(n, 0);
	if (m == 1) {
		answer(ans);
	} else {
		int v1 = 0;
		int v2 = 1;
		for (int i = inds[0]; i < inds[1]; ++i) ans[i] = v1;
		for (int i = inds[1]; i < inds[2]; ++i) ans[i] = v2;

		for (int j = 2; j < m; ++j) {
			int v3;
			if (jump[j-2]) v3 = v1;
			else v3 = 3 - v1 - v2;
			v1 = v2;
			v2 = v3;

			for (int i = inds[j]; i < inds[j+1]; ++i) ans[i] = v2;
		}
		answer(ans);
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		bool fail = ! solve();
		if (fail) break;
	}
}