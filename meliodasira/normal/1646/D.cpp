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

const int N = 2e5 + 5;

vector<int> adj[N];
pii dp[N][2];
int ans[N];
int n;

pii operator+(pii a, pii b) {
	return make_pair(a.first + b.first, a.second + b.second);
}

void dfs1(int u, int fa) {
	dp[u][0] = make_pair(0, -1);
	dp[u][1] = make_pair(1, -(int)adj[u].size());
	for (auto v: adj[u]) {
		if (v == fa) continue;
		dfs1(v, u);
		dp[u][0] = dp[u][0] + max(dp[v][0], dp[v][1]);
		dp[u][1] = dp[u][1] + dp[v][0];
	}
}

void solve(int u, int fa, int x) {
	if (x == 0) ans[u] = 1;
	for (auto v: adj[u]) {
		if (v == fa) continue;
		if (x == 1)
			solve(v, u, 0);
		else
			solve(v, u, dp[v][1] > dp[v][0]);
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	if (n == 2) {
		printf("2 2\n");
		printf("1 1\n");
		return 0;
	}
	rep(i, 1, n - 1) {
		int u = read(), v = read();
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1, 0);
	if (dp[1][0] > dp[1][1])
		solve(1, 0, 0);
	else
		solve(1, 0, 1);
	int ans1 = 0, ans2 = 0;
	rep(u, 1, n) {
		if (!ans[u]) {
			for (auto v: adj[u]) {
				ans[u] += ans[v];
			}
			++ans1;
		}
		ans2 += ans[u];
	}
	printf("%d %d\n", ans1, ans2);
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
}