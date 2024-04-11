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

vector<int> adj[N], edg[N], way[N][2];
int dp[N][2], deg[N], fa[N];
int T, n, ans;

void dfs1(int u, int fa) {
	way[u][0].clear();
	way[u][1].clear();
	dp[u][0] = dp[u][1] = 0;
	vector<int> vec1, vec2;
	for (auto v: adj[u]) {
		if (v == fa) continue;
		::fa[v] = u;
		dfs1(v, u);
		if (!dp[v][0]) vec1.push_back(v);
		if (dp[v][0] && dp[v][1]) vec2.push_back(v);
	}
	auto check = [&] {
		if (vec1.size() == adj[u].size() / 2 - 1) {
			dp[u][1] = 1;
			way[u][1] = vec1;
		}
		if (vec1.size() == adj[u].size() / 2) {
			dp[u][0] = 1;
			way[u][0] = vec1;
		}
	};
	check();
	while (vec2.size()) {
		vec1.push_back(vec2.back());
		vec2.pop_back();
		check();
	}
	if (!dp[u][0] && !dp[u][1]) {
		ans = 0;
		return;
	}
}

int vis[N];
void dfs2(int u, int fa, int val) {
	for (auto v: way[u][val]) vis[v] = 1;
	vector<int> son;
	for (auto v: adj[u]) {
		if (v == fa || vis[v]) continue;
		son.push_back(v);
	}
	for (auto v: way[u][val]) vis[v] = 0;
	for (auto v: way[u][val]) dfs2(v, u, 1);
	for (auto v: son) dfs2(v, u, 0);
	vector<int> vec0, vec1;
	if (val == 1) {
		vec1 = way[u][1];
		vec0 = son;
		if (fa) vec1.push_back(u);
	} else {
		vec1 = way[u][0];
		vec0 = son;
		if (fa) vec0.push_back(u);
	}
	// fprintf(stderr, "u = %d\n", u);
	// for (auto i : vec0) cout << i << " ";
	// cout << endl;
	// for (auto i : vec1) cout << i << " ";
	// cout << endl;
	vector<int> seq;
	for (int i = 0; i < (int)vec1.size(); i++) seq.push_back(vec0[i]), seq.push_back(vec1[i]);
	if (adj[u].size() & 1) seq.push_back(vec0.back());
	for (int i = 1; i < (int)seq.size(); i++) edg[seq[i]].push_back(seq[i - 1]), ++deg[seq[i - 1]];
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) adj[i].clear(), edg[i].clear(), deg[i] = 0;
		for (int i = 1; i < n; i++) {
			int u = read(), v = read();
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		ans = 1;
		dfs1(1, 0);
		if (!ans || !dp[1][0]) {
			printf("NO\n");
			continue;
		}
		dfs2(1, 0, 0);
		queue<int> q;
		for (int i = 2; i <= n; i++) {
			if (!deg[i]) {
				q.push(i);
			}
		}
		printf("YES\n");
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			printf("%d %d\n", u, fa[u]);
			for (auto v: edg[u]) {
				--deg[v];
				if (!deg[v]) q.push(v);
			}
		}
	}
}