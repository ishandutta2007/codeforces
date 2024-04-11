#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 500;
int val[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	int ax = 0;
	bool diff = false;
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			cin >> val[y][x];
		}
		ax ^= val[y][0];
		for (int x = 0; x < w; ++x) {
			if (val[y][0] != val[y][x]) diff = true;
		}
	}
	if (ax == 0 && diff == false) {
		cout << "NIE\n";
	} else {
		if (ax != 0) diff = false;

		cout << "TAK\n";
		for (int y = 0; y < h; ++y) {
			if (diff) {
				bool found = false;
				for (int x = 0; x < w; ++x) {
					if (val[y][0] != val[y][x]) {
						found = true;
						cout << x+1 << ' ';
						break;
					}
				}
				if (found) {
					diff = false;
					continue;
				}
			}
			cout << 1 << ' ';
		}
		cout << '\n';
	}
}