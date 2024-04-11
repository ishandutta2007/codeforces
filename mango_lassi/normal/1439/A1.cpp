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
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (arr[y][x] == '1') {
				int dx = (x > 0 ? -1 : 1);
				int dy = (y > 0 ? -1 : 1);
				ops.push_back({y, x, y + dy, x, y + dy, x + dx});
				ops.push_back({y, x, y, x + dx, y + dy, x + dx});
				ops.push_back({y, x, y + dy, x, y, x + dx});
			}
		}
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