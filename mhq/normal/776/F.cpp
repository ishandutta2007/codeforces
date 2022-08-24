#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
struct Point{
	ld x, y;
};
struct Vector {
	ld x, y;

	int halfPlane() const {
		return (x > 0 || (x == 0 && y > 0));
	}

	Vector()
		: x(0), y(0) {
	}

	Vector(int64_t x, int64_t y)
		: x(x), y(y) {
	}

	Vector(const Point &a, const Point &b)
		: x(b.x - a.x), y(b.y - a.y) {
	}
};

inline bool operator<(const Vector &a, const Vector &b) {
	int ha = a.halfPlane(), hb = b.halfPlane();
	if (ha != hb) {
		return ha < hb;
	}
	return a.x*b.y - a.y*b.x > 0;
}

struct PlanarFaceFinder {
	struct PlanarEdge {
		int a, b, idx;
		Vector v;

		inline friend bool operator<(const PlanarEdge &a, const PlanarEdge &b) {
			return a.v < b.v;
		}
	};

	int n, m;
	vector<Point> pt;
	vector<PlanarEdge> edges;
	vector< vector<PlanarEdge> > g;
	vector<int> fids;
	vector< vector<PlanarEdge> > faces;

	inline void addEdge(int a, int b) {
		edges.push_back({a, b, 2*m, Vector(pt[a], pt[b])});
		g[a].push_back(edges.back());
		edges.push_back({b, a, 2*m+1, Vector(pt[b], pt[a])});
		g[b].push_back(edges.back());
		++m;
	}

	inline vector< vector<PlanarEdge> > findFaces() {
		for (int i = 0; i < n; ++i) {
			sort(begin(g[i]), end(g[i]));
		}
		fids.assign(2*m, -1);
		faces.clear();
		for (int i = 0; i < 2*m; ++i) {
			if (fids[i] >= 0) {
				continue;
			}
			int cfid = faces.size();
			int edg = i;
			faces.emplace_back();
			while (fids[edg] < 0) {
				fids[edg] = cfid;
				faces.back().push_back(edges[edg]);
				int v = edges[edg].b;
				auto iter = upper_bound(begin(g[v]), end(g[v]), edges[edg^1]);
				if (iter == end(g[v])) {
					iter = begin(g[v]);
				}
				edg = iter->idx;
			}
			assert(fids[edg] == cfid);
		}
		return faces;
	}

	PlanarFaceFinder(const vector<Point> &pt)
		: n(pt.size()), m(0), pt(pt), g(n) {
	}
};

int n, m;
const ld COEF = 1e9;
const ld pi = acos(-1.0);
const int maxN = 1e5 + 10;
vector < int > g[maxN];
bool cmp(pair < vector < int >, vector < int > >& a, pair < vector < int >, vector < int > >& b) {
	for (int i = 0; i < min(a.first.size(), b.first.size()); i++) {
		if (a.first[i] != b.first[i]) return a.first[i] < b.first[i];
	}
	return a.first.size() < b.first.size();
}
int ans[maxN];
bool used[maxN];
int sz[maxN];
void dfs_sz(int v, int p) {
	sz[v] = 1;
	for (int to : g[v]) {
		if (!used[to] && to != p) {
			dfs_sz(to, v);
			sz[v] += sz[to];
		}
	}
}

int find_cen(int v, int need_sz, int p) {
	for (int to : g[v]) {
		if (!used[to] && to != p && sz[to] > need_sz) {
			return find_cen(to, need_sz, v);
		}
	}
	return v;
}

void solve(int root, int clr) {
	dfs_sz(root, -1);
	int cen = find_cen(root, (sz[root] + 1) / 2, -1);
	ans[cen] = clr;
	used[cen] = true;
	for (int to : g[cen]) {
		if (!used[to]) {
			solve(to, clr + 1);
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    vector < Point > pt(n);
    for (int i = 0; i < n; i++) {
    	ld ang = (2 * pi * i) / n;
    	pt[i] = {COEF * sin(ang), COEF * cos(ang)};
    }
    PlanarFaceFinder pl(pt);
    for (int i = 0; i < n; i++) {
    	pl.addEdge(i, (i + 1) % n);
    }
    for (int i = 0; i < m; i++) {
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	pl.addEdge(a, b);
    }
    auto it = pl.findFaces();
    bool need_del = true;
    vector < pair < vector < int >, vector < int > > > vv;
    for (auto& pit : it) {
    	if (pit.size() == n && need_del) {
    		need_del = false;
    		continue;
    	}
    	vector < int > cur;
    	for (int i = 0; i < pit.size(); i++) {
    		cur.emplace_back(pit[i].a);
    	}
    	auto cur_sorted = cur;
    	sort(cur_sorted.begin(), cur_sorted.end());
    	reverse(cur_sorted.begin(), cur_sorted.end());
    	vv.emplace_back(cur_sorted, cur);
    }
	sort(vv.begin(), vv.end(), cmp);
	vector < vector < int > > regs;
	map < pair < int, int >, int > ids;
	int sz = 0;
	for (int i = 0; i < vv.size(); i++) {
		regs.emplace_back(vv[i].second);
		for (int j = 0; j < regs.back().size(); j++) {
			pair < int, int > t = minmax(regs.back()[j], regs.back()[(j + 1) % regs.back().size()]);
			if (ids.count(t)) {
				g[sz].emplace_back(ids[t]);
				g[ids[t]].emplace_back(sz);
			}
			else {
				ids[t] = sz;
			}
		}
		sz++;
	}
	solve(0, 1);
	for (int i = 0; i < sz; i++) {
		cout << ans[i] << " ";
	}

    return 0;
}