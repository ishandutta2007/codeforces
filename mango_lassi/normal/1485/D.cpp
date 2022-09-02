#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int H = 720720;

const int N = 500;
int as[N][N];

void solve() {
	int h, w;
	cin >> h >> w;
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) cin >> as[y][x];
	}

	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			int a = as[y][x];
			if ((x + y) % 2 == 0) cout << H << ' ';
			else cout << H - a*a*a*a << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}