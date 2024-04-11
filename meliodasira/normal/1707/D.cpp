#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

int P;

int add(int x, int y) {
	if (x + y >= P) return x + y - P;
	return x + y;
}

int sub(int x, int y) {
	if (x < y) return x - y + P;
	return x - y;
}

int mul(int x, int y) { return 1ull * x * y % P; }

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1;
		x = mul(x, x);
	}
	return ans;
}

const int N = 2005;

vector<int> adj[N];
int f[N][N], pre[N][N], suf[N][N], C[N][N], ans[N];
int n;

void dfs1(int u, int fa) {
	if (u == 1) {
		for (auto v: adj[u]) {
			dfs1(v, u);
			int sum = 0;
			for (int i = 1; i <= n; i++) {
				sum = add(sum, f[v][i]);
				ans[i] = mul(ans[i], sum);
			}
		}
		return;
	}
	vector<int> son;
	for (auto v: adj[u]) {
		if (v == fa) continue;
		dfs1(v, u);
		son.push_back(v);
	}
	int len = (int)son.size();
	rep(i, 1, n) pre[0][i] = suf[len + 1][i] = 1;
	rep(i, 1, len) {
		int v = son[i - 1], sum = 0;
		rep(j, 1, n) {
			sum = add(sum, f[v][j]);
			pre[i][j] = mul(pre[i - 1][j], sum);
		}
	}
	per(i, len, 1) {
		int v = son[i - 1], sum = 0;
		rep(j, 1, n) {
			sum = add(sum, f[v][j]);
			suf[i][j] = mul(suf[i + 1][j], sum);
		}
	}
	rep(i, 1, n) f[u][i] = pre[len][i];
	rep(i, 1, len) {
		int v = son[i - 1], sum = 0;
		rep(j, 1, n) {
			f[u][j] = add(f[u][j], mul(sum, f[v][j]));
			sum = add(sum, mul(pre[i - 1][j], suf[i + 1][j]));
		}
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	P = read();
	C[0][0] = 1;
	rep(i, 1, n) {
		C[i][0] = 1;
		rep(j, 1, i) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	}
	rep(i, 1, n - 1) {
		int u = read(), v = read();
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	rep(i, 1, n) ans[i] = 1;
	dfs1(1, 0);
	per(i, n, 1) ans[i] = sub(ans[i], ans[i - 1]);
	rep(i, 1, n - 1) {
		rep(j, 1, i - 1) ans[i] = sub(ans[i], mul(ans[j], C[i - 1][j - 1]));
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	}
}