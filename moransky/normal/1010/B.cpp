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
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 31;

int m, n, c[N];

int inline ask(int x) {
	printf("%d\n", x);
	fflush(stdout);
	int p; read(p);
	return p;
}


int main() {
	read(m), read(n);
	for (int i = 0; i < n; i++) {
		int t = ask(1);
		if (t == 0) return 0;
		c[i] = t;
	}
	int l = 1, r = m, o = 0;
	
	while (l <= r) {
		int mid = (l + r) >> 1;
		int t = c[o] * ask(mid);
		if (!t) return 0;
		if (t == 1) l = mid + 1;
		else r = mid - 1;
		(o += 1) %= n;
	}
}