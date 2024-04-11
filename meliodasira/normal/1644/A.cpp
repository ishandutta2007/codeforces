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

char c[50];
int vis[50];
int T;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		scanf("%s", c + 1);
		int n = strlen(c + 1);
		memset(vis, 0, sizeof(vis));
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			if (c[i] >= 'a' && c[i] <= 'z') {
				vis[c[i] - 'a'] = 1;
			} else if (!vis[c[i] - 'A']) {
				ans = 0;
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
}