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
typedef long double ld;

using namespace std;
const int MAXN = 210000;


struct point {
	ll x, y;
	point(ll x = 0, ll y = 0): x(x), y(y) {}
	point operator+(point a) {
		return point(x + a.x, y + a.y);
	}
	point operator-(point a) {
		return point(x - a.x, y - a.y);
	}
	ll operator*(point a) {
		return x * a.y - y * a.x;
	}
};


bool cmp(point a, point b) {
	if (a.y >= 0 && b.y < 0)
		return 1;
	if (a.y < 0 && b.y >= 0)
		return 0;
	if (a.y == 0 && b.y == 0) {
		if (a.x >= 0 && b.x < 0)
			return 1;
		else
			return 0;
	}
	return a * b > 0;
}

struct hp {
	ll a, b, c;
	int n;
	hp(point x, point y) {
		a = x.y - y.y;
		b = y.x - x.x;
		c = a * x.x + b * x.y;
		n = 0;
	}
};

int n;
point p[MAXN];
vector<hp> vv;
point q[MAXN * 2];

bool cmp2(hp a, hp b) {
	point pa = point(a.a, a.b);
	point pb = point(b.a, b.b);
	if (pa.y >= 0 && pb.y < 0)
		return  1;
	if (pa.y < 0 && pb.y >= 0)
		return 0;
	if (pa.y == 0 && pb.y == 0) {
		if (pa.x >= 0 && pb.x < 0)
			return 1;
		if (pa.x < 0 && pb.x >= 0)
			return 0;
	}
	ll k = pa * pb;
	if (k > 0)
		return 1;
	if (k < 0)
		return 0;
	return a.c < b.c;
}

struct pointr {
	ld x, y;
	pointr(ld x, ld y): x(x), y(y) {}
	pointr operator+(pointr a) {
		return pointr(x + a.x, y + a.y);
	}
	pointr operator-(pointr a) {
		return pointr(x - a.x, y - a.y);
	}
	ld operator*(pointr a) {
		return x * a.y - y * a.x;
	}
};

pointr cross(hp a, hp b) {
	ld d = a.a * b.b - a.b * b.a;
	ld dx = a.c * b.b - a.b * b.c;
	ld dy = a.a * b.c - a.c * b.a;
	return pointr(dx / d, dy / d);
}

vector<pointr> pp;
int en[700000];

bool bad(hp a, hp b, hp c) {
	pointr xx = cross(b, c);
	return xx.x * a.a + xx.y * a.b <= a.c;
}

bool bd2(hp a, hp b) {
	if (a.a * b.b - a.b * b.a != 0)
		return 0;
	if (a.a * b.a + a.b * b.b <= 0)
		return 0;
	if (a.a != 0) {
		ld c1 = a.c / abs(a.a);
		ld c2 = b.c / abs(b.a);
		if (c1 <= c2)
			return 1;
	}
	else {
		ld c1 = a.c / abs(a.b);
		ld c2 = b.c / abs(b.b);
		if (c1 <= c2)
			return 1;
	}
	return 0;
}

ld calc() {
	sort(vv.begin(), vv.end(), cmp2);
	vector<hp> st;
	for (int i = 0; i < vv.size(); ++i)
		vv[i].n = i;
	for (int i = 0; i < vv.size(); ++i) {
		while (true) {
			if (st.empty())
				break;
			if (bd2(st.back(), vv[i])) {
				st.pop_back();
				continue;
			}
			if (st.size() >= 2 && bad(st[st.size() - 2], st.back(), vv[i])) {
				st.pop_back();
				continue;
			}
			break;
		}
		st.push_back(vv[i]);
	}
	for (int i = 0; i < vv.size(); ++i) {
		while (true) {
			if (st.empty())
				break;
			if (bd2(st.back(), vv[i])) {
				st.pop_back();
				continue;
			}
			if (st.size() >= 2 && bad(st[st.size() - 2], st.back(), vv[i])) {
				st.pop_back();
				continue;
			}
			break;
		}
		st.push_back(vv[i]);
	}
	for (int i = 0; i < vv.size(); ++i)
		en[i] = -1;
	vv.clear();
	for (int i = 0; i < st.size(); ++i) {
		if (en[st[i].n] != -1) {
			for (int j = en[st[i].n]; j <= i; ++j)
				vv.push_back(st[j]);
			break;
		}
		en[st[i].n] = i;
	}
	pp.clear();
	for (int i = 0; i < vv.size() - 1; ++i)
		pp.push_back(cross(vv[i], vv[i + 1]));
	pp.push_back(pp[0]);
	ld sum = 0;
	for (int i = 0; i < pp.size() - 1; ++i)
		sum += pp[i] * pp[i + 1];
	sum /= 2;
	return abs(sum);
}

const int BR = 1000000;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", &p[i].x, &p[i].y);
	for (int i = 1; i < n; ++i)
		q[i - 1] = p[i] - p[0];
	sort(q, q + n - 1, cmp);
	for (int i = 0; i < n - 1; ++i)
		q[i + n - 1] = q[i];
	vv.clear();
	for (int i = 0; i < n - 1; ++i) {
		if (q[i] * q[i + 1] == 0) {
			printf("0\n");
			return;
		}
	}
	int now = 0;
	for (int i = 0; i < n - 1; ++i) {
		now = max(now, i + 1);
		while (now < i + n - 1 && q[i] * q[now] > 0)
			++now;
		if (now != i + n - 1 && q[i] * q[now] == 0) {
			printf("0\n");
			return;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		hp x = hp(q[i] + p[0], q[i + 1] + p[0]);
		if (x.a * p[0].x + x.b * p[0].y < x.c) {
			x.a = -x.a;
			x.b = -x.b;
			x.c = -x.c;
		}
		vv.push_back(x);
	}
	now = 0;
	for (int i = 0; i < n - 1; ++i) {
		while (now + 1 < i + n - 1 && q[i] * q[now + 1] >= 0)
			++now;
		if (now != i)
			vv.push_back(hp(q[i] + p[0], q[now] + p[0]));
	}
	reverse(q, q + n - 1 + n - 1);
	now = 0;
	for (int i = 0; i < n - 1; ++i) {
		while (now + 1 < i + n - 1 && q[i] * q[now + 1] <= 0)
			++now;
		if (now != i)
			vv.push_back(hp(q[now] + p[0], q[i] + p[0]));
	}
	vv.push_back(hp(point(-BR, -BR), point(BR, -BR)));
	vv.push_back(hp(point(BR, -BR), point(BR, BR)));
	vv.push_back(hp(point(BR, BR), point(-BR, BR)));
	vv.push_back(hp(point(-BR, BR), point(-BR, -BR)));
	printf("%.9Lf\n", calc());
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int i = 0; i < tt; ++i) {
		solve();
	}
	return 0;
}