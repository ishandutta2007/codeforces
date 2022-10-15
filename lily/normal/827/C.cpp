/* Never Say Die */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <bitset>
using namespace std;
typedef long long LL;
typedef double D;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
int ch = 0;
template <class T> inline void read(T &a) {
	bool f = 0; a = 0;
	while (ch < '0' || ch > '9') {if (ch == '-') f = 1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {a = a * 10 + ch - '0'; ch = getchar();}
	if (f) a = -a;
}

#define MAXN 100319

int G[128];

char s[MAXN];

struct Tag {
	int c[4];
	inline int &operator [](int x) {return c[x];}
	Tag operator + (const Tag &a) const {
		Tag ret;
		for (int i = 0; i < 4; i++) {
			ret.c[i] = a.c[i] + c[i];
		}
		return ret;
	}
};


struct Node {
	int l, r; Tag v;
} t[MAXN * 100];

int n, m, a[MAXN], tcnt = 0;
int sz[11][11], rt[11][11];

int I, J;


int build(int l, int r) {
	int x = ++tcnt;
	if (l == r) {
		int p = l * I + J;
		if (p >= 1 && p <= n) {
			t[x].v[s[p]] = 1;
		}
	}
	else {
		int mid = (l + r) >> 1;
		t[x].l = build(l, mid);
		t[x].r = build(mid + 1, r);
		t[x].v = t[t[x].l].v + t[t[x].r].v;
	}
	return x;
}

void Build() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < i; j++) {
			sz[i][j] = (n - j) / i;
			I = i, J = j;
			rt[i][j] = build(0, sz[i][j]);
		}
	}
}

int qry(int x, int l, int r, int ql, int qr, int v) {
	if ((l == ql && r == qr) || !t[x].v[v]) {
		return t[x].v[v];
	}
	int mid = (l + r) >> 1, ret = 0;
	if (ql <= mid) ret += qry(t[x].l, l, mid, ql, min(mid, qr), v);
	if (qr >  mid) ret += qry(t[x].r, mid + 1, r, max(mid + 1, ql), qr, v);
	return ret;
}

void upd(int x, int l, int r, int p, int fr, int to) {
	t[x].v[fr]--; t[x].v[to]++;
	if (l < r) {
		int mid = (l + r) >> 1;
		if (p <= mid) upd(t[x].l, l, mid, p, fr, to);
		else upd(t[x].r, mid + 1, r, p, fr, to);
	}
}

void update(int p, int v) {
	if (s[p] == v) return;
	for (int i = 1; i <= 10; i++) {
		int q = p % i;
		upd(rt[i][q], 0, sz[i][q], p / i, s[p], v);
	}
	s[p] = v;
}

char ss[233];

void query(int l, int r) {
	scanf("%s", ss);
	int i = (int)strlen(ss), ans = 0;
	for (int j = 0; j < i; j++) ss[j] = G[ss[j]];
	for (int k = 0, j; k < i; k++) {
		j = (l + k) % i; 
		int ll = (l - j + i - 1) / i, rr = r >= j ? (r - j) / i : -1;
		if (ll <= rr) {
			ans += qry(rt[i][j], 0, sz[i][j], ll, rr, ss[k]);
		}
	}
	printf("%d\n", ans);
}

int main() {
	scanf("%s", s + 1);
	n = (int)strlen(s + 1);
	G['A'] = 0; G['T'] = 1; G['G'] = 2; G['C'] = 3;
	for (int i = 1; i <= n; i++) s[i] = G[s[i]];
	Build();

	read(m);
	for (int i = 1, op, l, r; i <= m; i++) {
		read(op);
		if (op == 1) {
			read(l);
			ch = getchar();
			while (ch < 'A') ch = getchar();
			update(l, G[ch]);
		}
		else {
			read(l); read(r);
			query(l, r);
		}
	}
	return 0;
}