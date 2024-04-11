#include <iostream>
using namespace std;
using ll = long long;

const int H = 1000;
const int W = 1000;
string row[H];
int match[H][W];
int nxt[H][W];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	for (int y = 0; y < h; ++y) cin >> row[y];

	// Find longest matching suffix
	for (int y = 0; y < h; ++y) {
		match[y][w-1] = y+1;
		for (int x = w-2; x >= 0; --x) {
			if (row[y][x] != row[y][x+1]) match[y][x] = 0;
			else match[y][x] = 1 + (y > 0 ? match[y-1][x] : 0);
		}
	}

	// Find next spot where a different color appears
	for (int x = 0; x < w; ++x) {
		nxt[0][x] = -1;
		for (int y = 1; y < h; ++y) {
			if (row[y][x] == row[y-1][x]) nxt[y][x] = nxt[y-1][x];
			else nxt[y][x] = y-1;
		}
	}

	// Calculate answer
	ll res = 0;
	for (int y = 0; y < h; ++y) {
		ll pre = 0;
		for (int x = w-1; x >= 0; --x) {
			int t = nxt[y][x];
			int d = y - t;
			if (t != -1) {
				if (t - nxt[t][x] != d) t = -1;
				else t = nxt[t][x];
			}
			if (t != -1) {
				if (t - nxt[t][x] < d) {
					pre = 0;
				} else {
					t -= d;
					if (match[y][x] >= y-t) {
						++pre;
					} else {
						pre = 1;
					}
				}
			} else pre = 0;
			res += pre;
		}
	}
	cout << res << '\n';
}