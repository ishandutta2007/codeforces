#include<cstdio>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
using namespace std;
#define i64 long long int
struct Node {
	i64 cnt, sum;
} a[1000111 * 4];
void ins(int i, int s, int e, int x, int y) {
	if (s == e) {
		a[i].cnt += y;
		a[i].sum += (i64)x * y;
		return;
	}
	int  m = (s + e) / 2;
	if (x <= m)ins(i * 2, s, m, x, y);else
		ins(i * 2 + 1, m + 1, e, x, y);
	a[i].cnt = a[i * 2].cnt + a[i * 2 + 1].cnt;
	a[i].sum = a[i * 2].sum + a[i * 2 + 1].sum;
}
i64 query(int i, int s, int e, i64 c) {
	if (s == e) {
		return min(c, a[i].cnt) * s;
	}
	int m = (s + e) / 2;
	if (a[i * 2].cnt <= c)
		return a[i * 2].sum + query(i * 2 + 1, m + 1, e, c - a[i * 2].cnt);
	else
		return query(i * 2, s, m, c);
}

struct Z {
	int d, price, cnt;
} c[202222 * 2];
int lc;
bool cmp(Z x, Z y) {
	return x.d < y.d;
}
int main() {
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	while (m--) {
		int A, B, C, D;
		scanf("%d%d%d%d", &A, &B, &C, &D);
		c[lc].d = A;
		c[lc].price = D;
		c[lc++].cnt = C;
		c[lc].d = B+1;
		c[lc].price = D;
		c[lc++].cnt = -C;
	}
	sort(c, c + lc, cmp);
	int pnt = 0;
	i64 res = 0;
	for (int i = 1; i <= n; i++) {
		for (; pnt < lc && c[pnt].d <= i; pnt++) {
			ins(1, 1, 1000000, c[pnt].price, c[pnt].cnt);
		}
		res += query(1, 1, 1000000, k);
	}
	cout << res << endl;
	return 0;
}