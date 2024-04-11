#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, m, x, y, a, b;
		cin >> n >> m >> x >> y >> a >> b;
		int dx = 1, dy = 1, cnt = 0;
		while (1) {
			if (x == a || y == b) break;
			++cnt;
			if (x + dx < 1 || x + dx > n) dx = -dx;
			if (y + dy < 1 || y + dy > m) dy = -dy;
			x += dx; y += dy;
		}
		cout << cnt << endl;
	}
	return 0;
}