#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int md = 1e9 + 7;

inline int mul(int x, int y) { return (ll)x * y % md; }

inline int add(int x, int y) {
	x += y;
	if(x >= md) x -= md;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if(x < 0) x += md;
	return x;
}

inline int fpow(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

const int N = 1e5 + 5;

struct mat { int a[2][2]; } unit, fib_unit;

void print(mat x) {
	fprintf(stderr, "mat : \n");
	rep(i, 0, 1) rep(j, 0, 1)
		print(x.a[i][j], j == 1 ? '\n' : ' ');
	fprintf(stderr, "mat end\n"); 
}

void init_mat() { 
	unit.a[0][0] = unit.a[1][1] = 1; unit.a[0][1] = unit.a[1][0] = 0; 
	fib_unit.a[0][0] = fib_unit.a[0][1] = fib_unit.a[1][0] = 1; fib_unit.a[1][1] = 0; 
}

mat operator + (const mat a, const mat b) {
	mat ans; memset(ans.a, 0, sizeof(ans.a));
	rep(i, 0, 1) rep(j, 0, 1) ans.a[i][j] = add(a.a[i][j], b.a[i][j]);
	return ans;
}

mat operator * (const mat a, const mat b) {
	mat ans; memset(ans.a, 0, sizeof(ans.a));
	rep(i, 0, 1) rep(j, 0, 1) rep(k, 0, 1)
		ans.a[i][j] = add(ans.a[i][j], mul(a.a[i][k], b.a[k][j]));
	return ans;
}

bool operator == (const mat a, const mat b) {
	rep(i, 0, 1) rep(j, 0, 1)
		if(a.a[i][j] != b.a[i][j]) return 0;
	return 1;
}

bool operator != (const mat a, const mat b) {
	rep(i, 0, 1) rep(j, 0, 1)
		if(a.a[i][j] != b.a[i][j]) return 1;
	return 0;
}

mat operator ^ (mat x, int y) {
	mat ans = unit;
	while(y) {
		if(y & 1) ans = ans * x;
		y >>= 1; x = x * x;
	}
	return ans;
}

struct Node { int l, r; mat sum, tag; } p[N << 2];

int a[N], n, m;

void update(int u) { p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum; }

void pushdown(int u) {
	if(p[u].tag != unit) {
		p[u << 1].sum = p[u << 1].sum * p[u].tag;
		p[u << 1 | 1].sum = p[u << 1 | 1].sum * p[u].tag;
		p[u << 1].tag = p[u << 1].tag * p[u].tag;
		p[u << 1 | 1].tag = p[u << 1 | 1].tag * p[u].tag;
		p[u].tag = unit;
	}
}

void build(int u, int l, int r) {
	p[u].l = l; p[u].r = r; p[u].tag = unit;
	if(l == r) {
		p[u].sum = fib_unit ^ a[l];
		return; 
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
	update(u);
}

void change(int u, int l, int r, mat x) {
	if(p[u].l >= l && p[u].r <= r) {
		p[u].sum = p[u].sum * x;
		p[u].tag = p[u].tag * x;
		return;
	}
	pushdown(u);
	int mid = (p[u].l + p[u].r) >> 1;
	if(mid >= l) change(u << 1, l, r, x);
	if(mid + 1 <= r) change(u << 1 | 1, l, r, x);
	update(u);
}

mat query(int u, int l, int r) {
	if(p[u].l >= l && p[u].r <= r) return p[u].sum;
	pushdown(u); int mid = (p[u].l + p[u].r) >> 1;
	if(mid >= l && mid + 1 <= r) return query(u << 1, l, r) + query(u << 1 | 1, l, r);
	else if(mid >= l) return query(u << 1, l, r); else return query(u << 1 | 1, l, r);
}

int main() {
	init_mat(); read(n); read(m);
	for(register int i = 1; i <= n; i++) read(a[i]);
	build(1, 1, n); while(m--) {
		int opt; read(opt);
		if(opt == 1) {
			int l, r, x; read(l); read(r); read(x);
			change(1, l, r, fib_unit ^ x);
		}
		if(opt == 2) {
			int l, r; read(l); read(r);
			print(query(1, l, r).a[0][1], '\n');
		}
	}
	return 0;
}

// Rotate Flower Round.