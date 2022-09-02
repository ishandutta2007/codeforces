#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 500;
const int W = 3 * N;
const int H = 5;

bool arr[H][W];

void fill(int x, int y) {
	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			if (dx != 0 || dy != 0) arr[y + dy][x + dx] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	++n;

	// 1: 
	// xxx..
	// x.x..
	// xxxxx
	// ..x.x
	// ..xxx

	// 2:
	// xxx.xxx
	// x.x.x.x
	// xxxxxxx
	// ..x.x..
	// ..xxx..

	// And so on

	for (int i = 0; i < n; ++i) {
		int x = 1 + 2 * i;
		int y = 1 + 2*(i & 1);
		fill(x, y);
	}

	vector<pair<int, int>> res;
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			if (arr[y][x]) res.emplace_back(y, x);
		}
	}
	
	cout << res.size() << '\n';
	for (auto pr : res) cout << pr.first << ' ' << pr.second << '\n';
}