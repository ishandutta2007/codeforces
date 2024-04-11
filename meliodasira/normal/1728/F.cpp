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

const int N = 1005;

unordered_map<int, int> match, tmp, pre, vis;
int a[N];
int n, len;
long long ans;

int dfs(int u) {
	vis[u] = 1;
	int minn = 1e9;
	for (int i = u;; i += u) {
		if (!match.count(i)) {
			pre[i] = u;
			minn = min(minn, i);
			break;
		}
		if (!vis.count(match[i])) {
			pre[i] = u;
			tmp[match[i]] = i;
			minn = min(minn, dfs(match[i]));
		}
	}
	return minn;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		len = 0;
		tmp.clear();
		pre.clear();
		vis.clear();
		int ret = dfs(a[i]);
		ans += ret;
		while (ret) {
			match[ret] = pre[ret];
			ret = tmp[pre[ret]];
		}
	}
	printf("%lld\n", ans);
}