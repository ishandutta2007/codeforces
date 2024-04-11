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

int trie[N * 25][3];
int a[N][25];
int n, k, tot, ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	k = read();
	rep(i, 1, n) {
		int now = 0;
		rep(j, 1, k) {
			a[i][j] = read();
			if (!trie[now][a[i][j]]) trie[now][a[i][j]] = ++tot;
			now = trie[now][a[i][j]];
		}
	}
	rep(i, 1, n) {
		int cnt = 0;
		rep(j, 1, n) {
			if (i == j) continue;
			int now = 0;
			rep(t, 1, k) {
				int x;
				if (a[i][t] == a[j][t])
					x = a[i][t];
				else
					x = 3 - a[i][t] - a[j][t];
				now = trie[now][x];
				if (!now) break;
			}
			if (now) ++cnt;
		}
		cnt /= 2;
		ans += cnt * (cnt - 1) / 2;
	}
	printf("%d\n", ans);
}