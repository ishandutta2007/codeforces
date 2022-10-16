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

const int N = 2e5 + 5;

int n, d[N], p[N], t, b[N];

void inline add(int x, int y) {
	printf("%d %d\n", x, y);
}

bool inline cmp(int x, int y) {
	return d[x] > d[y];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", d + i), p[i] = i;
	sort(p + 1, p + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		int u = p[i];
		b[i] = u * 2 - 1;
	}
	for (int i = 1; i < n; i++)
		add(b[i], b[i + 1]);
	t = n;
	for (int i = 1; i <= n; i++) {
		int u = p[i];
		if (i + d[u] > t) {
			b[++t] = u * 2;
			add(b[t - 1], b[t]);
		} else {
			add(u * 2, b[i + d[u] - 1]);
		}
	}
}