#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18;
struct rect_t {
	int x, y; long long f;
	bool operator < (const rect_t& rc) const {
		return x < rc.x;
	}
};

struct line_t {
	int a; long long b;
	line_t(int a = 0,long long b = 0) : a(a), b(b) {}
	long long f(int x) { return 1LL * a * x + b; };
};

double slope(line_t ln1, line_t ln2) {
	return (double) (ln2.b - ln1.b) / (double) (ln2.a - ln1.a);
}

struct convex_hull {
	vector<line_t> lns;
	int ptr = 0;
	void add(int a,long long b) {
		line_t ln(a, b);
		while (lns.size() > 1 && slope(lns[lns.size() - 2], lns.back()) <= slope(lns[lns.size() - 2], ln)) lns.pop_back();
		lns.push_back(ln); ptr = min(ptr, int(lns.size()) - 1);
	}
	long long get(int x) {
		if (lns.empty()) return -inf;
		while (ptr + 1 < int(lns.size()) && lns[ptr].f(x) < lns[ptr + 1].f(x)) ptr++;
		return lns[ptr].f(x);
	}
};

const int N = 1000005;

int n;
rect_t a[N];
convex_hull ch;
long long ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y >> a[i].f;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		long long now = max(0LL, ch.get(-a[i].y)) + 1LL * a[i].x * a[i].y - a[i].f;
		ans = max(ans, now);
		ch.add(a[i].x, now);
	}
	cout << ans << '\n';
}