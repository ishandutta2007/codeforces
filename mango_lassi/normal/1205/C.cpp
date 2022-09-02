#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 50;
int res[N][N];

int ask(int x1, int y1, int x2, int y2) {
	cout << "? " << (y1+1) << ' ' << (x1+1) << ' ' << (y2+1) << ' ' << (x2+1) << endl;
	int res;
	cin >> res;
	return res;
}
void answer(int n) {
	cout << "!" << endl;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) cout << res[y][x];
		cout << endl;
	}
}
void flipOdd(int n) {
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			if ((x+y) % 2 == 1) res[y][x] ^= 1;
		}
	}
}
bool handleDiag(int x, int y, int n) {
	if (res[y+1][x] != res[y][x+1]) {
		int x0 = x;
		int y0 = y;
		int x1 = x+1;
		int y1 = y+1;
		if (x > 0) --x0;
		else if (y > 0) --y0;
		else if (x+2 < n) ++x1;
		else if (y+2 < n) ++y1;
		if (ask(x0, y0, x1, y1) != (res[y0][x0] == res[y1][x1])) flipOdd(n);
		return true;
	} else return false;
}

int main() {
	int n;
	cin >> n;

	res[0][0] = 1;
	res[2][1] = res[0][1] ^ 1 ^ ask(1, 0, 1, 2);
	res[1][0] = res[2][1] ^ 1 ^ ask(0, 1, 1, 2);
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (x + y < 2) continue;
			if (x == 1 && y == 2) continue;
			if (x == n-1 && y == n-1) continue;

			if (x >= 2) {
				res[y][x] = res[y][x-2] ^ 1 ^ ask(x-2, y, x, y);
			} else if (y >= 2) {
				res[y][x] = res[y-2][x] ^ 1 ^ ask(x, y-2, x, y);
			} else {
				res[y][x] = res[y-1][x-1] ^ 1 ^ ask(x-1, y-1, x, y);
			}
		}
	}

	// 3 questions left, we'll use at most 2
	// Find 3x3 square with 1 in upper left corner and 0 in bottom right corner
	for (int i = 0; i+2 < n; ++i) {
		int x = i;
		int y = i;
		if (res[y][x] != 1 || res[y+2][x+2] != 0) continue;
		if (handleDiag(x, y, n)) break;
		if (handleDiag(x+1, y, n)) break;
		if (handleDiag(x, y+1, n)) break;
		if (handleDiag(x+1, y+1, n)) break;
		if (ask(x, y, x+2, y+1)) {
			if (res[y][x] != res[y+1][x+2]) flipOdd(n);
		} else if (ask(x+1, y, x+2, y+2)) {
			if (res[y][x+1] != res[y+2][x+2]) flipOdd(n);
		} else {
			if (res[y+2][x] == 1) {
				// 1X1
				// X1Z
				// 1Z0
				// 1X1Z: Not palindrome if X != 1 or Z != 1
				// X1Z0: Not palindrome if X != 0 or Z != 1
				// -> Z == 0
				if (res[y+1][x+2] == 1) flipOdd(n);
			} else {
				// 1X0
				// X0Z
				// 0Z0
				// 1X0Z: Not palindrome if X != 0 or Z != 1
				// X0Z0: Not palindrome if X != 0 or Z != 0
				// -> X == 1
				if (res[y][x+1] == 0) flipOdd(n);
			}
		}
		break;
	}
	answer(n);
}