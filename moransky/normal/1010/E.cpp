#include <bits/stdc++.h>

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

const int N = 5e5 + 5;

int X, Y, Z, n, m, q, t, ans[N], num[N], c[N];

struct E{
	int op, x, y, z, o, i, z2;
} e[N];

int xL = 2e9, xR, yL = 2e9, yR, zL = 2e9, zR;

bool inline in(int x, int l, int r) {
	return l <= x && x <= r;
}

bool inline cmp1(E a, E b) {
	if (a.x == b.x) return a.op < b.op;
	return a.x < b.x;
}

bool inline cmp2(E a, E b) {
	if (a.y == b.y) return a.op < b.op;
	return a.y < b.y;
}

void inline add(int x, int k) {
	if (!x) return;
	for (; x <= Z; x += x & -x) c[x] += k;
}

void inline clear(int x) {
	if (!x) return; 
	for (; x <= Z; x += x & -x) c[x] = 0;
}


int inline ask(int x) {
	if (x < 0) return 0;
	int res = 0;
	for (; x; x -= x & -x) res += c[x];
	return res;
}

void cdq(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) >> 1;
	cdq(l, mid), cdq(mid + 1, r);
	int o = 0;
	for (int i = mid + 1, j = l; i <= r; i++) {
		while (j <= mid && e[j].y <= e[i].y) {
			if (e[j].op == 1) add(e[j].z, 1), ++o;
			j++;
		}
		if (e[i].op == 2 && o) num[e[i].i] += e[i].o * (ask(e[i].z2) - ask(e[i].z));
	}
	for (int i = l; i <= mid; i++)
		if (e[i].op == 1) clear(e[i].z);
	sort(e + l, e + 1 + r, cmp2);
}

int main() {
	read(X), read(Y), read(Z);
	read(n), read(m), read(q);
	for (int i = 1; i <= n; i++) {
		int x, y, z; read(x), read(y), read(z);
		chkMin(xL, x), chkMax(xR, x);
		chkMin(yL, y), chkMax(yR, y);
		chkMin(zL, z), chkMax(zR, z);
	}
	bool o = 1;
	for (int i = 1; i <= m; i++) {
		int x, y, z; read(x), read(y), read(z);
		e[i] = (E) { 1, x, y, z };
		if (in(x, xL, xR) && in(y, yL, yR) && in(z, zL, zR)) o = 0;
	}
	if (!o) {
		puts("INCORRECT");
		return 0;
	}
	t = m;
	for (int i = 1; i <= q; i++) {
		int x, y, z; read(x), read(y), read(z);
		if (in(x, xL, xR) && in(y, yL, yR) && in(z, zL, zR)) {
			ans[i] = 1;
		} else {
			e[++t] = (E) { 2, max(xR, x), max(yR, y), min(zL, z) - 1, 1, i, max(zR, z) };
			
			e[++t] = (E) { 2, min(xL, x) - 1, max(yR, y), min(zL, z) - 1, -1, i, max(zR, z) };
			e[++t] = (E) { 2, max(xR, x), min(yL, y) - 1, min(zL, z) - 1, -1, i, max(zR, z) };
			e[++t] = (E) { 2, min(xL, x) - 1, min(yL, y) - 1, min(zL, z) - 1, 1, i, max(zR, z) };
			ans[i] = 0;
		}
	}
	sort(e + 1, e + 1 + t, cmp1);
	cdq(1, t);
	puts("CORRECT");
	for (int i = 1; i <= q; i++) {
		if (ans[i] == 0 && !num[i]) {
			ans[i] = -1;
		}
		if (ans[i] == 1) puts("OPEN");
		else if (ans[i] == 0) puts("CLOSED");
		else puts("UNKNOWN");
	}
}