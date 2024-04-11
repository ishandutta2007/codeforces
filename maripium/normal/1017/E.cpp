#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
	Point(int x = 0,int y = 0) : x(x), y(y) {}
	bool operator < (const Point &p) {
		return make_pair(x, y) < make_pair(p.x, p.y);
	}
};

long long dist(Point a, Point b) { return 1ll * (a.x - b.x) * (a.x - b.x) + 1ll * (a.y - b.y) * (a.y - b.y); }
long long cross(Point a, Point b) { return 1ll * a.x * b.y - 1ll * b.x * a.y; }
long long area(Point a, Point b, Point c) {
	return cross(a, b) + cross(b, c) + cross(c, a);
}

void ConvexHull(vector<Point> &poly) {
	sort(poly.begin(), poly.end());
	vector<Point> up, down;
	for (int i = 0; i < poly.size(); ++i) {
		while (up.size() >= 2 && area(up[up.size() - 2], up.back(), poly[i]) >= 0) up.pop_back();
		while (down.size() >= 2 && area(down[down.size() - 2], down.back(), poly[i]) <= 0) down.pop_back();
		up.push_back(poly[i]), down.push_back(poly[i]);
	}
	poly = down;
	for (int i = up.size() - 2; i >= 1; --i) {
		poly.push_back(up[i]);
	}
}

const int N = 1e5 + 5;
const int base = 1007;
const int mod = 1e9 + 9277;

int n, m;
int pw[N + N], hs[N + N];
map<int,int> mp;

int get(int l,int r) {
	int ret = hs[r] - 1ll * hs[l - 1] * pw[r - l + 1] % mod;
	if (ret < 0) ret += mod; return ret;
}

int magic(Point a, Point b, Point c) {
	int dAB = dist(a, b) % mod, dBC = dist(b, c) % mod, dCA = dist(c, a) % mod;
	int ret = dAB;
	int fbase = 123456789;
	ret = (1ll * ret * fbase % mod + dBC) % mod;
	ret = (1ll * ret * fbase % mod + dCA) % mod;
	return ret;  
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	vector<Point> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i].x >> b[i].y;
	}
	ConvexHull(a), ConvexHull(b);
	if (a.size() != b.size()) {
		return cout << "NO" << '\n',0;
	}
	if (a.size() == 2) {
		long long dA = dist(a[0], a[1]);
		long long dB = dist(b[0], b[1]);
		if (dA != dB) return cout << "NO" << '\n',0;
		return cout << "YES" << '\n',0;
	}
	n = a.size();
	pw[0] = 1;
	for (int i = 1; i <= n + n; ++i) {
		pw[i] = 1ll * pw[i - 1] * base % mod;
	}
	vector<int> vec;
	for (int i = 0; i < n; ++i) {
		vec.push_back(magic(a[i], a[(i + 1) % n], a[(i + 2) % n]));
	}
	for (int i = 0; i < n; ++i) {
		vec.push_back(vec[i]);
	}
	for (int i = 1; i <= n + n; ++i) {
		hs[i] = (1ll * hs[i - 1] * base % mod + vec[i - 1]) % mod;
	}
	for (int i = 1; i <= n; ++i) {
		mp[get(i, i + n - 1)] = i;
	}
	int hsB = 0;
	for (int i = 0; i < n; ++i) {
		int cur = magic(b[i], b[(i + 1) % n], b[(i + 2) % n]);
		hsB = (1ll * hsB * base % mod + cur) % mod;
	}
	if (mp.count(hsB)) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}