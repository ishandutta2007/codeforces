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

const int N = 1e6 + 5;

int n, f[N];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
	f[find(x)] = find(y);
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		merge(i, x);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (find(i) == i) cnt++;
	cnt = (n - cnt) & 1;
	if ((3 * n) % 2 == cnt) puts("Petr");
	else puts("Um_nik");
	return 0;
}