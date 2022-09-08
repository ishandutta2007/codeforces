#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
   print(x); putchar(t);
}

const int N = 2e5 + 5;

struct ele { int f[32]; };

struct Node {
	int l, r; ele val;
}p[N << 2];

int t[N][5];
int n, m, k;

ele merge(ele a, ele b) {
	for(register int i = 0; i < (1 << k); i++) a.f[i] = max(a.f[i], b.f[i]);
	return a;
}

void build(int u, int l, int r) {
	p[u].l = l; p[u].r = r;
	if(l == r) {
		for(register int i = 0; i < (1 << k); i++) {
			p[u].val.f[i] = 0;
			for(register int j = 0; j < k; j++) {
				if(i & (1 << j)) p[u].val.f[i] += t[l][j];
				else p[u].val.f[i] -= t[l][j];
			}
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
	p[u].val = merge(p[u << 1].val, p[u << 1 | 1].val);
}

void change(int u, int l) {
	if(p[u].l == p[u].r) {
		for(register int i = 0; i < (1 << k); i++) {
			p[u].val.f[i] = 0;
			for(register int j = 0; j < k; j++) {
				if(i & (1 << j)) p[u].val.f[i] += t[l][j];
				else p[u].val.f[i] -= t[l][j];
			}
		}
		return;
	}
	int mid = (p[u].l + p[u].r) >> 1;
	if(mid >= l) change(u << 1, l); else change(u << 1 | 1, l);
	p[u].val = merge(p[u << 1].val, p[u << 1 | 1].val);
}

ele query(int u, int l, int r) {
	if(p[u].l >= l && p[u].r <= r) return p[u].val;
	int mid = (p[u].l + p[u].r) >> 1;
	if(mid >= l && mid + 1 <= r) return merge(query(u << 1, l, r), query(u << 1 | 1, l, r));
	else if(mid >= l) return query(u << 1, l, r); return query(u << 1 | 1, l, r);
}

int main() {
	read(n); read(k);
	for(register int i = 1; i <= n; i++) {
		for(register int j = 0; j < k; j++) {
			read(t[i][j]);
		}
	}
	build(1, 1, n); read(m);
	while(m--) {
		int opt; read(opt);
		if(opt == 1) {
			int i; read(i);
//			cout << i << " " << k << endl;
			for(register int j = 0; j < k; j++) read(t[i][j]);
			change(1, i);
		}
		if(opt == 2) {
			int l, r; read(l); read(r);
			ele res = query(1, l, r); int ans = 0;
			for(register int i = 0; i < (1 << (k - 1)); i++) ans = max(ans, res.f[i] + res.f[(1 << k) - 1 - i]);
			print(ans, '\n');
		}
	}
	return 0;
}