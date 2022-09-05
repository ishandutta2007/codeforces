#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
  
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e6 + 5, M = 1e6, md = 998244353;

inline int add(int x, int y) {
	x += y;
	if (x >= md) x -= md;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += md;
	return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

int a[N], fac[N * 2], inv[N * 2], cnt[N];
int n, lim = -1, ans, sum, now;

inline int C(int n, int m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
	fac[0] = 1;
	for (int i = 1; i <= M * 2; i++) fac[i] = mul(fac[i - 1], i);
	inv[M * 2] = fpow(fac[M * 2], md - 2);
	for (int i = M * 2; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) if (a[i] + 1 < i) { lim = a[i]; break; }
	if (~lim) {
		for (int i = 1; i <= n; i++) ++cnt[a[i]];
		for (int i = 0; i <= lim; i++) {
			if (i) cnt[i] += cnt[i - 1];
			int must = (i == 0 ? 0 : cnt[i - 1]);
			ans = add(ans, C(n + i - must - 1, n - 1));
		}
		print(ans, '\n');
		return 0;
	}
	for (int i = 1; i <= n; i++) ++cnt[a[i] % n], sum += a[i], now += (a[i] % n);
	for (int i = 0; i < n; i++) {
		int x = (sum - now) / n;
		ans = add(ans, C(n + x - 1, n - 1));
		now -= n; now += cnt[i] * n;
	}
	print(ans, '\n');
    return 0;
}