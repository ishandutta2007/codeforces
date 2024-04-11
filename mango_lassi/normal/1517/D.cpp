#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int N = 500;
int dp[N][N];
int tmp[N][N];
int dist[N][N][2];

void cap(int& a, int b) { a = min(a, b); }

void solve() {
	int h, w, k;
	cin >> h >> w >> k;

	for (int y = 0; y < h; ++y) {
		for (int x = 0; x+1 < w; ++x) cin >> dist[y][x][0];
	}
	for (int y = 0; y < h-1; ++y) {
		for (int x = 0; x < w; ++x) cin >> dist[y][x][1];
	}

	if (k & 1) {
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) dp[y][x] = -1;
		}
	} else {
		for (int it = 0; it < k/2; ++it) {
			for (int y = 0; y < h; ++y) {
				for (int x = 0; x < w; ++x) {
					int off = INF;
					if (y > 0) cap(off, dp[y-1][x] + 2*dist[y-1][x][1]);
					if (x > 0) cap(off, dp[y][x-1] + 2*dist[y][x-1][0]);
					if (y+1 < h) cap(off, dp[y+1][x] + 2*dist[y][x][1]);
					if (x+1 < w) cap(off, dp[y][x+1] + 2*dist[y][x][0]);
					tmp[y][x] = off;
				}
			}
			for (int y = 0; y < h; ++y) {
				for (int x = 0; x < w; ++x) dp[y][x] = tmp[y][x];
			}
		}
	}

	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) cout << dp[y][x] << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();

	/*
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
	*/
}