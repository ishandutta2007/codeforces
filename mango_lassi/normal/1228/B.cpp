#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 1e3;
int val[N][N];

void setv(int y, int x, int v, ll& cou) {
	if (val[y][x] == -v) cou = 0;
	val[y][x] = v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	ll cou = 1;
	for (int y = 0; y < h; ++y) {
		int r;
		cin >> r;
		for (int x = 0; x < r; ++x) setv(y, x, 1, cou);
		if (r < w) setv(y, r, -1, cou);
	}
	for (int x = 0; x < w; ++x) {
		int r;
		cin >> r;
		for (int y = 0; y < r; ++y) setv(y, x, 1, cou);
		if (r < h) setv(r, x, -1, cou);
	}
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			if (val[y][x] == 0) cou = (cou * 2) % MOD;
		}
	}
	cout << cou << '\n';
}