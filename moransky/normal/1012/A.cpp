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

const int N = 2e5 + 5;

int n, a[N];

LL ans;

int main() {
	read(n);
	for (int i = 1; i <= 2 * n; i++) read(a[i]);
	sort(a + 1, a + 1 + 2 * n);
	ans = ((LL)a[n] - a[1]) * ((LL)a[2 * n] - a[n + 1]);
	for (int i = 2; i <= n; i++)
		chkMin(ans, ((LL)a[2 * n] - a[1]) * (a[i + n - 1] - a[i]));
	printf("%lld\n", ans);
}