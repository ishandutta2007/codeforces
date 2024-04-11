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
int fa[N];
int T, n, k;

int MID, cnt;
int dfs1(int u) {
	int maxn = 0;
	for (auto v: adj[u]) {
		int tmp = dfs1(v);
		maxn = max(maxn, tmp + 1);
	}
	if (maxn == MID - 1 && fa[u] != 1 && u != 1) maxn = -1, ++cnt;
	return maxn;
}

bool check(int mid) {
	MID = mid;
	cnt = 0;
	dfs1(1);
	return cnt <= k;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		k = read();
		rep(i, 1, n) adj[i].clear();
		rep(i, 2, n) {
			fa[i] = read();
			adj[fa[i]].push_back(i);
		}
		int l = 1, r = n, ans = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid))
				ans = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		printf("%d\n", ans);
	}
}