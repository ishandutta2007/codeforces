// Skyqwq
#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 5e3 + 5;

int n, m, c[N], mn[N];

int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int a, b; read(a), read(b);
		--a, --b;
		c[a]++;
		if (!mn[a]) mn[a] = (b - a + n) % n;
		else chkMin(mn[a], (b - a + n) % n);
	}
	for (int i = 0; i < n; i++) {
		int ans = 0;
		for (int j = 0; j < n; j++) {
			if (c[j] == 0) continue;
			chkMax(ans, (j - i + n) % n + (c[j] - 1) * n + mn[j]);
		}
		printf("%d ", ans);
	}
	return 0;
}