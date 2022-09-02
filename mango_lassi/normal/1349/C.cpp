#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18 + 7;

vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

const int N = 1000;
int col[N][N];
ll dfs[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w, q;
	cin >> h >> w >> q;
	for (int y = 0; y < h; ++y) {
		string str;
		cin >> str;
		for (int x = 0; x < w; ++x) {
			col[y][x] = (str[x] == '1');
			dfs[y][x] = INF;
		}
	}

	vector<int> que;
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			bool ini = 0;
			for (auto pr : dirs) {
				int tx = x + pr.first;
				int ty = y + pr.second;
				if (ty >= 0 && ty < h && tx >= 0 && tx < w) {
					if (col[ty][tx] == col[y][x]) ini = 1;
				}
			}

			if (ini) {
				que.push_back(x + y*w);
				dfs[y][x] = 0;
			}
		}
	}
	for (int i = 0; i < que.size(); ++i) {
		int y = que[i] / w;
		int x = que[i] - w*y;
		for (auto pr : dirs) {
			int tx = x + pr.first;
			int ty = y + pr.second;
			if (ty >= 0 && ty < h && tx >= 0 && tx < w) {
				if (dfs[ty][tx] > dfs[y][x] + 1) {
					dfs[ty][tx] = dfs[y][x] + 1;
					que.push_back(tx + ty * w);
				}
			}
		}
	}

	for (int qi = 0; qi < q; ++qi) {
		int y, x;
		ll t;
		cin >> y >> x >> t;
		--y; --x;

		int toggle = (t > dfs[y][x] ? (t - dfs[y][x]) % 2 : 0);
		cout << (col[y][x] ^ toggle) << '\n';
	}
}