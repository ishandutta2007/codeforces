#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }
template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }

template <typename T> void inline read(T &x) {
	x = 0; int f = 1; char s = getchar();
	while (s > '9' || s < '0') { if (s == '-') f = -1; s = getchar(); }
	while (s <= '9' && s >= '0') x = x * 10 + s - '0', s = getchar();
	x *= f;
}

const int N = 3e5 + 5;

int n, a[N], L = 3e5, pos[N], B = sqrt(3e5), R[N], tot;
LL c[2][N], ans;
LL b[2][N];
void inline add(int o, int x, int k) {
	for (int i = pos[x]; i <= tot; i++) b[o][i] += k;
	for (int i = x; i <= R[pos[x]]; i++) c[o][i] += k;
}

LL inline ask(int o, int x) {
	return b[o][pos[x] - 1] + c[o][x];
}

LL inline query(int o, int l, int r) {
	r = min(r, L);
	return ask(o, r) - ask(o, l - 1);
}

void inline work1(int x) {
	for (int i = 1, j, t; i <= x; i = j + 1) {
		t = x / i, j = x / t;
		ans += x * query(0, i, j) - t * query(1, i, j);
	}
}

void inline work2(int x) {
	int c = 1;
	for (int i = x; i <= L; i += x) {
		ans += query(1, i, i + x - 1) - c * query(0, i, i + x - 1) * x;
		++c;
	}
}

int main() {
	for (int i = 1; i <= L; i++) {
		pos[i] = (i - 1) / B + 1;
		R[pos[i]] = i;
	}
	tot = pos[L];
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) {
		ans += a[i] * query(0, a[i], L);
		ans += query(1, 1, a[i]);
		work1(a[i]);
		work2(a[i]);
		printf("%lld ", ans);
		add(0, a[i], 1);
		add(1, a[i], a[i]);
	}
	return 0;
}