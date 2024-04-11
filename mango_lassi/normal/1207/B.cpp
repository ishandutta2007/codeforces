#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 50;
int val[N][N];
int act[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			cin >> val[y][x];
		}
	}
	vector<pair<int, int>> res;
	for (int y = 0; y+1 < h; ++y) {
		for (int x = 0; x+1 < w; ++x) {
			if (val[y][x] && val[y+1][x] && val[y][x+1] && val[y+1][x+1]) {
				res.emplace_back(y, x);
				act[y][x] = 1;
				act[y+1][x] = 1;
				act[y][x+1] = 1;
				act[y+1][x+1] = 1;
			}
		}
	}
	bool match = true;
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			if (val[y][x] != act[y][x]) match = false;
		}
	}
	if (match) {
		cout << res.size() << '\n';
		for (auto pr : res) cout << pr.first+1 << ' ' << pr.second+1 << '\n';
	} else {
		cout << "-1\n";
	}
}