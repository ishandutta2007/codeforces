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

const int N = 1e5 + 5;

int a[N], b[N], vis[N], cnt[N], pre[N];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) a[i] = read(), vis[i] = cnt[i] = 0, pre[a[i]] = i;
		for (int i = 1; i <= n; i++) b[i] = read();
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			int tot = 0, tmp = i;
			while (!vis[tmp]) {
				vis[tmp] = 1;
				++tot;
				tmp = pre[b[tmp]];
			}
			++cnt[tot];
		}
		long long ans = 0;
		int now = n - 1;
		for (int i = 2; i <= n; i += 2) {
			while (cnt[i]) {
				for (int j = 1; j <= i / 2; j++) {
					ans += now;
					now -= 2;
				}
				--cnt[i];
			}
		}
		int x = n;
		if (n % 2 == 0) --x;
		for (int i = x; i >= 1; i -= 2) {
			while (cnt[i]) {
				for (int j = 1; j <= i / 2; j++) {
					ans += now;
					now -= 2;
				}
				--cnt[i];
			}
		}
		printf("%lld\n", ans * 2);
	}
}