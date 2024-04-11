#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 3;
int cou[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, sx, sy;
	cin >> n >> sx >> sy;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		x -= sx;
		y -= sy;
		int xv = (x > 0) + (x >= 0);
		int yv = (y > 0) + (y >= 0);
		++cou[xv][yv];
	}
	int c = -1;
	int tx = -1;
	int ty = -1;
	
	// Up
	int off = cou[0][0] + cou[1][0] + cou[2][0];
	if (off > c) {
		c = off;
		tx = sx;
		ty = sy - 1;
	}

	// Left
	off = cou[0][0] + cou[0][1] + cou[0][2];
	if (off > c) {
		c = off;
		tx = sx - 1;
		ty = sy;
	}

	// Right
	off = cou[2][0] + cou[2][1] + cou[2][2];
	if (off > c) {
		c = off;
		tx = sx + 1;
		ty = sy;
	}

	// Down
	off = cou[0][2] + cou[1][2] + cou[2][2];
	if (off > c) {
		c = off;
		tx = sx;
		ty = sy + 1;
	}

	cout << c << '\n';
	cout << tx << ' ' << ty << '\n';
}