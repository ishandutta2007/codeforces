#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const int N = 2005;

inline void addmin(double &x, double y) { x = min(x, y); }

struct ele {
	double l, r;
	ele (double a = 0, double b = 0) : l(a), r(b) {}
	bool operator < (const ele A) const { return l < A.l; }
} ran[N * N], good[N * N];

double ans = 1e20;
double mx_t[N], mn_t[N];
int l[N], r[N], y[N], mx[N], mn[N];
int n, mx_len, mn_len, len, glen;

void solve() {
	mx_t[1] = mn_t[1] = 0; mx[1] = mn[1] = 1; mx_len = mn_len = 1;
	for (int i = 2; i <= n; i++) {
		if (r[i] >= r[mx[1]]) mx[1] = i;
		if (l[i] <= l[mn[1]]) mn[1] = i;
	}
	while (1) {
		double minn; int id = 0;
		for (int i = 1; i <= n; i++) {
			if (y[i] > y[mx[mx_len]]) {
				double ang = (double)(r[mx[mx_len]] - r[i]) / (y[i] - y[mx[mx_len]]);
				if (!id) id = i, minn = ang;
				else if (ang < minn) minn = ang, id = i;
			}
		}
		if (!id) break;
		mx_t[++mx_len] = minn; mx[mx_len] = id;
	}
	while (1) {
		double minn; int id = 0;
		for (int i = 1; i <= n; i++) {
			if (y[i] < y[mn[mn_len]]) {
				double ang = (double)(l[mn[mn_len]] - l[i]) / (y[i] - y[mn[mn_len]]);
				if (!id) id = i, minn = ang;
				else if (ang < minn) minn = ang, id = i;
			}
		}
		if (!id) break;
		mn_t[++mn_len] = minn; mn[mn_len] = id;
	}
	len = glen = 0;
	bool ban_zero = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (y[i] == y[j]) continue;
			if (max(l[i], l[j]) < min(r[i], r[j])) ban_zero = 1;
			int _x = i, _y = j;
			if (y[_x] < y[_y]) swap(_x, _y);
			if (l[_x] >= r[_y]) continue;
			double L = 0, R = (double)(r[_y] - l[_x]) / (y[_x] - y[_y]);
			if (r[_x] <= l[_y]) L = (double)(l[_y] - r[_x]) / (y[_x] - y[_y]);
			ran[++len] = ele(L, R);
		}
	}
	sort(ran + 1, ran + len + 1);
	double las = ban_zero ? 1e-7 : 0;
	for (int l = 1, r; l <= len; l = r + 1) {
		if (las <= ran[l].l + eps) good[++glen] = ele(las, ran[l].l);
		las = ran[l].r;
		r = l;
		while (r < len && las >= ran[r + 1].l + eps) ++r, las = max(las, ran[r].r);
	}
	good[++glen] = ele(las, 2e12); mx_t[mx_len + 1] = mn_t[mn_len + 1] = 3e12;
	int mx_now = 1, mn_now = 1;
	for (int i = 1; i <= glen; i++) {
		// printf("%.6lf %.6lf\n", good[i].l, good[i].r);
		while (mx_t[mx_now + 1] <= good[i].l) ++mx_now;
		while (mn_t[mn_now + 1] <= good[i].l) ++mn_now;
		while (1) {
			double L = max(max(mx_t[mx_now], mn_t[mn_now]), good[i].l);
			double R = min(min(mx_t[mx_now + 1], mn_t[mn_now + 1]), good[i].r);
			addmin(ans, r[mx[mx_now]] + y[mx[mx_now]] * L - l[mn[mn_now]] - y[mn[mn_now]] * L);
			addmin(ans, r[mx[mx_now]] + y[mx[mx_now]] * R - l[mn[mn_now]] - y[mn[mn_now]] * R);
			if (mx_t[mx_now + 1] <= mn_t[mn_now + 1]) {
				if (mx_t[mx_now + 1] >= good[i].r) break;
				++mx_now;
			} else {
				if (mn_t[mn_now + 1] >= good[i].r) break;
				++mn_now;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d%d", &l[i], &r[i], &y[i]);
	solve();
	for (int i = 1; i <= n; i++) swap(l[i], r[i]), l[i] = -l[i], r[i] = -r[i];
	solve();
	printf("%.10lf\n", ans);
	return 0;
}