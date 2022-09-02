#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
int res[N];
int ind[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	bool flip = (h > w);
	if (flip) swap(h, w);

	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			ind[y*w + x] = (flip ? (x*h + y + 1) : (y*w + x + 1));
		}
	}

	// IMPOSSIBLE:
	// 1 2
	// 1 3
	// 2 2
	// 2 3

	if ((h == 1 && w == 2) || (h == 1 && w == 3) || (h == 2 && w == 2) || (h == 2 && w == 3)) cout << "NO\n";
	else {
		if (h == 1 && w == 1) {
			res[0] = 1;
		} else if (h == 3 && w == 3) {
			// 1 5 9
			// 6 7 2
			// 8 3 4
			res[0] = ind[0];
			res[1] = ind[4];
			res[2] = ind[8];
			res[3] = ind[5];
			res[4] = ind[6];
			res[5] = ind[1];
			res[6] = ind[7];
			res[7] = ind[2];
			res[8] = ind[3];
		} else if (w == 4) {
			if (h == 1) {
				res[0] = ind[1];
				res[1] = ind[3];
				res[2] = ind[0];
				res[3] = ind[2];
			} else if (h == 2) {
				res[0] = ind[4];
				res[1] = ind[3];
				res[2] = ind[6];
				res[3] = ind[1];
				res[4] = ind[2];
				res[5] = ind[5];
				res[6] = ind[0];
				res[7] = ind[7];
			} else if (h == 3) {
				// 1 7 9 4
				// 6 c 3 5
				// b 2 8 a
 
				res[0] = ind[0];
				res[1] = ind[6];
				res[2] = ind[8];
				res[3] = ind[3];
				res[4] = ind[5];
				res[5] = ind[11];
				res[6] = ind[2];
				res[7] = ind[4];
				res[8] = ind[10];
				res[9] = ind[1];
				res[10] = ind[7];
				res[11] = ind[9];
			} else if (h == 4) {
				for (int y = 0; y < h; ++y) {
					for (int x = 0; x < w; ++x) {
						int tx = (x & 1) ? (x/2) : ((x+w)/2);
						int ty = (y & 1) ? (y/2) : ((y+h)/2);
						res[ty*w + tx] = ind[y*w + x];
					}
				}
			}
		} else {
			for (int y = 0; y < h; ++y) {
				for (int x = 0; x < w; ++x) {
					int tx = ((x^y) & 1) ? (x/2) : ((x+w)/2);
					res[y*w + tx] = ind[y*w + x];
				}
			}
		}

		cout << "YES\n";
		if (flip) {
			for (int x = 0; x < w; ++x) {
				for (int y = 0; y < h; ++y) cout << res[y*w + x] << ' '; cout << '\n';
			}
		} else {
			for (int y = 0; y < h; ++y) {
				for (int x = 0; x < w; ++x) cout << res[y*w + x] << ' '; cout << '\n';
			}
		}
	}
}