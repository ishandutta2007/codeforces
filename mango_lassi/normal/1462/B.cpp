#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	bool ans = 0;
	for (int i = 0; i <= 4; ++i) {
		bool works = 1;
		for (int j = 0; j < i; ++j) {
			if (str[j] != "2020"[j]) works = 0;
		}
		for (int j = i; j < 4; ++j) {
			if (str[n-4+j] != "2020"[j]) works = 0;
		}
		if (works) ans = 1;
	}
	cout << (ans ? "Yes" : "No") << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}