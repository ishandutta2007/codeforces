#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

struct point {
	int x, y, id, type;
	point(int x = 0,int y = 0,int id = 0,int type = 0) : x(x), y(y), id(id), type(type) {}
	point operator - (const point &p) const {
		return point(x - p.x, y - p.y, id, type);
	}
	int operator * (const point &p) const {
		return x * p.y - y * p.x;
	}
};

bool cmp(point p, point q) {
	return p * q > 0;
}

int n;
point a[N + N];
int ans[N + N];

void add(int u,int v) {
	ans[u] = v;
	ans[v] = u;
}

void solve(int l,int r) {
	if (l + 1 == r) {
		add(a[l].id, a[r].id);
		return;
	}
	for (int i = l + 1; i <= r; ++i) {
		if (a[i].x < a[l].x) {
			swap(a[l], a[i]);
		}
	}
	point root = a[l];
	for (int i = l; i <= r; ++i) {
		a[i] = a[i] - root;
	}
	sort(a + l + 1, a + r + 1, cmp);
	int last = l + 1;
	int sum = 0;
	for (int i = l + 1; i < r; ++i) {
		sum += a[i].type;
		if (sum == 0) {
			solve(last, i);
			last = i + 1;
		}
	}
	add(a[l].id, a[last].id);
	if (last + 1 < r) {
		solve(last + 1, r);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &a[i].x, &a[i].y);
		a[i].id = i;
		a[i].type = 1;
	}
	for (int i = n + 1; i <= n + n; ++i) {
		scanf("%d %d", &a[i].x, &a[i].y);
		a[i].id = i;
		a[i].type = -1;
	}
	solve(1, n + n);
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", ans[i] - n);
	}
}