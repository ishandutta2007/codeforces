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

const int N = 2005, md = 998244353;

inline int mul(int x, int y) { return (ll)x * y % md; }

inline int add(int x, int y) {
	x += y;
	if(x >= md) x -= md;
	return x;
}

int f[N][N];
int n, m, k;

int main() {
	read(n); read(m); read(k);
	f[1][0] = m;
	for(register int i = 2; i <= n; i++) {
		for(register int j = 0; j <= k; j++) {
			f[i][j] = add(f[i - 1][j], mul(f[i - 1][j - 1], m - 1));
		}
	}
	cout << f[n][k] << endl;
	return 0;
}

// Rotate Flower Round.