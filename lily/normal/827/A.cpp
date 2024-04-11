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

#define MAXN 3000319
#define MX 3000010

struct Node {
	int l, r, v;
	char ch;
} t[MAXN * 2];

int tcnt = 0;

char tmp[MAXN]; int len, pp;

int build(int l, int r) {
	int x = ++tcnt;
	t[x].ch = 0;
	if (l < r) {
		int mid = (l + r) >> 1;
		t[x].l = build(l, mid);
		t[x].r = build(mid + 1, r);
	}
	t[x].v = r - l + 1;
	return x;
}

void fill(int x, int l, int r) {
	if (l == r) {
		t[x].v = 0;
		t[x].ch = tmp[l - pp];
		return;
	}
	int mid = (l + r) >> 1;
	if (t[t[x].l].v) fill(t[x].l, l, mid);
	if (t[t[x].r].v) fill(t[x].r, mid + 1, r);
	t[x].v = t[t[x].l].v + t[t[x].r].v;
}


void update(int x, int l, int r, int ql, int qr) {
	if (!t[x].v) return;
	if (l == ql && r == qr) {
		fill(x, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	if (ql <= mid) update(t[x].l, l, mid, ql, min(mid, qr));
	if (qr >  mid) update(t[x].r, mid + 1, r, max(mid + 1, ql), qr);
	t[x].v = t[t[x].l].v + t[t[x].r].v;
}

int getlen(int x, int l, int r) {
	if (l == r) return 1;
	int mid = (l + r) >> 1;
	if (t[t[x].r].v == r - mid) {
		if (t[t[x].l].v != mid - l + 1) return getlen(t[x].l, l, mid);
		else return 0;
	}
	else {
		return mid - l + 1 + getlen(t[x].r, mid + 1, r);
	}
}

void dfs(int x, int l, int r) {
	if (l == r) {
		putchar(t[x].ch ? t[x].ch : 'a');
		if (l == len) exit(0);
		return;
	}
	int mid = (l + r) >> 1;
	dfs(t[x].l, l, mid);
	dfs(t[x].r, mid + 1, r);
}

int n;

int main() {
	read(n);
	build(1, MX);
	for (int i = 1; i <= n; i++) {
		scanf("%s", tmp);
		len = (int)strlen(tmp);
		int k; read(k);
		while (k--) {
			read(pp);
			update(1, 1, MX, pp, pp + len - 1);
		}
	}
	len = getlen(1, 1, MX);
	dfs(1, 1, MX);
	return 0;
}