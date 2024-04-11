#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 100;
const int C = 26;
string rice[N];
string res[N];

char indChar(int i) {
	if (i < 10) return '0' + i;
	else if (i < 10 + C) return 'a' + (i - 10);
	else return 'A' + (i - 10 - C);
}

void solve() {
	int h, w, k;
	cin >> h >> w >> k;
	int rc = 0;
	for (int y = 0; y < h; ++y) {
		cin >> rice[y];
		for (auto c : rice[y]) {
			if (c == 'R') ++rc;
		}
	}
	for (int y = 0; y < h; ++y) {
		res[y] = string(w, '_');
	}

	int y = 0;
	int x = 0;
	int d = 1;
	for (; k > 0; --k) {
		char act = indChar(k-1);
		int t = rc / k;
		do {
			if (rice[y][x] == 'R') {
				--t;
				--rc;
			}
			res[y][x] = act;

			if (x+d < 0 || x+d >= w) {
				++y;
				d *= -1;
			} else {
				x += d;
			}
		} while (t > 0 || (y < h && k == 1));
	}

	for (y = 0; y < h; ++y) cout << res[y] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}