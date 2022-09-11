#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
inline int pidorand() {
	return ((rand() & 32767) << 15) | (rand() & 32767);
}
#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

#define int long long
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a%b); }

struct Point {
	int x, y;

	Point(int _x, int _y) : x(_x), y(_y) {}
	Point() {}

	Point operator +(const Point& p) const {
		return Point(x + p.x, y + p.y);
	}

	Point operator -(const Point& p) const {
		return Point(x - p.x, y - p.y);
	}

	Point operator *(int k) const {
		return Point(x * k, y * k);
	}

	long long vprod(const Point& p) const {
		return 1ll * x * p.y - 1ll * y * p.x;
	}

	Point normed() const {
		long long g = gcd(abs(x), abs(y));
		if (y > 0 || (y == 0 && x > 0)) {
			return Point(x / g, y / g);
		} else {
			return Point(-x / g, -y / g);
		}
	}

	bool operator <(const Point& p) const {
		return x < p.x || x == p.x&&y < p.y;
	}

	bool operator ==(const Point& p) const {
		return x == p.x && y == p.y;
	}
};

ostream& operator <<(ostream& ostr, const Point& pt) {
	ostr << "(" << pt.x << ", " << pt.y << ")";
	return ostr;
}

int32_t main() {
	int n = nxt();
	int mlt = n;
	Point cen(0, 0);
	vector<Point> a(n);
	for (int i = 0; i < n; ++i) {
		int x = nxt(), y = nxt();
		a[i] = Point(x, y);
		cen = cen + a[i];
	}

	for (int i = 0; i < (int)a.size(); ++i) {
		if (a[i] * n == cen) {
			a.erase(a.begin() + i);
			--i;
		}
	}

	for (int i = 0; i < (int)a.size(); ++i) {
		int j = i + 1;
		while (j < (int)a.size() && !((a[i] + a[j]) * n == cen * 2)) {
			++j;
		}
		if (j < (int)a.size()) {
			a.erase(a.begin() + j);
			a.erase(a.begin() + i);
			--i;
		}
	}

	n = a.size();
	if (n == 0) {
		puts("-1");
		return 0;
	}

	vector<Point> dirs;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			dirs.push_back(((a[i] + a[j]) * mlt - cen * 2).normed());
		}
	}

	// for (auto p : dirs) {
	// 	cerr << p << ", ";
	// }
	// cerr << "\n";

	sort(all(dirs));
	int ans = 0;
	for (int i = 0; i < (int)dirs.size();) {
		int j = i;
		while (j < (int)dirs.size() && dirs[i] == dirs[j]) {
			++j;
		}
		if (j >= i + n / 2) {
			Point dir = dirs[i];

			vector<long long> vals;
			for (int k = 0; k < n; ++k) {
				vals.push_back(a[k].vprod(dir));
			}
			sort(all(vals));
			bool ok = true;
			long long zlp = vals[0] + vals[n - 1];
			for (int k = 0; k < (n + 1) / 2; ++k) {
				if (vals[k] + vals[n - 1 - k] != zlp) {
					ok = false;
					break;
				}
			}
			if (ok) {
				++ans;
			}
		}

		i = j;
	}

	cout << ans << "\n";

	return 0;
}