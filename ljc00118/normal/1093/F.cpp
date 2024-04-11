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

const int N = 1e5 + 5, md = 998244353;

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

int f[N][105], cnt[N][105], s[N], a[N];
int n, k, len;

int main() {
	read(n); read(k); read(len); if(len == 1) { cout << 0 << endl; return 0; }
	for(register int i = 1; i <= n; i++) read(a[i]);
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= k; j++) cnt[i][j] = cnt[i - 1][j] + (a[i] == -1 || a[i] == j);
	}
	s[0] = 1; if(a[1] == -1) { for(register int i = 1; i <= k; i++) f[1][i] = 1; s[1] = k; } else f[1][a[1]] = 1, s[1] = 1;
	for(register int i = 2; i <= n; i++) {
		for(register int j = 1; j <= k; j++) {
			if(~a[i] && a[i] != j) continue;
			f[i][j] = s[i - 1];
			if(i >= len) {
				int l = i - len;
				if(cnt[i][j] - cnt[l][j] == len) {
//					fprintf(stderr, "cnt[%d][%d] = %d, cnt[%d][%d] = %d\n", i, j, cnt[i][j], l, j, cnt[l][j]);
					f[i][j] = sub(f[i][j], sub(s[l], f[l][j]));
				}
			}
			s[i] = add(s[i], f[i][j]);
//			fprintf(stderr, "f[%d][%d] = %d\n", i, j, f[i][j]);
		}
	}
	cout << s[n] << endl;
	return 0;
}

// Rotate Flower Round.