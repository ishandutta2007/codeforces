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

const int N = 2e5 + 5;

int n, a[N], b[N], pos[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) read(b[i]), pos[b[i]] = i;
	int p = pos[1];
	if (p) {
		while (p < n && b[p] + 1 == b[p + 1]) p++;
		if (p == n) {
			int t = p - pos[1] + 1;
			bool o = 1;
			for (int i = 1; i + t <= n; i++)
				if (pos[t + i] >= i) o = 0;
			if (o) {
				printf("%d\n", n - t);
				return 0;
			}
		}
	}
	int mx = 0;
	for (int i = 1; i <= n; i++)
		chkMax(mx, pos[i] - i + 1);
	printf("%d\n", mx + n);
}