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

int a[N];
int n, invn;

int main() {
	read(n); invn = fpow(n, md - 2);
	for (int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) addx(a[i], a[i - 1]);
	for (int k = 1; k <= n; k++) {
		int ans = 0;
		for (int l = 1, r = k; l <= n; l += k, r += k) {
			r = min(r, n);
			addx(ans, mul((l - 1) / k, sub(a[r], a[l - 1])));
		}
		print(mul(ans, invn), k == n ? '\n' : ' ');
	}
	return 0;
}