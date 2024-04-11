#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void flip(int h, vector<int>& as, vector<int>& res) {
	res.push_back(h + 1);
	for (int i = 0; i < h-i; ++i) swap(as[i], as[h-i]);
} 
int ind(int a, vector<int>& as) {
	for (int i = 0; i < as.size(); ++i) {
		if (as[i] == a) return i;
	}
	return -1;
}

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) {
		cin >> a;
		--a;
	}

	// Odd positions stay in odd position, even in even positions
	// n even -> last value must be n

	bool fail = 0;
	for (int i = 0; i < n; ++i) {
		if ((as[i] & 1) != (i & 1)) fail = 1;
	}
	if ((n % 2) == 0 && as[n-1] != n-1) fail = 1;

	if (fail) {
		cout << -1 << '\n';
	} else {
		// Flip max odd and max even to end in 5 ops
		// 1 2 a 4 5 b 7 8 9 x x x x x x
		// a 2 1 4 5 b 7 8 9 x x x x x x
		// 5 4 1 2 a b 7 8 9 x x x x x x
		// 7 b a 2 1 4 5 8 9 x x x x x x
		// a b 7 2 1 4 5 8 9 x x x x x x
		// 9 8 5 4 1 2 7 b a x x x x x x

		vector<int> res;
		for (int h = n - 1 - ((n % 2) == 0); h > 1; h -= 2) {
			int x = ind(h, as);
			if (x > 1) flip(x, as, res);
			int y = ind(h-1, as);
			if (y > 2) {
				flip(y-1, as, res);
				flip(y+1, as, res);
				flip(2, as, res);
			}
			flip(h, as, res);
		}
		cout << res.size() << '\n';
		for (int v : res) cout << v << ' '; cout << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}