// MoRanSky
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void inline read(T &x) {
	x = 0; int f = 1; char s = getchar();
	while (s > '9' || s < '0') { if (s == '-') f = -1; s = getchar(); }
	while (s >= '0' && s <= '9') x = x * 10 + (s ^ 48), s = getchar();
	x *= f;
}

template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }
template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }

const int N = 1e5 + 5;

int n, d, b;
LL a[N], c[N];

bool inline work(int l, int r) {
	for (int i = l, j = 1; i <= r; i++) {
		LL nd = b;
		while (nd) {
			while (!c[j]) j++;
			LL t = min(nd, c[j]);
			c[j] -= t, nd -= t;
			LL tm = (abs(j - i) + d - 1) / d;
			if (tm > min(i, n - i + 1)) return 0;
		}
	}
	return 1;
}

bool inline chk(int x) {
	int L, R, X, Y;
	R = (n + 1) / 2, X = R + 1;
	L = x + 1, Y = n - x;
	if (L > R || X > Y) return 1;
	LL nd = (R - L + 1) * b;
	for (int i = 1; i <= n; i++) {
		LL t = min(a[i], nd);
		c[i] = t;
		nd -= t;
		if (!nd) break;
	}
	if (!work(L, R)) return 0;
	nd = (Y - X + 1) * b;
	for (int i = n; i; i--) {
		LL t = min(a[i], nd);
		c[i] = t;
		nd -= t;
		if (!nd) break;
	}
	if (!work(X, Y)) return 0;
	return 1;
}

int main() {
	read(n), read(d), read(b);
	for (int i = 1; i <= n; i++) read(a[i]);
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (chk(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", r);

}