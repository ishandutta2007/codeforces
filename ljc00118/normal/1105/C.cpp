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

const int N = 2e5 + 5, md = 1e9 + 7;

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

inline int fpow(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

int f[N][3], v[3];
int n, l, r;

int main() {
	read(n); read(l); read(r); f[0][0] = 1;
	v[0] = r / 3 - (l - 1) / 3;
	v[1] = (r + 2) / 3 - (l + 1) / 3;
	v[2] = (r + 1) / 3 - l / 3;
	for(register int i = 0; i < n; i++) {
		for(register int j = 0; j <= 2; j++) {
			for(register int k = 0; k <= 2; k++) {
				f[i + 1][(j + k) % 3] = add(f[i + 1][(j + k) % 3], mul(f[i][j], v[k]));
			}
		}
	}
	cout << f[n][0] << endl;
	return 0;
}