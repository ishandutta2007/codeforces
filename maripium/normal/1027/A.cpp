#include <bits/stdc++.h>
using namespace std;

bool ok(char c1, char c2) {
	if (c1 == c2) return true;
	if (c1 > c2) swap(c2, c1);
	if (c1 + 2 == c2) return true;
	return false;
}

bool ok(string s) {
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (!ok(s[i], s[n - 1 - i])) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	int tt; cin >> tt;
	while (tt--) {
		int n; string s; cin >> n >> s;
		cout << (ok(s) ? "YES" : "NO") << '\n';
	}
}