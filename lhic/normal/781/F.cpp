#pragma GCC optimize "-Ofast"
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef double ld;

using namespace std;
const int MAXN = 310000;
int n, m;
vector<pair<int, int>> pp;
ld T;
ld len[MAXN];
vector<pair<ld, ld>> vv;
vector<pair<ld, int> > ev;
ld lst = 0;
const ld eps = 1e-10;
const int IT0 = 30;
const int IT1 = 50;
const int IT2 = 30;

void add(ld tl, ld tr, ld x, ld y, ld dx, ld dy, ld d) {
	ld bl = 0;
	ld br = tr - tl;
	for (int it = 0; it < IT1; ++it) {
		ld m1 = bl + 4 * (br - bl) / 9;
		ld m2 = m1 + (br - bl) / 9;
		ld n1x = x + dx * m1;
		ld n1y = y + dy * m1;
		ld n2x = x + dx * m2;
		ld n2y = y + dy * m2;
		if (n1x * n1x + n1y * n1y < n2x * n2x + n2y * n2y)
			br = m2;
		else
			bl = m1;
	}
	ld t = (bl + br) / 2;
	ld nx = x + dx * t;
	ld ny = y + dy * t;
	if (nx * nx + ny * ny > d * d)
		return;
	bl = 0;
	br = t;
	for (int it = 0; it < IT2; ++it) {
		ld m = (bl + br) / 2;
		ld nx = x + dx * m;
		ld ny = y + dy * m;
		if (nx * nx + ny * ny <= d * d)
			br = m;
		else
			bl = m;
	}
	ld l = br + tl;
	bl = t;
	br = tr - tl;
	for (int it = 0; it < IT2; ++it) {
		ld m = (bl + br) / 2;
		ld nx = x + dx * m;
		ld ny = y + dy * m;
		if (nx * nx + ny * ny <= d * d)
			bl = m;
		else
			br = m;
	}
	ld r = bl + tl;
	while (lst + T <= l)
		lst += T;
	while (lst + T <= r) {
		if (l - lst + eps < T - eps)
			vv.push_back(make_pair(l - lst + eps, T - eps));
		lst += T;
		l = lst;
	}
	if (l - lst + eps < r - lst - eps)
		vv.push_back(make_pair(l - lst + eps, r - lst - eps));
}

pair<ld, ld> getd(int k) {
	ld dx = 0;
	ld dy = 0;
	if (pp[k + 1].first > pp[k].first)
		dx = 1;
	if (pp[k + 1].first < pp[k].first)
		dx = -1;
	if (pp[k + 1].second > pp[k].second)
		dy = 1;
	if (pp[k + 1].second < pp[k].second)
		dy = -1;
	return make_pair(dx, dy);
}

int check(ld d) {
	lst = 0;
	vv.clear();
	ld nl2 = 0;
	int now2 = 0;
	ld hv2 = 0;
	while (true) {
		if (nl2 + len[now2] <= T)
			nl2 += len[now2], ++now2;
		else
			break;
	}
	hv2 = len[now2];
	hv2 -= T - nl2;
	nl2 = T;
	ld nl1 = 0;
	vv.clear();
	for (int i = 0; i < n; ++i) {
		ld hv = len[i];
		while (hv > hv2) {
			pair<ld, ld> g1 = getd(i);
			pair<ld, ld> g2 = getd(now2);
		add(nl1, nl1 + hv2, pp[now2 + 1].first - g2.first * hv2  - (pp[i + 1].first - g1.first * hv), pp[now2 + 1].second - g2.second * hv2 - (pp[i + 1].second - g1.second * hv), g2.first - g1.first, g2.second - g1.second, d);
			nl1 += hv2;
			hv -= hv2;
			++now2;
			hv2 = len[now2];
		}
		pair<ld, ld> g1 = getd(i);
		pair<ld, ld> g2 = getd(now2);
		add(nl1, nl1 + hv, pp[now2 + 1].first - g2.first * hv2  - (pp[i + 1].first - g1.first * hv), pp[now2 + 1].second - g2.second * hv2 - (pp[i + 1].second - g1.second * hv), g2.first - g1.first, g2.second - g1.second, d);
		hv2 -= hv;
		nl1 += hv;
	}
	int now = 0;
	ev.clear();
	for (int i = 0; i < vv.size(); ++i)
		ev.push_back(make_pair(vv[i].first, 1));
	for (int i = 0; i < vv.size(); ++i)
		ev.push_back(make_pair(vv[i].second, -1));
	sort(ev.begin(), ev.end());
	for (int i = 0; i < ev.size(); ++i) {
		now += ev[i].second;
		if (now == m)
			return 1;
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		pp.push_back(make_pair(x, y));
	}
	for (int i = 0; i < n; ++i)
		pp.push_back(pp[i]);
	for (int i = 0; i < n; ++i)
		pp.push_back(pp[i]);
	for (int i = 0; i < 3 * n; ++i)
		len[i] = abs(pp[i].first - pp[i + 1].first) + abs(pp[i].second - pp[i + 1].second);
	for (int i = 0; i < n; ++i)
		T += len[i];
	T /= m;
	ld l = 0;
	ld r = 4000;
	int fl = 0;
	if (check(1))
		r = 1, fl = 0;
	else
		l = 1, fl = 1;
	for (int it = 0; it < IT0; ++it) {
		ld mid;
		if (fl)
			mid = sqrt(l * r);
		else
			mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << (l + r) / 2;
	return 0;
}