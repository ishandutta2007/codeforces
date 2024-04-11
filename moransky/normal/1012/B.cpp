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

const int N = 400005;

int n, m, q, f[N], cnt;

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
	read(n), read(m), read(q);
	for (int i = 1; i <= n + m; i++) f[i] = i;
	for (int i = 1, r, c; i <= q; i++) {
		read(r), read(c);
		f[find(r)] = find(c + n);
	}
	for (int i = 1; i <= n + m; i++) {
		if (find(i) == i) cnt++;
	}
	printf("%d\n", cnt - 1);
}