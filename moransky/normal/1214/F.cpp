#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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

typedef pair<int, int> PII;

const int N = 8e5 + 5;

int m, n, t, s[N], x[N], D = 400001, L = 800002;

LL ans = 9e18;

PII e[N];

LL c[2][N];

void inline add(int o, int x, LL k) {
	x += D;
	for (; x <= L; x += x & -x) c[o][x] += k;
}

LL inline ask(int o, int x) {
	LL res = 0;
	x += D;
	for (; x; x -= x & -x) res += c[o][x];
	return res;
}

LL inline query(int o, int l, int r) {
	if (l > r) return 0;
	return ask(o, r) - ask(o, l - 1);
}

void inline Add(int x, int k) {
	add(0, x, k);
	add(1, x, 1ll * x * k);
}

int s1[N], s2[N], t1, t2, arr[N];

int main() {
	read(m), read(n);
	for (int i = 1, x; i <= n; i++) {
		read(x);
		e[++t] = mp(x, i);
	}
	for (int i = 1, x; i <= n; i++) {
		read(x);
		e[++t] = mp(x, i + n);
	}
	sort(e + 1, e + 1 + t);
	for (int i = 1; i <= 2 * n; i++) e[i + t] = e[i], e[i + t].fi += m;
	t = 4 * n;
	for (int i = 1; i <= t; i++) {
		s[i] = s[i - 1] + (e[i].se <= n ? 1 : -1);
		x[i] = e[i + 1].fi - e[i].fi;
	}
	for (int i = 1; i <= 2 * n; i++)
		Add(s[i], x[i]);
	int p = -1;
	for (int i = 1; i <= 2 * n; i++) {
		Add(s[i], -x[i]);
		Add(s[i + 2 * n], x[i]);
		LL s0 = query(0, s[i] + 1, D), s1 = query(1, s[i] + 1, D);
		LL res = s1 - s[i] * s0;
		s0 = ask(0, s[i]), s1 = ask(1, s[i]);
		res += -s1 + s[i] * s0;
		if (res < ans) {
			ans = res;
			p = i;
		}
	}
	for (int i = p + 1; i <= p + 2 * n; i++) {
		if (e[i].se <= n) {
			if (t2) arr[e[i].se] = s2[t2--];
			else s1[++t1] = e[i].se;
		} else {
			if (t1) arr[s1[t1--]] = e[i].se - n;
			else s2[++t2] = e[i].se - n;
		}
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++) printf("%d ", arr[i]);
}