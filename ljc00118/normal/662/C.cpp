#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 100005, md = 998244353;

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

inline int mul(int x, int y) { return (ll)x * y % md; }

vector <int> a, b;
char c[25][N];
int n, m, ans = 0x7fffffff;

inline int div2(int x) { return (x & 1) ? ((x + md) >> 1) : (x >> 1); }

void fwt_xor(vector <int> &a, int opt) {
	for(register int mid = 1; mid < (1 << n); mid <<= 1) {
		for(register int i = 0; i < (1 << n); i += (mid << 1)) {
			for(register int j = 0; j < mid; j++) {
				int x = a[i + j], y = a[i + j + mid];
				if(opt == 1) a[i + j] = add(x, y), a[i + j + mid] = sub(x, y);
				else a[i + j] = div2(add(x, y)), a[i + j + mid] = div2(sub(x, y));
			}
		}
	}
}

int main() {
	read(n); read(m); a.resize(1 << n); b.resize(1 << n);
	for(register int i = 0; i < n; i++) scanf("%s", c[i] + 1);
	for(register int j = 1; j <= m; j++) {
		int now = 0;
		for(register int i = 0; i < n; i++) {
			if(c[i][j] == '1') now ^= (1 << i);
		}
		++a[now];
	}
	for(register int i = 0; i < (1 << n); i++) b[i] = __builtin_popcount(i), b[i] = min(b[i], n - b[i]);
	fwt_xor(a, 1); fwt_xor(b, 1); for(register int i = 0; i < (1 << n); i++) a[i] = mul(a[i], b[i]); fwt_xor(a, -1);
	for(register int i = 0; i < (1 << n); i++) { ans = min(ans, a[i]); } print(ans, '\n');
	return 0;
}