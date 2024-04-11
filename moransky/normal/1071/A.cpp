#include <iostream>
#include <cstdio>
#include <cstring>
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

const int N = 1e5 + 5;

LL a, b;

bool vis[N];

int t, c[N];

int main() {
	read(a), read(b);
	int n = 0;
	while ((n + 1ll) * (n + 2ll) / 2 <= a + b) n++;
	for (int i = n; i; i--) {
		if (a >= i) {
			a -= i;
			vis[i] = 1;
			c[++t] = i;
		}
	}
	printf("%d\n", t);
	for (int i = 1; i <= t; i++) printf("%d ", c[i]);
	printf("\n%d\n", n - t);
	for (int i = 1; i <= n; i++) if (!vis[i]) printf("%d ", i);
}