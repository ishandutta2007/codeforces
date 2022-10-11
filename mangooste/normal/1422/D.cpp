#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Point {
	int x, y;
	int num;

	Point(int x = 0, int y = 0, int num = -1) : x(x), y(y), num(num) {}
};

vector<vector<pair<int, int>>> g;

inline void add_edge(int v, int u, int len) {
	// cout << v << ' ' << u << ' ' << len << endl;
	g[v].emplace_back(u, len);
	g[u].emplace_back(v, len);
}

inline int dist(Point a, Point b) {
	return min(abs(a.x - b.x), abs(a.y - b.y));
}

inline int dist2(Point a, Point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	Point start;
	cin >> start.x >> start.y;
	Point finish;
	cin >> finish.x >> finish.y;
	vector<Point> ps(m);
	for (int i = 0; i < m; i++) {
		cin >> ps[i].x >> ps[i].y;
		ps[i].num = i;
	}

	g.resize(m + 2);
	add_edge(0, m + 1, dist2(start, finish));
	for (int i = 0; i < m; i++) {
		int len = dist(start, ps[i]);
		add_edge(0, i + 1, len);
		len = dist2(ps[i], finish);
		add_edge(i + 1, m + 1, len);
	}

	sort(ps.begin(), ps.end(), [](Point a, Point b) {
		return a.x < b.x;
	});
	for (int i = 0; i < m - 1; i++) {
		int ii = ps[i].num;
		int jj = ps[i + 1].num;
		int len = ps[i + 1].x - ps[i].x;
		add_edge(ii + 1, jj + 1, len);
	}

	sort(ps.begin(), ps.end(), [](Point a, Point b) {
		return a.y < b.y;
	});
	for (int i = 0; i < m - 1; i++) {
		int ii = ps[i].num;
		int jj = ps[i + 1].num;
		int len = ps[i + 1].y - ps[i].y;
		add_edge(ii + 1, jj + 1, len);
	}

	#define dist dist228
	set<pair<int, int>> st;
	vector<int> dist(m + 2, (int) 2e9 + 3);
	dist[0] = 0;
	st.insert({0, 0});
	while (st.size()) {
		int v = st.begin()->second;
		st.erase(st.begin());
		for (auto [u, len] : g[v])
			if (dist[u] > dist[v] + len) {
				st.erase({dist[u], u});
				dist[u] = dist[v] + len;
				st.insert({dist[u], u});
			}
	}
	cout << dist.back() << '\n';
}