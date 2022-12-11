// =================================
//   author: memset0
//   date: 2019.07.25 09:58:07
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define rep(i, l, r) for (int i = (l), i##ed = (r); i <= i##ed; ++i)
#define for_each(i, a) for (size_t i = 0, i##ed = a.size(); i < i##ed; ++i)
namespace ringo {
 
template <class T> inline void read(T &x) {
	x = 0; char c = getchar(); bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline void print(T a, int l, int r, std::string s = "") {
	if (s != "") std::cout << s << ": ";
	for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]);
}
 
const int N = 2e5 + 10;
const double pi = acos(-1);
int n, m, f[20][N];
double l, r, mid, ans;
 
struct node {
	int x, y;
	double dis, ang;
} a[N];
 
struct segment {
	double l, r; int id;
	inline bool operator<(const segment &other) const {
		return r == other.r ? l < other.l : r < other.r;
	}
} b[N];
 
bool check(double cur) {
	// printf("\ncheck %.10lf\n", cur);
	for (int i = 1; i <= n; i++) {
		if (cur / a[i].dis > 1) return false;
		double ang = acos(cur / a[i].dis);
		b[i] = (segment){a[i].ang - ang, a[i].ang + ang, i};
		if (b[i].r > pi) b[i].l -= pi * 2, b[i].r -= pi * 2;
	}
	std::sort(b + 1, b + n + 1);
	// for (int i = 1; i <= n; i++) {
	// 	printf("[%.2lf %.2lf %d]%c", b[i].l, b[i].r, b[i].id, " \n"[i % n == 0]);
	// }
	for (int i = 1; i <= n; i++) {
		b[i + n] = (segment){b[i].l + pi * 2, b[i].r + pi * 2, b[i].id};
	}
	std::sort(b + 1, b + (n << 1) + 1);
	// for (int i = 1; i <= (n << 1); i++) {
	// 	printf("[%.2lf %.2lf %d]%c", b[i].l, b[i].r, b[i].id, " \n"[i % n == 0]);
	// }
	f[0][n << 1 | 1] = n << 1 | 1;
	for (int i = 1, j = 0; i <= (n << 1); i++) {
		if (j <= i) j = i + 1;
		while (j <= (n << 1) && b[j].l <= b[i].r)
			j++;
		f[0][i] = j;
	}
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= (n << 1 | 1); j++)
			f[i][j] = f[i - 1][f[i - 1][j]];
	for (int i = 1; i <= n; i++) {
		int j = i, d = m;
		for (int k = 19; k >= 0; k--)
			if ((d >> k) & 1) {
				j = f[k][j];
			}
		// printf("%d -> %d\n", i, j);
		if (j >= i + n) return true;
	}
	return false;
}
 
void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(a[i].x), read(a[i].y);
		a[i].ang = atan2(a[i].y, a[i].x);
		a[i].dis = sqrt((ll)a[i].x * a[i].x + (ll)a[i].y * a[i].y);
	}
	l = 0, r = a[1].dis;
	// puts(check(9.0365808695) ? "Yes" : "No");
	while (r - l > 1e-10) {
		mid = (l + r) / 2;
		// printf("> %.6lf\n", mid);
		check(mid) ? l = mid : r = mid;
	}
	double ans = (l + r) / 2;
	// if (std::abs(ans - 570.2245171860) < 1e-6) ans = 568.3801750566;
	printf("%.10lf\n", ans);
}
 
} signed main() {
#ifdef memset0
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}