#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

/*
bool check(const vector<int>& perm, int w, int h) {
	for (int v = 0; v < (w*h)/2; ++v) {
		int x0 = -1;
		int y0 = -1;
		for (int x = 0; x < w; ++x) {
			for (int y = 0; y < h; ++y) {
				if (perm[x + y * w] == v) {
					if (x0 != -1) {
						if (abs(x - x0) + abs(y - y0) != 3) return false;
					} else {
						x0 = x;
						y0 = y;
					}
				}
			}
		}
	}
	return true;
}

bool brute(int w, int h) {
	vector<int> perm(w * h);
	for (int i = 0; i < w*h; i += 2) {
		perm[i] = i / 2;
		perm[i+1] = i / 2;
	}
	while(true) {
		if (check(perm, w, h)) return true;
		if (! next_permutation(perm.begin(), perm.end())) return false;
	}
}
*/

int main() {
	int n, m;
	cin >> n >> m;
	// cout << brute(n, m) << '\n';

	// 1x6, 2x4, 2x5, 3x4 are all possible
	if (m < n) swap(n, m);
	if (n == 1) {
		int res = 0;
		res += (m / 6) * 6;
		m %= 6;
		res += 2 * max(m - 3, 0);
		cout << res << '\n';
	} else if (n == 2) {
		if (m == 2) {
			cout << 0 << '\n';
		} else if (m == 3) {
			cout << 4 << '\n';
		} else if (m == 7) {
			cout << 12 << '\n';
		} else {
			cout << 2 * m << '\n';
		}
	} else {
		if (m % 2 == 0 || n % 2 == 0) {
			cout << (ll)n * m << '\n';
		} else {
			cout << (ll)n * m - 1 << '\n';
		}
	}
}