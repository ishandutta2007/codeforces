#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18 + 7;

// Struct for priority queue operations on index set [0, n-1]
// push(i, v) overwrites value at position i if one already exists
// decKey is faster but requires that the new key is smaller than the old one
struct Prique {
	const ll INF = 4 * (ll)1e18;
	vector<pair<ll, int>> data;
	const int n;

	Prique(int siz) : n(siz), data(2*siz, {INF, -1}) { data[0] = {-INF, -1}; }
	bool empty() const { return data[1].first >= INF; }
	pair<ll, int> top() const { return data[1]; }

	void push(int i, ll v) {
		data[i+n] = {v, (v >= INF ? -1 : i)};
		for (i += n; i > 1; i >>= 1) data[i>>1] = min(data[i], data[i^1]);
	}
	void decKey(int i, ll v) {
		for (int j = i+n; data[j].first > v; j >>= 1) data[j] = {v, i};
	}
	pair<ll, int> pop() {
		auto res = data[1];
		push(res.second, INF);
		return res;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	ll p, q;
	cin >> p >> q;

	vector<vector<ll>> dist(h);
	for (int y = 0; y < h; ++y) dist[y].resize(w, INF);
	
	Prique pq(h*w);
	vector<string> arr(h);
	for (int y = 0; y < h; ++y) {
		cin >> arr[y];
		for (int x = 0; x < w; ++x) {
			if (arr[y][x] == '.') {
				dist[y][x] = 0;
				pq.decKey(y * w + x, 0);
			}
		}
	}
	while(! pq.empty()) {
		int ind = pq.top().second;
		ll v = pq.top().first;
		pq.pop();

		int y = ind / w;
		int x = ind % w;

		int bdir = -1;
		if (arr[y][x] != '.') {
			if (arr[y][x] == 'U') bdir = 0;
			if (arr[y][x] == 'L') bdir = 1;
			if (arr[y][x] == 'D') bdir = 2;
			if (arr[y][x] == 'R') bdir = 3;
		}
		
		for (int dir = 0; dir < 4; ++dir) {
			if (dir == bdir) continue;

			int dy = (dir == 0) - (dir == 2);
			int dx = (dir == 1) - (dir == 3);

			int ty = y + dy;
			int tx = x + dx;
			if (ty < 0 || ty >= h || tx < 0 || tx >= w) continue;

			if (arr[ty][tx] == '.' || arr[ty][tx] == '#') continue;
			bool vert_ch = (arr[ty][tx] == 'U' || arr[ty][tx] == 'D');
			bool push = (vert_ch && dy != 0) || (! vert_ch && dy == 0);
			
			ll off = v + (push ? q : p);
			int ty2 = ty + (arr[ty][tx] == 'U') - (arr[ty][tx] == 'D');
			int tx2 = tx + (arr[ty][tx] == 'L') - (arr[ty][tx] == 'R');

			if (dist[ty2][tx2] > off) {
				dist[ty2][tx2] = off;
				pq.decKey(ty2 * w + tx2, off);
			}
		}
	}

	ll res = INF;
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			if (y + 1 < h) res = min(res, dist[y][x] + dist[y + 1][x]);
			if (x + 1 < w) res = min(res, dist[y][x] + dist[y][x + 1]);
		}
	}
	if (res >= INF) {
		cout << -1 << '\n';
	} else {
		cout << res << '\n';
	}
}