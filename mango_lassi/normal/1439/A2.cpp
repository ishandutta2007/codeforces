#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100;
string arr[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int y = 0; y < n; ++y) cin >> arr[y];

	// x_ xx xx -> x_
	// xx _x x_    __

	vector<array<int, 6>> ops;
	for (int y = 0; y < n-2; ++y) {
		for (int x = 0; x < m; ++x) {
			if (arr[y][x] == '1') {
				int dx = (x > 0 ? -1 : 1);

				if (arr[y][x+dx] == '1') {
					arr[y][x] ^= '0' ^ '1';
					arr[y+1][x] ^= '0' ^ '1';
					arr[y][x+dx] ^= '0' ^ '1';
					ops.push_back({y, x, y + 1, x, y, x + dx});
				} else {
					arr[y][x] ^= '0' ^ '1';
					arr[y+1][x] ^= '0' ^ '1';
					arr[y+1][x+dx] ^= '0' ^ '1';
					ops.push_back({y, x, y + 1, x, y+1, x + dx});
				}
			}
		}
	}
	for (int x = 0; x < m-1; ++x) {
		for (int y = n-2; y < n; ++y) {

			if (arr[y][x] == '1') {
				int dy = (y+1 < n ? 1 : -1);

				if (arr[y+dy][x] == '1') {
					arr[y][x] ^= '0' ^ '1';
					arr[y+dy][x] ^= '0' ^ '1';
					arr[y][x+1] ^= '0' ^ '1';
					ops.push_back({y, x, y + dy, x, y, x + 1});
				} else {
					arr[y][x] ^= '0' ^ '1';
					arr[y][x+1] ^= '0' ^ '1';
					arr[y+dy][x+1] ^= '0' ^ '1';
					ops.push_back({y, x, y, x + 1, y + dy, x + 1});
				}
			}
		}
	}


	int y = n-2;
	int x = m-2;
	if (arr[y][x+1] == '1') {
		if (arr[y+1][x+1] == '1') {
			// 01
			// 01

			// 10
			// 11
			ops.push_back({y, x, y + 1, x, y, x + 1});
			ops.push_back({y, x, y + 1, x, y + 1, x + 1});
		} else {
			// 01
			// 00

			// 10
			// 10

			// 11
			// 01
			ops.push_back({y, x, y + 1, x, y, x + 1});
			ops.push_back({y+1, x, y, x + 1, y + 1, x + 1});
			ops.push_back({y, x, y, x + 1, y + 1, x + 1});
		}
	} else if (arr[n-1][m-1] == '1') {
		// 00
		// 01

		// 10
		// 10

		// 11
		// 01
		ops.push_back({y, x, y + 1, x, y + 1, x + 1});
		ops.push_back({y+1, x, y, x + 1, y + 1, x + 1});
		ops.push_back({y, x, y, x + 1, y + 1, x + 1});
	}

	cout << ops.size() << '\n';
	for (auto arr : ops) {
		cout << arr[0]+1 << ' ' << arr[1]+1 << ' ' << arr[2]+1 << ' ' << arr[3]+1 << ' ' << arr[4]+1 << ' ' << arr[5]+1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();

}