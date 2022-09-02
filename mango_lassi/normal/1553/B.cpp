#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string str, tar;
	cin >> str >> tar;
	bool works = 0;
	int n = str.size();

	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			string off = "";
			for (int x = i; x < j; ++x) {
				off.push_back(str[x]);
			}
			for (int x = j; x >= 0 && off.size() < tar.size(); --x) {
				off.push_back(str[x]);
			}
			if (off == tar) works = 1;
		}
	}
	if (works) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}