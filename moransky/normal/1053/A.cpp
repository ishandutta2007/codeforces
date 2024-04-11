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

LL n, m, k, s;

int main() {
	read(n), read(m), read(k);
	s = 1ll * n * m * 2;
	if (s % k) {
		puts("NO");
		return 0;
	}
	s /= k;
	
	bool o = 0;
	
	
	for (LL i = 2; i * i <= k; i++) {
		if (k % i == 0) {
			if (!o) {
				o = 1;
				if (n % i == 0) {
					n *= 2;
					n /= i;
				} else {
					m *= 2;
					m /= i;
				}
				k /= i;
			}
			
			while (k % i == 0) {
				if (n % i == 0) {
					n /= i;
				} else {
					m /= i;
				}
				k /= i;
			}
		}
	}
	
	if (k > 1) {
		LL i = k;
		if (!o) {
			o = 1;
			if (n % i == 0) {
				n *= 2;
				n /= i;
			} else {
				m *= 2;
				m /= i;
			}
		} else {
			if (n % i == 0) {
				n /= i;
			} else {
				m /= i;
			}
		}
	}
	
	puts("YES");
	printf("%lld %lld\n", 0ll, 0ll);
	printf("%lld %lld\n", n, 0ll);
	printf("%lld %lld\n", 0ll, m);
}