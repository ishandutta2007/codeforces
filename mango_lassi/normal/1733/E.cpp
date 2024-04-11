#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 120;
ll arr[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		ll t;
		int ty, tx;
		cin >> t >> ty >> tx;
		t -= ty + tx;

		if (t < 0) cout << "NO\n";
		else {
			arr[0][0] = t;
			for (int y = 0; y <= ty; ++y) {
				for (int x = 0; x <= tx; ++x) {
					if (x > 0 || y > 0) arr[y][x] = 0;
					if (y > 0) arr[y][x] += arr[y-1][x] / 2;
					if (x > 0) arr[y][x] += (arr[y][x-1] + 1) / 2;
				}
			}

			int y = 0, x = 0;
			while(y <= ty && x <= tx && (y != ty || x != tx)) {
				if (arr[y][x] & 1) ++y;
				else ++x;
			}

			if (y == ty && x == tx) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}