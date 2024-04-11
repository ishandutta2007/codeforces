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


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 51000;

vector<pair<ld, int> > vv;
ld a[MAXN];
ld b[MAXN];
int rmq[MAXN * 4 * 2];
int cl[MAXN * 2];
int n;
int m;
ld x, y;


void init(ld d) {
	vv.clear();
	for (int i = 0; i < n; ++i) {
		ld a2 = a[i] * a[i] + 1;
		ld b2 = a[i] * b[i];
		ld c2 = b[i] * b[i] - d * d;
		ld di = b2 * b2 - a2 * c2;
		if (di < 0)
			continue;
		di = sqrt(di);
		ld xx = (-b2 + di) / a2;
		ld yy = a[i] * xx + b[i];
		vv.push_back(make_pair(atan2(yy, xx), i));
		xx = (-b2 - di) / a2;
		yy = a[i] * xx + b[i];
		vv.push_back(make_pair(atan2(yy, xx), i));
	}
	sort(vv.begin(), vv.end());
}

int get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return 0;
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return get(v * 2 + 1, tl, m, l, r) + get(v * 2 + 2, m, tr, l, r);
}

void add(int v, int tl, int tr, int x) {
	if (tl + 1 == tr) {
		++rmq[v];
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		add(v * 2 + 1, tl, m, x);
	else
		add(v * 2 + 2, m, tr, x);
	rmq[v] = rmq[v * 2 + 1] + rmq[v * 2 + 2];
}


ll getCnt(ld d) {
	init(d);
	memset(cl, 0, sizeof(cl[0]) * n);
	memset(rmq, 0, sizeof(rmq[0]) * n * 8);
	for (int i = 0; i < (int)vv.size(); ++i)
		cl[vv[i].second] = i;
	ll ans = 0;
	for (int i = 0; i < (int)vv.size(); ++i) {
		int xx = vv[i].second;
		if (cl[xx] != i) {
			ans += get(0, 0, (int)vv.size(), i, cl[xx]);
			add(0, 0, (int)vv.size(), cl[xx]);
		}
	}
	return ans;
}

set<pair<int, int> > ss;

ld cross(int x, int y) {
	if (x == y)
		return 0;
	if (abs(a[x] - a[y]) <= 1e-9)
		return 0;
	ld x2 = (b[y] - b[x]) / (a[x] - a[y]);
	ld y2 = a[x] * x2 + b[x];
	return sqrt(x2 * x2 + y2 * y2);
}

ld getSum() {
	ld ans = 0;
	ss.clear();
	memset(cl, 0, sizeof(cl[0]) * n);
	for (int i = 0; i < (int)vv.size(); ++i)
		cl[vv[i].second] = i;
	for (int i = 0; i < (int)vv.size(); ++i) {
		int xx = vv[i].second;
		if (cl[xx] != i) {
			auto it = ss.begin();
			while (it != ss.end() && it->first < cl[xx]) {
				ans += cross(xx, it->second);
				++it;
			}
			ss.insert(make_pair(cl[xx], xx));
		}
		else {
			ss.erase(make_pair(i, xx));
		}
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> x >> y >> m;
	x /= 1000;
	y /= 1000;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		a[i] /= 1000;
		b[i] /= 1000;
		b[i] += x * a[i] - y;
	}
	ld l = 0;
	ld r = 3e9;
	for (int it = 0; it < 60; ++it) {
		ld mid = (l + r) / 2;
		if (getCnt(mid) < m)
			l = mid;
		else
			r = mid;
	}
	cout.setf(ios::fixed);
	cout.precision(10);
	if (getCnt(l) >= m) {
		if (l < 1e-7) {
			cout << 0 << "\n";
			return 0;
		}
		l -= 1e-8;
		while (getCnt(l) >= m)
			l -= 1e-8;
	}
	cout << getSum() + l * (m - getCnt(l)) << "\n";
	return 0;

}