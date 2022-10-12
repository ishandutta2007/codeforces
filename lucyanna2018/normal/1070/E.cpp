#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
#define i64 long long int
struct Node {
	i64 cnt, sum;
} a[200111 * 4];
void build(int i, int s, int e) {
	a[i].cnt = a[i].sum = 0;
	if (s == e)return;
	int m = (s + e) / 2;
	build(i * 2, s, m);
	build(i * 2 + 1, m + 1, e);
}
void ins(int i, int s, int e, int x, int y) {
	if (s == e) {
		a[i].cnt ++;
		a[i].sum += y;
		return;
	}
	int  m = (s + e) / 2;
	if (x <= m)ins(i * 2, s, m, x, y);else
		ins(i * 2 + 1, m + 1, e, x, y);
	a[i].cnt = a[i * 2].cnt + a[i * 2 + 1].cnt;
	a[i].sum = a[i * 2].sum + a[i * 2 + 1].sum;
}
i64 query(int i, int s, int e, i64 c) {
	if (c == 0)return 0;
	if (s == e) return a[i].sum;
	int m = (s + e) / 2;
	if (a[i * 2].cnt <= c)
		return a[i * 2].sum + query(i * 2 + 1, m + 1, e, c - a[i * 2].cnt);
	else
		return query(i * 2, s, m, c);
}

int n, m;
i64 T;
pair<int, int> c[200020];
i64 calc(int X) {
	if (X == 0)return 0;
	return query(1, 0, n - 1, X) + query(1, 0, n - 1, (X-1) / m * m);
}
int main() {
	ios::sync_with_stdio(false);
	int _;
	for (cin >> _; _--;) {
		cin >> n >> m >> T;
		for (int i = 0; i < n; i++) {
			cin >> c[i].first;
			c[i].second = i;
		}
		sort(c, c + n);
		build(1, 0, n - 1);
		int bes = 0;
		i64 besi = 1;
		for (int i = 0, i2; i < n; i=i2) {
			for (i2 = i; i2 < n && c[i2].first == c[i].first; i2++) {
				ins(1, 0, n - 1, c[i2].second, c[i2].first);
			}
			int lo = 0, hi = i2;
			while (lo != hi) {
				int mi = (lo + hi + 1) / 2;
//				cout << mi << " " << calc(mi) << endl;
				if (calc(mi) <= T)
					lo = mi;
				else
					hi = mi - 1;
			}
			if (lo > bes) {
				bes = lo;
				besi = c[i].first;
			}
		}
		cout //<< "#" 
		<< bes << " " << besi << endl;
	}
	return 0;
}