#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<char> c(n);
		for (int i = 0; i < n; i++) cin >> c[i];
		int pos = 0;
		while (pos + 1 < n && (c[pos + 1] < c[pos] || (c[pos + 1] <= c[pos] && c[pos + 1] != c[0]))) ++pos;
		for (int i = 0; i <= pos; i++) cout << c[i];
		for (int i = pos; i >= 0; i--) cout << c[i];
		cout << endl;
	}
	return 0;
}