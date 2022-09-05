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

vector <int> adj[N];
int f[N][3];
int n;

void dfs1(int u, int fa) {
	f[u][0] = 1;
	for (auto v : adj[u]) {
		if (v == fa) continue;
		dfs1(v, u);
		f[u][2] = add(mul(f[u][2], add(f[v][0], add(f[v][2], f[v][2]))), mul(add(f[u][0], f[u][1]), add(f[v][0], f[v][1])));
		f[u][1] = add(mul(f[u][1], add(f[v][0], add(f[v][2], f[v][2]))), mul(f[u][0], f[v][2]));
		f[u][0] = mul(f[u][0], add(f[v][0], f[v][2]));
	}
}

int main() {
	read(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		read(u); read(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1, 0);
	print(add(f[1][0], f[1][2]), '\n');
	return 0;
}