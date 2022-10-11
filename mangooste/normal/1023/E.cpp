#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	auto ask = [&](int sx, int sy, int fx, int fy) -> bool {
		if (fx < 0 || fy < 0 || fx >= n || fy >= n) return false;
		if (sx < 0 || sy < 0 || sx >= n || sy >= n) return false;
		cout << "? " << sx + 1 << ' ' << sy + 1 << ' ' << fx + 1 << ' ' << fy + 1 << endl;
		string res;
		cin >> res;
		return res == "YES";
	};

	int x = 0, y = 0;
	string res1;
	while (n - x - 1 + n - y - 1 > n - 1) {
		if (ask(x + 1, y, n - 1, n - 1)) {
			x++;
			res1.push_back('D');
		} else {
			y++;
			res1.push_back('R');
		}
	}

	x = n - 1, y = n - 1;
	string res2;
	while (x + y > n - 1) {
		if (ask(0, 0, x, y - 1)) {
			y--;
			res2.push_back('R');
		} else {
			x--;
			res2.push_back('D');
		}
	}

	reverse(res2.begin(), res2.end());
	cout << "! " << res1 << res2 << endl;
}