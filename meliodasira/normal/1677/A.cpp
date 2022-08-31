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

const int N = 5005;

int a[N], s[N];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			memset(s, 0, sizeof(s));
			for (int j = i + 1; j <= n; j++) ++s[a[j]];
			for (int j = 1; j <= n; j++) s[j] += s[j - 1];
			int cnt = 0;
			for (int j = 1; j < i; j++) {
				ans += 1ll * cnt * s[a[j]];
				if (a[j] < a[i]) ++cnt;
			}
		}
		printf("%lld\n", ans);
	}
}