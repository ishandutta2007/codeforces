#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Point {
	ll x, y;

	Point() : x(), y() {}
	Point (ll _x, ll _y) : x(_x), y(_y) {}

	void scan() {
		scanf("%lld%lld", &x, &y);
	}
	void print() {
		eprintf("(%lld %lld)\n", x, y);
	}

	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	ll operator % (const Point &a) const {
		return x * a.x + y * a.y;
	}
	ll operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}
	ll sqrLen() const {
		return *this % *this;
	}

	bool operator < (const Point &a) const {
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
};

typedef pair<Point, int> ppi;

Point minP;

bool cmp(ppi A, ppi B) {
	Point v = A.first - minP, u = B.first - minP;
	ll x = v * u;
	if (x != 0) return x > 0;
	return v.sqrLen() < u.sqrLen();
}

const int N = 1010;
int n;
Point a[N];
ppi b[N];
bool bad[N];
bool was[N];
int col[N];
int ans[N][2];
int ansSz;
int m;

void addEdge(int v, int u) {
	ans[ansSz][0] = v;
	ans[ansSz][1] = u;
	ansSz++;
}

void buildHull() {
	m = 0;
	for (int i = 0; i < n; i++)
		if (!bad[i])
			b[m++] = mp(a[i], i);
	minP = b[0].first;
	for (int i = 0; i < m; i++)
		if (b[i].first < minP)
			minP = b[i].first;
	sort(b, b + m, cmp);
	int sz = 0;
	for (int i = 0; i < m; i++) {
		Point P = b[i].first;
		while(sz > 1 && (P - b[sz - 1].first) * (P - b[sz - 2].first) >= 0) sz--;
		b[sz++] = b[i];
	}
	m = sz;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		a[i].scan();
		scanf("%d", &col[i]);
	}
	buildHull();
	int cntCh = 0;
	for (int i = 0; i < m - 1; i++) {
		if (col[b[i].second] != col[b[i + 1].second]) cntCh++;
	}
	if (cntCh > 2) {
		printf("Impossible\n");
		return 0;
	}
	for (int i = 0; i < m; i++)
		was[b[i].second] = 1;
	while(ansSz < n - 2) {
		int pos = 0;
		while(pos < m - 1 && col[b[pos].second] == col[b[pos + 1].second]) pos++;
		int rg = (pos + 1) % m, lf = (pos + m - 1) % m;
		if (col[b[rg].second] != col[b[pos].second] && col[b[lf].second] != col[b[pos].second])
			pos = (pos + 1) % m;
		rg = (pos + 1) % m, lf = (pos + m - 1) % m;
		if (col[b[rg].second] != col[b[pos].second] && col[b[lf].second] != col[b[pos].second])
			throw;
		if (col[b[rg].second] == col[b[pos].second])
			addEdge(b[rg].second, b[pos].second);
		else
			addEdge(b[lf].second, b[pos].second);
		int me = b[pos].second;
		bad[me] = 1;
		int myCol = col[me];
		bool fnd = true;
		while(fnd) {
			buildHull();
			fnd = false;
			for (int i = 0; !fnd && i < m; i++) {
				int pp = b[i].second;
				if (!was[pp] && col[pp] == myCol) {
					fnd = true;
					bad[pp] = 1;
					addEdge(me, pp);
				}
			}
		}
		for (int i = 0; i < m; i++)
			was[b[i].second] = 1;
	}
	buildHull();
	if (m > 2) throw;
	if (m == 2) {
		int p = b[0].second, q = b[1].second;
		if (col[p] == col[q])
			addEdge(p, q);
	}
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d %d\n", ans[i][0], ans[i][1]);

	return 0;
}