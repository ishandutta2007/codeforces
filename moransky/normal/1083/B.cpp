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

const int N = 5e5 + 5;

int n, k;

char s[N], t[N];

LL ans;

int main() {
	read(n), read(k);
	scanf("%s%s", s + 1, t + 1);
	int v = 1;
	int p = 1;
	while (s[p] == t[p] && p <= n) p++;
	ans = p - 1;
	for (int i = p; i <= n; i++) {
		v *= 2;
		if (s[i] == 'b') v--;
		if (t[i] == 'a') v--;
		if (v >= k) {
			ans += (n - i + 1ll) * k;
			break;
		}
		ans += v;
	}
	print(ans);
	return 0;
}