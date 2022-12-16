#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned int ui;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

int gcd(int a, int b) {
    int az = __builtin_ctz(a);
    int bz = __builtin_ctz(b);
    int z = min(az, bz);
    b >>= bz;
    while (a) {
        a >>= az;
        int diff = a - b;
        az = __builtin_ctz(diff);
        b = min(a, b), a = abs(diff);
    }
    return b << z;
}
const int maxn = 5e4 + 10, A = 5e4, T = 64, maxp = 1000;
int n, q, m, a[maxn], b[maxn], lb[maxp], rb[maxp], bel[maxn], cov[maxp];
vi e[maxn];
ui mn[maxp], ansb[maxp][maxn];
ui val(int i) { ui d = gcd(a[i], b[i]); return (a[i] / d) * (b[i] / d); }

void calcans(int o) {
	for (int i = 1; i <= A; ++i) ansb[o][i] = UINT_MAX;
	for (int i = lb[o]; i <= rb[o]; ++i)
		for (ui x : e[b[i]])
			ansb[o][x] = min(ansb[o][x], b[i] / x);
	for (ui i = 1; i <= A; ++i)
		for (ui x : e[i]) ansb[o][i] = min(ansb[o][i], ansb[o][x] * (i / x));
}
void calc(int o) {
	if (cov[o]) mn[o] = ansb[o][cov[o]];
	else {
		mn[o] = UINT_MAX;
		for (int i = lb[o]; i <= rb[o]; ++i) mn[o] = min(mn[o], val(i));
	}
}

void prework() {
	for (ui i = 1; i <= A; ++i)
		for (ui j = i; j <= A; j += i)
			e[j].push_back(i);
	for (int i = 1; i <= n; ++i) bel[i] = (i - 1) / T + 1;
	m = bel[n];
	for (int i = 1; i <= m; ++i) {
		lb[i] = rb[i - 1] + 1, rb[i] = min(n, lb[i] + T - 1);
		calc(i), calcans(i);
	}
}

void push_down(int o) {
	if (!cov[o]) return;
	for (int i = lb[o]; i <= rb[o]; ++i) a[i] = cov[o];
	cov[o] = 0;
}
void tag(int o, int x) { cov[o] = x, calc(o); }

void update(int l, int r, int x) {
	int p = bel[l], q = bel[r];
	push_down(p), push_down(q);
	if (p == q) {
		for (int i = l; i <= r; ++i) a[i] = x;
		return calc(p);
	}
	for (int i = l; i <= rb[p]; ++i) a[i] = x;
	for (int i = lb[q]; i <= r; ++i) a[i] = x;
	calc(p), calc(q);
	for (int i = p + 1; i < q; ++i) tag(i, x);
}

ui query(int l, int r) {
	int p = bel[l], q = bel[r]; ui res = UINT_MAX;
	push_down(p), push_down(q);
	if (p == q) {
		for (int i = l; i <= r; ++i) res = min(res, val(i));
		return res;
	}
	for (int i = l; i <= rb[p]; ++i) res = min(res, val(i));
	for (int i = lb[q]; i <= r; ++i) res = min(res, val(i));
	for (int i = p + 1; i < q; ++i) res = min(res, mn[i]);
	return res;
}

int main() {
	read(n, q);
	for (int i = 1; i <= n; ++i) read(a[i]);
	for (int i = 1; i <= n; ++i) read(b[i]);
	prework();
	while (q--) {
		int op, l, r, x; read(op, l, r);
		if (op == 1) read(x), update(l, r, x);
		else write(query(l, r), '\n');
	}
	return 0;
}