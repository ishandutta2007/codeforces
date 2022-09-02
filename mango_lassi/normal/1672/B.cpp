#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string tar;
	cin >> tar;

	bool works = 1;
	int ac = 0, bc = 0;
	for (int i = 0; i < tar.size(); ++i) {
		if (tar[i] == 'A') ++ac;
		if (tar[i] == 'B') ++bc;
		works &= (ac >= bc);
	}
	works &= (tar.back() == 'B');
	
	cout << (works ? "YES" : "NO") << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}