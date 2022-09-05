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

const int N = 2e6 + 5, md = 998244353;

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

int fac[N], inv[N];
int n, m, ans;

inline int C(int n, int m) { return mul(fac[n], mul(inv[m], inv[n - m])); }

int main() {
	read(n); read(m);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
	inv[n] = fpow(fac[n], md - 2);
	for (int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
	for (int i = 1; i <= n; i++) {
		int now = mul(C(n, i), mul(m + i, mul(fac[i - 1], inv[i])));
		if (i & 1) ans = add(ans, now);
		else ans = sub(ans, now);
	}
	print(mul(ans, mul(n, fpow(m + 1, md - 2)) + 1), '\n');
	return 0;
}