#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	// have all numbers 1 ... h*w appear
	// -> 


	//   4  5  6
	// 1 4  5  6
	// 2 4  10 6
	// 3 12 15 6

	if (h == 1 && w == 1) cout << 0 << '\n';
	else {
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				ll row, col;
				if (h > w) {
					row = w+y+1;
					col = x+1;
				} else {
					row = y+1;
					col = h+x+1;
				}
				cout << (row * col) / gcd(row, col) << ' ';
			}
			cout << '\n';
		}
	}
}