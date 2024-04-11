#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 2e5 + 5, P = 1e9 + 7;

int n, q, a[N], w[N];

LL s[N << 2][2];

#define ls (p << 1)
#define rs (p << 1 | 1)

void inline pushup(int p) {
	s[p][0] = s[ls][0] + s[rs][0];
	s[p][1] = (s[ls][1] + s[rs][1]) % P;
}

void build(int p, int l, int r) {
	if (l == r) {
		s[p][0] = w[r], s[p][1] = 1ll * w[r] * a[r] % P;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}

void change(int p, int l, int r, int x) {
	if (l == r) {
		s[p][0] = w[r], s[p][1] = 1ll * a[r] * w[r] % P;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) change(ls, l, mid, x);
	else change(rs, mid + 1, r, x);
	pushup(p);
}

typedef pair<LL, LL> PLL;

PLL operator + (PLL a, PLL b) {
	return mp(a.fi + b.fi, (a.se + b.se) % P);
}

PLL inline query(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return mp(s[p][0], s[p][1]);
	int mid = (l + r) >> 1;
	PLL res = mp(0, 0);
	if (x <= mid) res = res + query(ls, l, mid, x, y);
	if (mid < y) res = res + query(rs, mid + 1, r, x, y);
	return res;
}

LL md, k;

LL inline kth(int p, int l, int r, int x, int y) {
	if (!k) return 0;
	
	if (s[p][0] >= k && l == r) {
		md = a[r];
		LL gx = k * a[r] % P;
		k = 0;
		return gx;
	}
	
	int mid = (l + r) >> 1;
	
	if (x <= l && r <= y) {
		if (s[p][0] < k) {
			k -= s[p][0];
			return s[p][1];
		}
		if (k <= s[ls][0]) {
			return kth(ls, l, mid, x, y);
		} else {
			k -= s[ls][0];
			return (s[ls][1] + kth(rs, mid + 1, r, x, y)) % P;
		}
	}
	
	LL res = 0;
	if (y <= mid) {
		return kth(ls, l, mid, x, y);
	} else if (x > mid) {
		return kth(rs, mid + 1, r, x, y);
	} else {
		res = kth(ls, l, mid, x, y);
		if (k) {
			res = (res + kth(rs, mid + 1, r, x, y)) % P;
		}
	}
	
	return res;
}

int main() {
	read(n), read(q);
	for (int i = 1; i <= n; i++) read(a[i]), a[i] -= i;
	for (int i = 1; i <= n; i++) read(w[i]);
	build(1, 1, n);
	while (q--) {
		int x, y; read(x), read(y);
		if (x < 0) {
			int p = -x;
			w[p] = y;
			change(1, 1, n, p);
		} else {
			PLL u = query(1, 1, n, x, y);
			k = (u.fi + 1) >> 1;
			LL t = k;
			LL L = kth(1, 1, n, x, y);
			k = t;
			LL ans = (k % P * md % P - L + P) % P;
			LL R = (u.se - L + P) % P;
			LL num = (u.fi - k) % P;
			ans = (ans + R - num * md % P + P) % P;
			printf("%lld\n", ans);
		}
	}
}