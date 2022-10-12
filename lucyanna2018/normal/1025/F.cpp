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
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 2020;
const int M = N * N / 2;

struct Point {
	ll x, y;

	Point() : x(), y() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}

	void scan() {
		cin >> x >> y;
	}
	void print() {
		cout << x << " " << y << endl;
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
};

Point a[N];
int p[N];
int rp[N];
pii b[M];
int n;

bool cmp1(const int &id1, const int &id2) {
	Point v = a[id1], u = a[id2];
	if (v.y != u.y) return v.y < u.y;
	return v.x < u.x;
}
bool cmp2(const pii &p1, const pii &p2) {
	Point v = a[p1.second] - a[p1.first], u = a[p2.second] - a[p2.first];
	return v * u > 0;
}

ll solve(int v,int u) {
	Point w = a[u] - a[v];
	int lo = -1, hi = n-1;
	while (lo != hi) {
		int mi = (lo + hi + 1) / 2;
		if (w * (a[p[mi]] - a[v]) >= 0)
			hi = mi - 1;
		else
			lo = mi;
	}
	ll X = lo+1, Y = n - X - 2;
	return (X*(X - 1) / 2) * (Y*(Y - 1) / 2);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)a[i].scan();

	for (int i = 0; i < n; i++)
		p[i] = i;
	sort(p, p + n, cmp1);
	for (int i = 0; i < n; i++)
		rp[p[i]] = i;
	int m = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++) {
			Point d = a[j] - a[i];
			if (d.y < 0 || (d.y == 0 && d.x < 0)) {
				b[m++] = mp(j, i);
			}
			else {
				b[m++] = mp(i, j);
			}
		}
	sort(b, b + m, cmp2);
	ll res = 0;
	for (int i = 0; i < m; i++) {
		int v = b[i].first, u = b[i].second;
		res += solve(v, u);
		int pv = rp[v], pu = rp[u];
		swap(p[pv], p[pu]);
		swap(rp[v], rp[u]);
	}
	cout << res << endl;
	return 0;
}