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

const int N = 3e5 + 5, md = 998244353;

inline int add(int x, int y) {
	x += y;
	if (x >= md) x -= md;
	return x;
}

inline void addx(int &x, int y) {
	x += y;
	if (x >= md) x -= md;
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

int a[N], f[N], b[N], p1[N], p2[N], p3[N];
int n, m, ans;

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), m += a[i];
	for (int i = 0; i < m; i++) {
		p1[i] = mul(i, fpow(m, md - 2));
		p2[i] = mul(mul(m - i, fpow(m, md - 2)), mul(n - 2, fpow(n - 1, md - 2)));
		p3[i] = mul(mul(m - i, fpow(m, md - 2)), fpow(n - 1, md - 2));
	}
	b[0] = n - 1;
	for (int i = 1; i < m; i++) {
		int p = fpow(sub(1, add(p2[i], p1[i])), md - 2);
		b[i] = mul(add(1, mul(p1[i], b[i - 1])), p);
	}
	f[m] = 0;
	for (int i = m - 1; i >= 0; i--) f[i] = add(f[i + 1], b[i]);
	for (int i = 1; i <= n; i++) addx(ans, f[a[i]]);
	ans = mul(sub(ans, mul(f[0], n - 1)), fpow(n, md - 2));
	print(ans, '\n');
	return 0;
}