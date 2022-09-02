#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int C = 26;

int ind(const string& str, bool r, int t) {
	int mult = 1, res = 0;
	if (! r) {
		for (int i = 0; i < str.size(); ++i) {
			res += (str[i] - 'a') * mult;
			mult *= C;
			--t;
			if (t == 0) break;
		}
	} else {
		for (int i = (int)str.size() - 1; i >= 0; --i) {
			res += (str[i] - 'a') * mult;
			mult *= C;
			--t;
			if (t == 0) break;
		}
	}
	return res;
}

bool solve() {
	int n;
	cin >> n;

	bool found = 0;
	vector<string> strs(n);
	for (auto& str : strs) {
		cin >> str;
		if (str[0] == str.back()) found = 1;
	}
	if (found) return true;

	vector<int> cou2(C*C, 0), cou32(C*C, 0), cou33(C*C*C, 0);
	for (int i = 0; i < n; ++i) {
		if (strs[i].size() == 2) {
			++cou2[ind(strs[i], 0, 2)];
		} else {
			++cou32[ind(strs[i], 0, 2)];
			++cou33[ind(strs[i], 0, 3)];
		}
	}
	for (int i = n-1; i >= 0; --i) {
		if (strs[i].size() == 2) {
			int id = ind(strs[i], 1, 2);
			if (cou2[id] > 0 || cou32[id] > 0) return true;
		} else {
			int id2 = ind(strs[i], 1, 2);
			if (cou2[id2] > 0) return true;
			int id3 = ind(strs[i], 1, 3);
			if (cou33[id3] > 0) return true;
		}
		if (strs[i].size() == 2) {
			--cou2[ind(strs[i], 0, 2)];
		} else {
			--cou32[ind(strs[i], 0, 2)];
			--cou33[ind(strs[i], 0, 3)];
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		bool res = solve();
		cout << (res ? "YES" : "NO") << '\n';
	}
}