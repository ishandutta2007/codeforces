#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int C = 26;

vector<int> calc(const string& str) {
	vector<int> res(C, 0);
	for (auto c : str) ++res[c - 'a'];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		string p, h;
		cin >> p >> h;
		int n = p.size();
		int m = h.size();
		sort(p.begin(), p.end());

		auto comp = calc(p);

		bool fail = true;
		for (int i = 0; i + n <= m; ++i) {
			string tmp(n, '_');
			for (int j = 0; j < n; ++j) tmp[j] = h[i+j];
			if (calc(tmp) == comp) fail = false;
		}
		if (fail) cout << "NO\n";
		else cout << "YES\n";
	}
}