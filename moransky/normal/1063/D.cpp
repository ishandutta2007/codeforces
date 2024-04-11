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
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

LL inline calc(LL k, LL n, LL l, LL o) {
	k -= l;
	if (k < 0) return -1;
	if (n <= 10000000) {
		for (LL q = n; ~q; q--) {
			LL u = k % (n + q);
			if (max(o, q + l - n) <= u && u <= min(l, q)) {
				return q;
			}
		}
		return -1;
	} else {
		LL R = n;
		for (LL t = 0; t * n <= k; t++) {
			if (R == -1) break;
			LL L = max(0ll, (k - (t + 1) * n + 1 + t) / (t + 1));
			if (L > R) continue;
			LL q = min((k - l + n - t * n) / (t + 1), R);
			if (R >= q && q >= L) {
				LL u = k % (n + q);
				if (max(o, q + l - n) <= u && u <= min(l, q)) {
					return q;
				}
			} 
			R = L - 1;
		}
		return -1;
	}
}

int main() {
	LL n, l, r, k;
	read(n), read(l), read(r), read(k);
	if (r < l) r += n;
	LL len = r - l + 1;
	LL ans = -1;
	chkMax(ans, calc(k, n, len, 0));
	chkMax(ans, calc(k + 1, n, len, 1));
	print(ans);
}