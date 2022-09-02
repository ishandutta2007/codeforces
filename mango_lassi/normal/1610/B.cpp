#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool works(int skip, const vector<int>& as) {
	int n = as.size(), j = n-1;
	for (int i = 0; i < j; ++i) {
		if (as[i] == skip) continue;
		while(j > i && as[j] == skip) --j;

		if (as[i] != as[j]) return false;
		--j;
	}
	return true;
}

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	// Might as well delete al
	// While first and last character are equal, delete them.
	// When they are distinct, try deleting both of the characters

	for (int i = 0; i < n-1-i; ++i) {
		if (as[i] != as[n-1-i]) {
			bool res = works(as[i], as) || works(as[n-1-i], as);
			if (res) cout << "YES\n";
			else cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}