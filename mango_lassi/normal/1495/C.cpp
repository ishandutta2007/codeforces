#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
	int h, w;
	cin >> h >> w;
	vector<string> lines(h);

	for (int y = 0; y < h; ++y) cin >> lines[y];
	
	for (int y = 0; y < h; y += 3) {
		for (int x = 0; x < w; ++x) lines[y][x] = 'X';
		
		if (y+2 < h) {
			bool found = 0;
			for (int x = 0; x < w; ++x) {
				if ((lines[y+1][x] == 'X' || lines[y+2][x] == 'X') && !found) {
					lines[y+1][x] = 'X';
					lines[y+2][x] = 'X';
					if (y+3 < h) found = 1;
				}
			}
			if ((! found) && (y+3 < h)) {
				lines[y+1][0] = 'X';
				lines[y+2][0] = 'X';
			}
		}
	}
	for (int y = 0; y < h; ++y) cout << lines[y] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}