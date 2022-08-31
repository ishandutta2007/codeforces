#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
// int read() {
// 	char c;
// 	while (gc < '-')
// 		;
// 	if (c == '-') {
// 		int x = gc - '0';
// 		while (gc >= '0') x = x * 10 + c - '0';
// 		return -x;
// 	}
// 	int x = c - '0';
// 	while (gc >= '0') x = x * 10 + c - '0';
// 	return x;
// }
#undef gc

static char ibuf[1 << 20];
char *fis = ibuf, *fit = ibuf;
inline char readChar() { return fis == fit && (fit = (fis = ibuf) + fread(ibuf, 1, 1 << 20, stdin), fis == fit) ? EOF : *fis++; }
inline int read() {
	char c = readChar();
	int n = 0;
	while (c < '0' || c > '9') { c = readChar(); }
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c & 15);
		c = readChar();
	}
	return n;
}
static char obuf[1 << 20];
int ol = 0;
char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) {
	*fos++ = c;
	if (fos == fot) {
		fwrite(obuf, 1, fos - obuf, stdout);
		fos = obuf;
	}
}

struct FastMod {
	typedef unsigned long long ULL;
	typedef __uint128_t LLL;
	ULL b, m;
	void init(ULL b) { this->b = b, m = ULL((LLL(1) << 64) / b); }
	ULL operator()(ULL a) {
		ULL q = (ULL)((LLL(m) * a) >> 64);
		ULL r = a - q * b;
		return r >= b ? r - b : r;
	}
} M;

const int N = 3e5 + 5;

struct ff {
	int f1, f2, len;
	ff(int a = 0, int b = 0, int c = 0): f1(a), f2(b), len(c) {}
} t[N << 2], tag[N << 2];

int f[N], a[N], b[N];
int n, q, p;

inline int add(int x, int y) {
	return x + y >= p ? x + y - p : x + y;
}

int calc(int n, int f1, int f2) {
	return M(1ull * f1 * f[n - 2] + 1ull * f2 * f[n - 1]);
}

ff merge(ff a, ff b) {
	if (a.f1 == -1 || b.f1 == -1) return ff(-1);
	if (a.len == 1 && b.len == 1) {
		return ff(a.f1, b.f1, 2);
	}
	if (a.len == 1) {
		if ((a.f1 + b.f1) % p == b.f2) return ff(a.f1, b.f1, a.len + b.len);
		return ff(-1);
	}
	if (calc(a.len + 1, a.f1, a.f2) != b.f1) return ff(-1);
	if (b.len != 1 && calc(a.len + 2, a.f1, a.f2) != b.f2) return ff(-1);
	return ff(a.f1, a.f2, a.len + b.len);
}

void add_tag(int u, ff x) {
	tag[u].f1 = add(tag[u].f1, x.f1);
	tag[u].f2 = add(tag[u].f2, x.f2);
	if (t[u].f1 != -1) {
		t[u].f1 = add(t[u].f1, x.f1);
		t[u].f2 = add(t[u].f2, x.f2);
	}
}

void pushdown(int u, int l, int r) {
	int mid = (l + r) >> 1;
	add_tag(u << 1, tag[u]);
	ff tmp = ff(calc(mid - l + 2, tag[u].f1, tag[u].f2), calc(mid - l + 3, tag[u].f1, tag[u].f2));
	add_tag(u << 1 | 1, tmp);
	tag[u].f1 = tag[u].f2 = 0;
}

void update(int u) {
	t[u] = merge(t[u << 1], t[u << 1 | 1]);
}

void build(int u, int l, int r) {
	tag[u] = ff(0, 0, r - l + 1);
	if (l == r) {
		t[u] = ff(a[l], 0, 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	update(u);
}

void change(int u, int L, int R, int l, int r, int opt) {
	if (l <= L && R <= r) {
		if (opt == 1) {
			add_tag(u, ff(f[L - l + 1], f[L - l + 2]));
		} else {
			add_tag(u, ff(f[L - l + 1] ? p - f[L - l + 1] : 0, f[L - l + 2] ? p - f[L - l + 2] : 0));
		}
		return;
	}
	pushdown(u, L, R);
	int mid = (L + R) >> 1;
	if (mid >= l) change(u << 1, L, mid, l, r, opt);
	if (mid + 1 <= r) change(u << 1 | 1, mid + 1, R, l, r, opt);
	update(u);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	q = read();
	p = read();
	M.init(p);
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[i] = read(), a[i] = (a[i] - b[i] + p) % p;
	f[1] = f[2] = 1;
	for (int i = 3; i <= n + 2; i++) f[i] = (f[i - 1] + f[i - 2]) % p;
	build(1, 1, n);
	while (q--) {
		char c = readChar();
		while (c != 'A' && c != 'B') c = readChar();
		int l = read(), r = read();
		change(1, 1, n, l, r, c == 'A');
		if (t[1].f1 == 0 && (n == 1 || t[1].f2 == 0))
			writeChar('Y'), writeChar('E'), writeChar('S');
		else
			writeChar('N'), writeChar('O');
		writeChar('\n');
	}
	fwrite(obuf, 1, fos - obuf, stdout);
}