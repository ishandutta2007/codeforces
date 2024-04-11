#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int H = 2 * (int)1e4;
vector<int> divs[H];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 1; i <= H; ++i) {
		for (int j = i; j <= H; j += i) divs[j].push_back(i);
	}
	
	for (int ti = 0; ti < t; ++ti) {
		int a, b, c;
		cin >> a >> b >> c;

		pair<pair<int, int>, pair<int, int>> res = {{3*H, -1}, {-1, -1}};
		for (int y = 1; y <= H; ++y) {
			int db = abs(b - y);

			int dc = c % y;
			int z = c - dc;
			if (c < y || (y - dc < dc)) {
				dc = y - dc;
				z += y;
			}

			int da = H;
			int x = 1;
			for (auto i : divs[y]) {
				if (abs(a - i) <= da) {
					da = abs(a - i);
					x = i;
				}
			}
			res = min(res, {{da + db + dc, x}, {y, z}});
		}
		cout << res.first.first << '\n' << res.first.second << ' ' << res.second.first << ' ' << res.second.second << '\n';
	}
}