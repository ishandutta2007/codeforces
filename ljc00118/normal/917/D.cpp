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

const int N = 105, md = 1e9 + 7;

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

inline void subx(int &x, int y) {
	x -= y;
	if (x < 0) x += md;
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

vector <int> adj[N];
int f[N][N][N], ans[N], siz[N], c[N][N], tmp[N][N];
int n;

void conv(int a[N][N], int b[N][N], int &lena, int lenb) {
	for (int i = 0; i <= lena + lenb; i++) {
		for (int j = 0; j <= lena + lenb; j++) tmp[i][j] = 0;
	}
	for (int i = 0; i <= lena; i++) {
		for (int j = 0; j <= lena; j++) {
			if (a[i][j] == 0) continue;
			for (int x = 0; x <= lenb; x++) {
				for (int y = 0; y <= lenb; y++) {
					if (b[x][y] == 0) continue;
					addx(tmp[i + x + 1][j], mul(mul(a[i][j], b[x][y]), y));
					addx(tmp[i + x][j + y], mul(a[i][j], b[x][y]));
				}
			}
		}
	}
	lena += lenb;
	for (int i = 0; i <= lena; i++) {
		for (int j = 0; j <= lena; j++) a[i][j] = tmp[i][j];
	}
}

void dfs1(int u, int fa) {
	siz[u] = 1; f[u][0][1] = 1;
	for (auto v : adj[u]) {
		if (v == fa) continue;
		dfs1(v, u);
		conv(f[u], f[v], siz[u], siz[v]);
	}
}

int main() {
	read(n);
	c[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		read(u); read(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1, 0);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (f[1][i][j] == 0) continue;
			// fprintf(stderr, "i = %d, j = %d, f = %d\n", i, j, f[1][i][j]);
			addx(ans[n - i - 1], mul(f[1][i][j], j));
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i != n - 1) ans[i] = mul(ans[i], fpow(n, n - i - 2));
		else ans[i] = 1;
		for (int j = i + 1; j <= n - 1; j++) subx(ans[i], mul(ans[j], c[j][i]));
	}
	for (int i = 0; i <= n - 1; i++) print(ans[i], ' ');
	putchar('\n');
	return 0;
}