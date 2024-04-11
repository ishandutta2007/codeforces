#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isCentral(int y, int x, int n) {
	return (y > 0 && y < n-1 && x > 0 && x < n-1);
}

void solve() {
	int n;
	cin >> n;

	bool central = 0;
	vector<int> cou(4, 0);
	vector<int> ys(3), xs(3);
	for (int i = 0; i < 3; ++i) {
		cin >> ys[i] >> xs[i];
		--ys[i]; --xs[i];
		cou[(xs[i] % 2) + 2 * (ys[i] % 2)] += 1;
		central |= isCentral(ys[i], xs[i], n);
	}

	int ty, tx;
	cin >> ty >> tx;
	--ty; --tx;

	if (cou[(tx % 2) + 2 * (ty % 2)] == 0) {
		cout << "NO\n";
	} else if (central) {
		cout << "YES\n";
	} else {
		int sy = 0, sx = 0;
		for (int i = 0; i < 3; ++i) {
			if (ys[i] == ty) ++sy;
			if (xs[i] == tx) ++sx;
		}
		if (sy >= 2 || sx >= 2) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}