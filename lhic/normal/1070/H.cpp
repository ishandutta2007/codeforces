#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int n;
	cin >> n;
	map<string, pair<int, string>> m;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		set<string> ss;
		for (int j= 0; j < s.length(); ++j) {
			for (int k = 1; k + j <= s.length(); ++k) {
				ss.insert(s.substr(j, k));

			}
		}

		for (auto& sc: ss) {
				auto& val = m[sc];
				++val.first;
				val.second = s;
		}
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string s;
		cin >> s;
		auto it = m.find(s);
		if (it == m.end()) {
			cout << "0 -\n";
		} else {
			cout << it->second.first << " " << it->second.second << "\n";
		}
	}
	return 0;
}