# include <cstdio>
# include <iostream>
using namespace std;
#define lc ((u) << 1)
#define rc ((u) << 1 | 1)

const int maxn = 1<<18;
int x[maxn], y[maxn], c[maxn], p, t;

void update(int u,int l,int r) {
	if(l == r) {
		c[l] == -1 ? x[u] = 1 : y[u] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	(p <= mid) ?  update(lc, l, mid) : update(rc, mid + 1, r);
	x[u] = x[lc], y[u] = y[rc];
	(y[lc] >= x[rc]) ? y[u] += y[lc] - x[rc] : x[u] += x[rc] - y[lc];
}

int query(int u,int l,int r,int p) {
	if(l == r) return c[l];
	int mid = (l + r) >> 1;
	return (y[rc] < p) ?
		query(lc, l, mid, p - y[rc] + x[rc]) :
		query(rc, mid + 1, r, p);
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &p, &t);
		if(t == 1) {
			int x;
			scanf("%d", &x);
			c[p] = x;
		} else {
			c[p] = -1;
		}
		update(1, 1, n);
		if(y[1] < 1) {
			puts("-1");
		} else {
			printf("%d\n", query(1, 1, n, 1));
		}
	}
	return 0;
}