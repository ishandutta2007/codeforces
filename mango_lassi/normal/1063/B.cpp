#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

const int N = 2000;
ll dist[N][N]; // min sum of lefts + rights to reach here
bool wall[N][N];

bool inBounds(int x, int y, int w, int h) {
	if (x < 0 || x >= w || y < 0 || y >= h) return false;
	else return true;
}

int main() {
	int w, h;
	cin >> h >> w;
	int sy, sx;
	cin >> sy >> sx;
	ll lefts, rights;
	cin >> lefts >> rights;
	
	for (int y = 0; y < h; ++y) {
		string row;
		cin >> row;
		for (int x = 0; x < w; ++x) {
			if (row[x] == '*') {
				wall[x][y] = true;
			}
		}
	}

	--sx; --sy;
	for (int x = 0; x < w; ++x) {
		for (int y = 0; y < h; ++y) {
			dist[x][y] = INF;
		}
	}
	dist[sx][sy] = 0;
	
	priority_queue<pair<int, pair<int, int>>> que;
	que.push({0, {sx, sy}});

	while(! que.empty()) {
		auto pr = que.top();
		que.pop();

		ll c = -pr.first;
		int x = pr.second.first;
		int y = pr.second.second;
		if (dist[x][y] < c) continue;

		for (int tx = x-1; tx <= x+1; tx += 2) {
			int ty = y;
			if (inBounds(tx, ty, w, h) && !wall[tx][ty]) {
				if (dist[tx][ty] > c + 1) {
					que.push({-(c+1), {tx, ty}});
					dist[tx][ty] = c+1;
				}
			}
		}

		for (int ty = y-1; ty <= y+1; ty += 2) {
			int tx = x;
			if (inBounds(tx, ty, w, h) && !wall[tx][ty]) {
				if (dist[tx][ty] > c) {
					que.push({-c, {tx, ty}});
					dist[tx][ty] = c;
				}
			}
		}
	}

	int res = 0;
	for (int x = 0; x < w; ++x) {
		for (int y = 0; y < h; ++y) {
			ll both = (dist[x][y] - abs(x - sx)) / 2;
			ll ml, mr;
			if (x <= sx) {
				ml = abs(x - sx) + both;
				mr = both;
			} else {
				ml = both;
				mr = abs(x - sx) + both;
			}
			if (ml <= lefts && mr <= rights) ++res;
		}
	}
	cout << res << '\n';
}