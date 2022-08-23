#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/


template<typename T>
struct Dinic {
	const T INF = 1e9;
	const int INF1 = 1e9;
	struct edge {
		int a, b;
		T f, c;
	};
	int s, t;
	vector<edge> ed;
	int n;
	vector<vector<int> > eds;
	vector<T> dd;
	vector<int> pp;
	vector<int> inCut;
	Dinic(int N, int S, int TT) {
		n = N, s = S, t = TT;
		eds.clear();
		dd.clear();
		pp.clear();
		ed.clear();
		eds.resize(n);
		dd.resize(n);
		pp.resize(n);
		inCut.clear();
	}
	void add_edge(int a, int b, T c) {
		edge x;
		x.a = a;
		x.b = b;
		x.f = 0;
		x.c = c;
		eds[a].push_back(ed.size());
		eds[b].push_back(ed.size() + 1);
		ed.push_back(x);
		x.c = 0;
		swap(x.a, x.b);
		ed.push_back(x);
	}
	T dfs(int v, T fl) {
		if (v == t)
			return fl;
		if (dd[v] == dd[t])
			return 0;
		T sum = 0;
		for (; pp[v] < (int)eds[v].size(); ++pp[v]) {
			int e = eds[v][pp[v]];
			int u = ed[e].b;
			T fr = ed[e].c - ed[e].f;
			if (fr == 0 || dd[u] != dd[v] + 1 || pp[u] == (int)eds[u].size())
				continue;
			fr = dfs(u, min(fl, fr));
			ed[e].f += fr;
			ed[e ^ 1].f -= fr;
			sum += fr;
			fl -= fr;
			if (fl == 0)
				break;
		}
		return sum;
	}
	T flow() {
		T sum = 0;
		T lst = 0;
		do {
			lst = 0;
			fill(dd.begin(), dd.end(), INF1);
			dd[s] = 0;
			queue<int> qu;
			qu.push(s);
			while (!qu.empty()) {
				int x = qu.front();
				qu.pop();
				for (int i = 0; i < (int)eds[x].size(); ++i) {
					if (ed[eds[x][i]].f < ed[eds[x][i]].c) {
						int u = ed[eds[x][i]].b;
						if (dd[u] > dd[x] + 1)
							dd[u] = dd[x] + 1, qu.push(u);
					}
				}
			}
			if (dd[t] == INF)
				break;
			fill(pp.begin(), pp.end(), 0);
			lst = dfs(s, INF);
			sum += lst;
		} while (lst);
		return sum;
	}
	void dfs1(int s) {
		pp[s] = 1;
		for (int e: eds[s]) {
			if (ed[e].c != ed[e].f && !pp[ed[e].b])
				dfs1(ed[e].b);
		}
	}
	void markCut() {
		inCut.resize(ed.size());
		fill(pp.begin(), pp.end(), 0);
		dfs1(s);
		for (int i = 0; i < ed.size(); ++i)
			if (pp[ed[i].a] && !pp[ed[i].b])
				inCut[i] = 1;
			else
				inCut[i] = 0;
	}
};


template<typename T>
struct Point {
	T x, y;
	Point(T X = 0, T Y = 0) {
		x = X, y = Y;
	}
	template<typename D>
	Point(Point<D> a) {
		x = a.x;
		y = a.y;
	}
	Point<T> operator+(Point<T> a) {
		return Point<T>(x + a.x, y + a.y);
	}
	Point<T> operator-(Point<T> a) {
		return Point<T>(x - a.x, y - a.y);
	}
	Point<T> operator-() {
		return Point<T>(-x, -y);
	}
	Point<T>& operator+=(Point<T> a) {
		x += a.x;
		y += a.y;
		return *this;
	}
	Point<T>& operator-=(Point<T> a) {
		x -= a.x;
		y -= a.y;
		return *this;
	}
	Point<T> operator*(T k) {
		return Point<T>(x * k, y * k);
	}
	Point<T> operator/(T k) {
		return Point<T>(x / k, y / k);
	}
	Point<T>& operator*=(T k) {
		x *= k, y *= k;
		return *this;
	}
	Point<T>& operator/=(T k) {
		x /= k, y /= k;
		return *this;
	}
	T operator*(Point<T> a) {
		return x * a.y - y * a.x;
	}
	T operator^(Point<T> a) {
		return x * a.x + y * a.y;
	}
	ld len() {
		return sqrt(x * x + y * y);
	}
	T len2() {
		return x * x + y * y;
	}
	Point<T> rotl() {
		return Point<T>(-y, x);
	}
	Point<T> rotr() {
		return Point<T>(y, -x);
	}
	Point<ld> rot(ld ang) {
		return Point<ld>(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));
	}
};


template<typename T>
struct Line {
	T a, b, c;
	Line(Point<T> x, Point<T> y) {
		a = x.y - y.y;
		b = y.x - x.x;
		c = a * x.x + b * x.y;
	}
	template<typename D>
	Line(Line<D> x) {
		a = x.a;
		b = x.b;
		c = x.c;
	}
	pair<Point<ld>, Point<ld>> getPoints() {
		if (abs(a) <= abs(b)) {
			return make_pair(Point<ld>(0, c / b), Point<ld>(1, (c - a) / b));
		}
		else {
			return make_pair(Point<ld>(c / a, 0), Point<ld>((c - b) / a, 1));
		}
	}
};

template<typename T>
pair<Point<ld>, int> cross(Line<T> a, Line<T> b) {
	ld d = ld(a.a) * b.b - ld(a.b) * b.a;
	if (abs(d) <= 1e-9)
		return make_pair(Point<ld>(0, 0), 0);
	ld dx = ld(a.c) * b.b - ld(a.b) * b.c;
	ld dy = ld(a.a) * b.c - ld(a.c) * b.a;
	return make_pair(Point<ld>(dx / d, dy / d), 1);
}

const int MAXP = 410;

using point = Point<ll>;
using line = Line<ll>;


point p[MAXP];
point q[MAXP];
ll rr[MAXP];

int n, m;
ll w;

/*
ld get(point v) {
	ld ans = 0;
	p[n] = p[0];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((p[j] - p[i]) * v == 0) {
				ans = max(ans, (p[j] - p[i]).len());
			}
			if (((p[j] - p[i]) * v < 0 && (p[j + 1] - p[i]) * v > 0) || ((p[j] - p[i]) * v > 0 && (p[j + 1] - p[i]) * v < 0)) {
				line l1(p[j], p[j + 1]);
				line l2(p[i], p[i] + v);
				point x = cross(l1, l2).first;
				ans = max(ans, (x - p[i]).len());
			}
		}
	}
	return ans;
}*/

ld dist(point x, point a, point b) {
	if (a.x == b.x && a.y == b.y)
		return (x - a).len();
	ld ds = (a - x).len();
	ds = min(ds, (x - b).len());
	if (((x - a) ^ (b - a)) >= 0 && ((x - b) ^ (a - b)) >= 0) {
		ds = min(ds, abs((x - a) * (b - a)) / (b - a).len());
	}
	return ds;
}

const ld eps = 1e-15;

bool in(point a, ld d) {
	for (int i = 0; i < n; ++i) {
		if (dist(a, p[i], p[i + 1]) + eps <= d)
			return 1;
	}
	ll s1 = 0;
	ll s2 = 0;
	for (int i = 0; i < n; ++i) {
		s1 += p[i] * p[i + 1];
		s2 += abs((p[i] - a) * (p[i + 1] - a));
	}
	s1 = abs(s1);
	if (s1 == s2)
		return 1;
	return 0;
}


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> w;
	for (int i = 0; i < n; ++i)
		cin >> p[i].x >> p[i].y;
	ll x1 = p[0].x, x2 = p[0].x;
	for (int i = 1; i < n; ++i)
		x1 = min(x1, p[i].x), x2 = max(x2, p[i].x);
	int bst = 0;
	for (int i = 0; i < n; ++i)
		if (make_pair(p[i].y, p[i].x) < make_pair(p[bst].y, p[bst].x))
			bst = i;
	rotate(p, p + bst, p + n);
	for (int i = 1; i < n; ++i)
		p[i] = p[i] - p[0];
	p[0] = point(0, 0);
	point mn = p[0];
	point mx = p[0];
	for (int i = 1; i < n; ++i) {
		if (make_pair(p[i].y, p[i].x) < make_pair(mn.y, mn.x))
			mn = p[i];
		if (make_pair(-p[i].y, -p[i].x) < make_pair(mx.y, mx.x))
			mx = -p[i];
	}
	p[n] = p[0];
	vector<point> vp;
	for (int i = 0; i < n; ++i)
		vp.push_back(p[i + 1] - p[i]), vp.push_back(p[i] - p[i + 1]);
	sort(vp.begin(), vp.end(), [] (point a, point b) -> bool {
			if (a.y >= 0 && b.y < 0)
				return 1;
			if (a.y < 0 && b.y >= 0)
				return 0;
			if (a.y == 0 && b.y == 0)
				return a.x > 0 && b.x < 0;
			return a * b > 0;
			});
	p[0] = mn + mx;
	for (int i = 0; i < vp.size(); ++i)
		p[i + 1] = p[i] + vp[i];
	n = vp.size();
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> q[i].x >> q[i].y >> rr[i];
	vector<pair<int, int>> bl;
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			point v = q[j] - q[i];
			if (in(v, rr[i] + rr[j]))
				bl.emplace_back(i, j);
		}
		if (x2 - x1 + rr[i] > q[i].x)
			bl.emplace_back(i, m);
		if (x2 - x1 + rr[i] > w - q[i].x)
			bl.emplace_back(i, m + 1);
	}
	Dinic<ll> din(2 * m + 2, 2 * m, 2 * m + 1);
	for (int i = 0; i < m; ++i)
		din.add_edge(2 * i, 2 * i + 1, 1);
	for (auto p: bl) {
		if (p.second == m) {
			din.add_edge(2 * m, 2 * p.first, 300);
		}
		else if (p.second == m + 1) {
			din.add_edge(2 * p.first + 1, 2 * m + 1, 300);
		}
		else {
			din.add_edge(2 * p.first + 1, 2 * p.second, 300);
			din.add_edge(2 * p.second + 1, 2 * p.first, 300);
		}
	}
	cout << din.flow() << "\n";
	return 0;
}