#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int H = 400;
const int W = 400;
int arr[H][W];
int sums[H][W + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int h, w;
		cin >> h >> w;

		for (int y = 0; y < h; ++y) {
			string str;
			cin >> str;
			for (int x = 0; x < w; ++x) arr[y][x] = (str[x] == '1');
			sums[y][0] = 0;
			for (int x = 1; x <= w; ++x) sums[y][x] = sums[y][x-1] + arr[y][x-1];
		}

		int res = INF;
		for (int x0 = 0; x0 < w; ++x0) {
			for (int x1 = x0 + 3; x1 < w; ++x1) {
				int len = x1 - x0 - 1;

				array<int, 4> min_cost;
				min_cost[0] = INF;
				min_cost[1] = INF;
				min_cost[2] = INF;
				min_cost[3] = INF;

				for (int y1 = 0; y1 < h; ++y1) {
					int cou = sums[y1][x1] - sums[y1][x0 + 1];
					int empt = len - cou;
					int sd = 2 - arr[y1][x0] - arr[y1][x1];
					int off = min_cost[3] + empt;
	
					res = min(res, min_cost[3] + empt);
					min_cost[3] = cou + sd + min(min_cost[3], min_cost[2]);
					min_cost[2] = cou + sd + min_cost[1];
					min_cost[1] = cou + sd + min_cost[0];
					min_cost[0] = empt;
				}
			}
		}
		cout << res << '\n';
	}
	
}