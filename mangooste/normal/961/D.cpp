#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct point {
	int x, y;

	point(int x = 0, int y = 0) : x(x), y(y) {}
};

struct line {
	ll a, b, c;

	line(ll a = 0, ll b = 0, ll c = 0) : a(a), b(b), c(c) {}

	line(point pa, point pb) {
		a = pa.y - pb.y;
		b = pb.x - pa.x;
		c = (ll)pa.x * pb.y - (ll)pa.y * pb.x;
	}

	bool in(point p) {
		return a * p.x + b * p.y + c == 0;
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<point> p(n);
	for (auto &el : p) {
		cin >> el.x >> el.y;
	}

	if (n <= 3) {
		cout << "YES\n";
		return 0;
	}

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	bool ok = false;

	for (int _ = 0; _ < 50 && !ok; _++) {
		int a = rng() % n, b = rng() % n;
		if (a == b) {
			b = (b + 1) % n;
		}

		line ln(p[a], p[b]);
		vector<point> bad;
		for (int i = 0; i < n; i++) {
			if (!ln.in(p[i])) {
				bad.push_back(p[i]);
			}
		}

		if (bad.size() <= 2) {
			ok = true;
			continue;
		}

		ln = line(bad[0], bad[1]);
		ok = true;
		for (auto el : bad) {
			ok &= ln.in(el);
		}
	}

	cout << (ok ? "YES\n" : "NO\n");
}