#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline int ask(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
	int res;
	cin >> res;
	assert(res != -1);
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n, 0));
	a[0][0] = 1;

	auto go = [&](int x, int y) {
		for (int d = 1; max(x, y) + d < n; d++)
			a[x + d][y + d] = a[x + d - 1][y + d - 1] ^ ask(x + d - 1, y + d - 1, x + d, y + d) ^ 1;
	};

	go(0, 0);
	for (int i = 1; i < n; i++) {
		if (i > 1) {
			a[i][0] = a[i - 2][0] ^ ask(i - 2, 0, i, 0) ^ 1;
			a[0][i] = a[0][i - 2] ^ ask(0, i - 2, 0, i) ^ 1;
		}
		go(i, 0), go(0, i);
	}

	int real = a[1][0] ^ ask(1, 0, 1, 2) ^ 1;
	int x = (a[1][2] != real);
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if ((i + j) % 2)
				a[i][j] ^= x;

	bool any = false;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 2 && !any; j++) {
			if ((i + j) % 2)
				continue;

			if ((a[i][j] == a[i + 1][j + 1]) == (a[i + 1][j] == a[i + 1][j + 2])
				|| (a[i][j] == a[i][j + 2]) == (a[i][j + 1] == a[i + 1][j + 2])
				|| (a[i][j] == a[i + 1][j + 1]) == (a[i][j + 1] == a[i + 1][j + 2])) {
				int real = a[i][j] ^ ask(i, j, i + 1, j + 2) ^ 1;
				int x = (real != a[i + 1][j + 2]);
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						if ((i + j) % 2)
							a[i][j] ^= x;

				any = true;
			}
		}

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 2 && !any; j++) {
			if ((i + j) % 2 == 0)
				continue;

			if ((a[i][j] == a[i + 1][j + 1]) == (a[i + 1][j] == a[i + 1][j + 2])
				|| (a[i][j] == a[i][j + 2]) == (a[i][j + 1] == a[i + 1][j + 2])
				|| (a[i][j] == a[i + 1][j + 1]) == (a[i][j + 1] == a[i + 1][j + 2])) {
				int real = a[i + 1][j + 2] ^ ask(i, j, i + 1, j + 2) ^ 1;
				int x = (real != a[i + 1][j + 2]);
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						if ((i + j) % 2)
							a[i][j] ^= x;

				any = true;
			}
		}

	assert(any);
	cout << "!\n";
	for (auto xs : a) {
		for (auto x : xs)
			cout << x;
		cout << '\n';
	}
}