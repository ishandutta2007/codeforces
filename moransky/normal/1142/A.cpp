// Skyqwq
#include <iostream>
#include <cstdio>
#include <cmath>
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

LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}

LL n, k, a, b, mx = 0, mn = 9e18;

void inline work(LL x) {
	while (x <= n * k) {
		LL t = gcd(x, n * k);
		chkMax(mx, n * k / t);
		chkMin(mn, n * k / t);
		x += k;
	}
}

int main() {
	read(n), read(k), read(a), read(b);
	work((a + b) % k), work((LL)(abs(a - b)) % k);
	printf("%lld %lld\n", mn, mx);
	return 0;
}