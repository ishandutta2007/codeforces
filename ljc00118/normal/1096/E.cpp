// qwq
#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
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

const int N = 5005, md = 998244353;

inline int mul(int x, int y) { return (ll)x * y % md; }

inline int add(int x, int y) {
	x += y;
	if(x >= md) x -= md;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if(x < 0) x += md;
	return x;
}

inline int fpow(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

int C[N + 105][105], inv[N];
int n, s, r, ans;

int calc(int n, int s, int big) {
	if(n == 0) return s == 0;
	int ans = 0;
	for(register int i = 0, opt = 1; i <= n && i * big <= s; i++, opt = md - opt)
		ans = add(ans, mul(opt, mul(C[s - i * big + n - 1][n - 1], C[n][i])));
	return ans;
}

int main() {
	read(n); read(s); read(r);
	for(register int i = 0; i <= s + n; i++) {
		C[i][0] = 1;
		for(register int j = 1; j <= i && j <= n; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	}
	for(register int i = 1; i <= n; i++) inv[i] = fpow(i, md - 2);
	for(register int i = 1; i <= n; i++) {
		for(register int j = r; j <= s; j++) {
			if(s - i * j < 0) break;
			ans = add(ans, mul(mul(C[n - 1][i - 1], calc(n - i, s - i * j, j)), inv[i])); 
		}
	}
	print(mul(ans, fpow(C[s - r + n - 1][n - 1], md - 2)), '\n');
	return 0;
}

// Rotate Flower Round.